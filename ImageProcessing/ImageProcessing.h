//
//  ImageProcessing.h
//  DrawLines
//
//  Created by Simon Kim on 12. 11. 2..
//
//

#import <Foundation/Foundation.h>

@interface ImageProcessing : NSObject

+ (UIImage *) grayscale:(UIImage *) image;
+ (UIImage *) histogramEqualization:(UIImage *) image;
+ (NSUInteger) measureContrast:(UIImage *) image;
+ (void) measureImage:(UIImage *) image histogram:(int *) histogram;
+ (UIImage *) transformImage:(UIImage *) image srcPoints:(CGPoint[4]) srcPoints tgtPoints:(CGPoint[4]) tgtPoints;
@end
