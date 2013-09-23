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


@end
