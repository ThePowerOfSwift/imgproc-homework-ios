/*
 *  Image.cpp
 *  ImageProcessing
 *
 *  Created by Chris Greening on 04/01/2009.
 *  http://code.google.com/p/simple-iphone-image-processing/
 *
 *  Modified by Simon Kim for narrower purpose
 *  Sep. 23rd, 2013
 */
#include "Image.h"
#include <stack>

@implementation ImageWrapper

@synthesize image;
@synthesize ownsImage;

+ (ImageWrapper *) imageWithCPPImage:(Image *) theImage;
{
	ImageWrapper *wrapper = [[ImageWrapper alloc] init];
	wrapper.image=theImage;
	wrapper.ownsImage=true;
	return wrapper;
}

+ (ImageWrapper *) imageWithCPPImage:(Image *) theImage ownsImage:(bool) ownsTheImage;
{
	ImageWrapper *wrapper = [[ImageWrapper alloc] init];
	wrapper.image=theImage;
	wrapper.ownsImage=ownsTheImage;
	return wrapper;
}

+ (ImageWrapper *) imageWithUIImage:(UIImage *) theImage
{
	return Image::createImage(theImage, theImage.size.width, theImage.size.height);
}

+ (ImageWrapper *) imageWithUIImage:(UIImage *) theImage resize:(CGSize) size
{
	return Image::createImage(theImage, size.width, size.height);
}

- (UIImage *) UIImage
{
    return self.image->toUIImage();
}


- (void) dealloc
{
	// delete the image that we have been holding onto
	if(ownsImage) delete image;
}


@end

void Image::initYptrs() {
	m_yptrs=(uint8_t **) malloc(sizeof(uint8_t *)*m_height);
	for(int i=0; i<m_height; i++) {
		m_yptrs[i]=m_imageData+i*m_width;
	}
}


Image::Image(ImageWrapper *other, int x1, int y1, int x2, int y2) {
	m_width=x2-x1;
	m_height=y2-y1;
	m_imageData=(uint8_t *) malloc(m_width*m_height);
	initYptrs();
	Image *otherImage=other.image;
	for(int y=y1; y<y2; y++) {
		for(int x=x1; x<x2; x++) {
			(*this)[y-y1][x-x1]=(*otherImage)[y][x];
		}
	}
	m_ownsData=true;
}

Image::Image(int width, int height) {
	m_imageData=(uint8_t *) malloc(width*height);
	m_width=width;
	m_height=height;
	m_ownsData=true;
	initYptrs();
}
// create an image from data
Image::Image(uint8_t *imageData, int width, int height, bool ownsData) {
	m_imageData=imageData;
	m_width=width;
	m_height=height;
	m_ownsData=ownsData;
	initYptrs();
}

Image::Image(UIImage *srcImage, int width, int height,  CGInterpolationQuality interpolation, bool imageIsRotatedBy90degrees) {
	if(imageIsRotatedBy90degrees) {
		int tmp=width;
		width=height;
		height=tmp;
	}
	m_width=width;
	m_height=height;
	// get hold of the image bytes
	m_imageData=(uint8_t *) malloc(m_width*m_height);
	CGColorSpaceRef colorSpace=CGColorSpaceCreateDeviceGray();
	CGContextRef context=CGBitmapContextCreate(m_imageData,  m_width, m_height, 8, m_width, colorSpace, kCGImageAlphaNone);
	CGContextSetInterpolationQuality(context, interpolation);
	CGContextSetShouldAntialias(context, NO);
	CGContextDrawImage(context, CGRectMake(0,0, m_width, m_height), [srcImage CGImage]);
	CGContextRelease(context);
	CGColorSpaceRelease(colorSpace);
	
	if(imageIsRotatedBy90degrees) {
		uint8_t *tmpImage=(uint8_t *) malloc(m_width*m_height);
		for(int y=0; y<m_height; y++) {
			for(int x=0; x<m_width; x++) {
				tmpImage[x*m_height+y]=m_imageData[(m_height-y-1)*m_width+x];
			}
		}
		int tmp=m_width;
		m_width=m_height;
		m_height=tmp;
		free(m_imageData);
		m_imageData=tmpImage;
	}
	initYptrs();
}



