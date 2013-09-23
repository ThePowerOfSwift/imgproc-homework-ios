//
//  ImageProcessing.h
//  DrawLines
//
//  Created by Simon Kim on 12. 11. 2..
//
//

#import <Foundation/Foundation.h>

@interface ImageProcessing : NSObject

+ (UIImage *) regionDetectedImageWithUIImage:(UIImage *) image x:(int) x y:(int) y;
+ (UIImage *) extractEdgeWithUIImage:(UIImage *) image;
+ (UIImage *) gaussianBlur:(UIImage *) image;
+ (UIImage *) histogramEqualization:(UIImage *) image;
+ (UIImage *) grayscale:(UIImage *) image;
+ (NSUInteger) measureContrast:(UIImage *) image;
+ (void) measureImage:(UIImage *) image histogram:(int *) histogram;
@end
