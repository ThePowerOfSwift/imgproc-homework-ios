/*
 *  Image.h
 *  ImageProcessing
 *
 *  Created by Chris Greening on 02/01/2009.
 *  http://code.google.com/p/simple-iphone-image-processing/
 *
 *  Modified by Simon Kim for narrower purpose
 *  Sep. 23rd, 2013
 */

#import <UIKit/UIImage.h>

#include <vector>
#include <algorithm>

class Image;
@interface ImageWrapper : NSObject {
	Image *image;
	bool ownsImage;
}

@property(assign, nonatomic) Image *image;
@property(assign, nonatomic) bool ownsImage;

- (UIImage *) UIImage;

+ (ImageWrapper *) imageWithCPPImage:(Image *) theImage;
+ (ImageWrapper *) imageWithUIImage:(UIImage *) theImage;
+ (ImageWrapper *) imageWithUIImage:(UIImage *) theImage resize:(CGSize) size;
@end

class Image {
private:
	uint8_t *m_imageData;
	uint8_t **m_yptrs;
	int m_width;
	int m_height;
	bool m_ownsData;
	Image(ImageWrapper *other, int x1, int y1, int x2, int y2);
	Image(int width, int height);
	Image(uint8_t *imageData, int width, int height, bool ownsData=false);
	Image(UIImage *srcImage, int width, int height, CGInterpolationQuality interpolation, bool imageIsRotatedBy90degrees=false);
	void initYptrs();
public:
	// copy a section of another image
	static ImageWrapper *createImage(ImageWrapper *other, int x1, int y1, int x2, int y2);
	// create an empty image of the required width and height
	static ImageWrapper *createImage(int width, int height);
	// create an image from data
	static ImageWrapper *createImage(uint8_t *imageData, int width, int height, bool ownsData=false);
	// take a source UIImage and convert it to greyscale
	static ImageWrapper *createImage(UIImage *srcImage, int width, int height, bool imageIsRotatedBy90degrees=false);
  
	// histogram equalisation
	void HistogramEqualisation();

	// convert back to a UIImage for display
	UIImage *toUIImage();
	~Image() {
		if(m_ownsData)
			free(m_imageData);
		delete m_yptrs;
	}
	inline uint8_t* operator[](const int rowIndex) {
		return m_yptrs[rowIndex];
	}
	inline int getWidth() {
		return m_width;
	}
	inline int getHeight() {
		return m_height;
	}
    unsigned int measureContrast(int x, int y, int width, int height);
    // histogram[256]
    void measureHistogram(int *histogram);
    inline void setPixel(uint8_t pixel, int x, int y) {
        m_imageData[y * m_width + x] = pixel;
    }
    inline uint8_t getPixel(int x, int y) {
        return m_imageData[y * m_width + x];
    }
};
