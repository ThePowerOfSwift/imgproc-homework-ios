//
//  ImageProcessing.m
//  DrawLines
//
//  Created by Simon Kim on 12. 11. 2..
//
//

#import "ImageProcessing.h"
#import "Image.h"
@implementation ImageProcessing


+ (UIImage *) grayscale:(UIImage *) image
{
    ImageWrapper *wrapper = [ImageWrapper imageWithUIImage:image];
    return [wrapper UIImage];
}

/* Histogram */
+ (void) measureImage:(UIImage *) image histogram:(int *) histogram
{
    ImageWrapper *wrapper = [ImageWrapper imageWithUIImage:image];
    wrapper.image->measureHistogram(histogram);
}


/* Auto Contrast */
+ (UIImage *) histogramEqualization:(UIImage *) image
{
    ImageWrapper *wrapper = [ImageWrapper imageWithUIImage:image];
    Image *img = (Image *) wrapper.image;
    
    img->HistogramEqualisation();
    return [wrapper UIImage];
    
}

/* Auto Focus */
+ (NSUInteger) measureContrast:(UIImage *) image
{
    unsigned int measure;
    ImageWrapper *wrapper = [ImageWrapper imageWithUIImage:image];
    int width = wrapper.image->getWidth();
    int height = wrapper.image->getHeight();
    
    measure = wrapper.image->measureContrast(0, 0, width, height);
    return measure;
}

+ (UIImage *) transformImage:(UIImage *) image srcPoints:(CGPoint[4]) srcPoints tgtPoints:(CGPoint[4]) tgtPoints
{
    
    ImageWrapper *src = [ImageWrapper imageWithUIImage:image];
    CGFloat srcWidth = src.image->getWidth();
    
    CGSize size = CGSizeMake(tgtPoints[3].x - tgtPoints[0].x, tgtPoints[3].y - tgtPoints[0].y);
    ImageWrapper *dst = Image::createImage(size.width, size.height);
    
    CGFloat xb1 = srcPoints[0].x;
    CGFloat xb2 = srcPoints[1].x - xb1;
    CGFloat xb3 = srcPoints[2].x - xb1;
    CGFloat xb4 = xb1 - srcPoints[1].x - srcPoints[2].x + srcPoints[3].x;

    CGFloat yb1 = srcPoints[0].y;
    CGFloat yb2 = srcPoints[1].y - yb1;
    CGFloat yb3 = srcPoints[2].y - yb1;
    CGFloat yb4 = yb1 - srcPoints[1].y - srcPoints[2].y + srcPoints[3].y;

    NSLog(@"Target image size:%@", NSStringFromCGSize(size));
    
    for( int y = tgtPoints[0].y; y < tgtPoints[3].y; y++) {
        for( int x = tgtPoints[0].x; x < tgtPoints[3].x; x++) {
            CGPoint point;
            
            // Nonlinear
            point.x = xb1 + xb2*(x/size.width) + xb3*(y/size.height) + xb4*(x/size.width)*(y/size.height);
            point.y = yb1 + yb2*(x/size.width) + yb3*(y/size.height) + yb4*(x/size.width)*(y/size.height);
            
            int offset = point.y * srcWidth;
            offset += point.x;

            dst.image->setPixel(src.image->getPixel(point.x, point.y), x, y);
        }
    }

    return [dst UIImage];
}

@end
