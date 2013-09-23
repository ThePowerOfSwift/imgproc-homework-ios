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


+ (UIImage *) regionDetectedImageWithUIImage:(UIImage *) image x:(int) x y:(int) y
{
    /*
    ImageWrapper *region = [ImageWrapper regionDetectedImageWithUIImage:image x:x y:y];
    ImageWrapper *edge = region.image->cannyEdgeExtract(0.3, 0.7);
    
    return edge.image->toUIImage();
     */
    return [ImageWrapper regionDetectedImageWithUIImage:image x:x y:y].image->toUIImage();
}

+ (UIImage *) extractEdgeWithUIImage:(UIImage *) image
{
    ImageWrapper *wrapper = [ImageWrapper imageWithUIImage:image];
    return wrapper.image->gaussianBlur().image->cannyEdgeExtract(0.2, 0.6).image->toUIImage();
}

+ (UIImage *) gaussianBlur:(UIImage *)image
{
    ImageWrapper *wrapper = [ImageWrapper imageWithUIImage:image];
    
    for( int i = 0; i < 3; i++) {
        wrapper = wrapper.image->gaussianBlur();
    }
    return [wrapper UIImage];
    
}

+ (UIImage *) histogramEqualization:(UIImage *) image
{
    ImageWrapper *wrapper = [ImageWrapper imageWithUIImage:image];
    Image *img = (Image *) wrapper.image;
    
    img->HistogramEqualisation();
    return [wrapper UIImage];
    
}

+ (UIImage *) grayscale:(UIImage *) image
{
    ImageWrapper *wrapper = [ImageWrapper imageWithUIImage:image];
    return [wrapper UIImage];
}

+ (NSUInteger) measureContrast:(UIImage *) image
{
    unsigned int measure;
    ImageWrapper *wrapper = [ImageWrapper imageWithUIImage:image];
    int width = wrapper.image->getWidth();
    int height = wrapper.image->getHeight();
    
    measure = wrapper.image->measureContrast(0, 0, width, height);
    return measure;
}

+ (void) measureImage:(UIImage *) image histogram:(int *) histogram
{
    ImageWrapper *wrapper = [ImageWrapper imageWithUIImage:image];
    wrapper.image->measureHistogram(histogram);
}


@end