// copy a section of another image
ImageWrapper *Image::createImage(ImageWrapper *other, int x1, int y1, int x2, int y2)
{
	return [ImageWrapper imageWithCPPImage:new Image(other, x1, y1, x2, y2)];
}
// create an empty image of the required width and height
ImageWrapper *Image::createImage(int width, int height) {
	return [ImageWrapper imageWithCPPImage:new Image(width, height)];
}
// create an image from data
ImageWrapper *Image::createImage(uint8_t *imageData, int width, int height, bool ownsData) {
	return [ImageWrapper imageWithCPPImage:new Image(imageData, width, height, ownsData)];
}
// take a source UIImage and convert it to greyscale
ImageWrapper *Image::createImage(UIImage *srcImage, int width, int height, bool imageIsRotatedBy90degrees) {
	return [ImageWrapper imageWithCPPImage:new Image(srcImage, width, height, kCGInterpolationHigh, imageIsRotatedBy90degrees)];
}

UIImage *Image::toUIImage() {
	// generate space for the result
	uint8_t *result=(uint8_t *) calloc(m_width*m_height*sizeof(uint32_t),1);
	// process the image back to rgb
	for(int i=0; i<m_height*m_width; i++) {			
		result[i*4]=0;
		int val=m_imageData[i];
		result[i*4+1]=val;
		result[i*4+2]=val;
		result[i*4+3]=val;
	}
	// create a UIImage
	CGColorSpaceRef colorSpace=CGColorSpaceCreateDeviceRGB();
	CGContextRef context=CGBitmapContextCreate(result, m_width, m_height, 8, m_width*sizeof(uint32_t), colorSpace, kCGBitmapByteOrder32Little|kCGImageAlphaNoneSkipLast);
	CGImageRef image=CGBitmapContextCreateImage(context);
	CGContextRelease(context);
	CGColorSpaceRelease(colorSpace);
	UIImage *resultUIImage=[UIImage imageWithCGImage:image];
	CGImageRelease(image);
	// make sure the data will be released by giving it to an autoreleased NSData
	[NSData dataWithBytesNoCopy:result length:m_width*m_height];
	return resultUIImage;
}

/* Auto Focus */
unsigned int Image::measureContrast(int x, int y, int width, int height)
{
    unsigned int measure = 0;
    int pixel;
    if ( x + width > getWidth() ) {
        width = getWidth() - x;
    }
    if ( y + height > getHeight()) {
        height = getHeight() - y;
    }
    
    int i = (x + y * this->getWidth());
    int lastPixel = m_imageData[i];
    int offsetLast = (x + width + (y + height - 1) * this->getWidth());
    
    while(true) {
        i += this->getWidth() + 1;
        if ( i >= offsetLast ) {
            break;
        }
        pixel = m_imageData[i];
        measure += abs( pixel - lastPixel);
        lastPixel = pixel;
    }
    
    return measure;
}

/* Auto Contrast */
void Image::HistogramEqualisation() {
	std::vector<int> pdf(256);
	std::vector<int> cdf(256);
	// compute the pdf
	for(int i=0; i<m_height*m_width; i++) {
		pdf[m_imageData[i]]++;
	}
	// compute the cdf
	cdf[0]=pdf[0];
	for(int i=1; i<256; i++) {
		cdf[i]=cdf[i-1]+pdf[i];
	}
	// now map the pixels to the new values
	for(int i=0; i<m_height*m_width; i++) {
		m_imageData[i] = 255 * cdf[m_imageData[i]] / cdf[255];
	}
}

/* Histogram */
void Image::measureHistogram(int *histogram)
{
    for( int i = 0; i < 256; i++) {
        histogram[i] = 0;
    }
    
	for(int i=0; i<m_height*m_width; i++) {
		histogram[m_imageData[i]]++;
	}
}