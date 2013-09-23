//
//  ImageManipulator.h
//
//  Class for manipulating images.
//
//  Created by Björn Sållarp on 2008-09-11.
//  Copyright 2008 Björn Sållarp. All rights reserved.
//
//  Read my blog @ http://blog.sallarp.com
//
// Updated on 2009-04-05

#import <UIKit/UIKit.h>

void imgman_HSL2RGB(float h, float s, float l, float* outR, float* outG, float* outB);
void imgman_addRoundedRectToPath(CGContextRef context, CGRect rect, float ovalWidth, float ovalHeight);
CGContextRef imgman_createBitmapContext (int pixelsWide, int pixelsHigh);
void imgman_releaseBitmapContext(CGContextRef context);
void DrawGlossGradient(CGContextRef context, UIColor *color, CGRect inRect);
void DrawSimpleGlossCover(CGContextRef context, CGRect inRect);
void imgman_DrawGlossyEffect(CGContextRef context, CGRect inRect, BOOL vertical);


@interface ImageManipulator : NSObject {

}
+ (CGSize) aspectFitSizeOf:(CGSize) srcSize withinSize:(CGSize) targetSize;
// UIView -> UIImageView
+ (UIView *) visualCopyOfView:(UIView *) view withDimLevel:(CGFloat) dim;

// UIView -> Image
+(UIImage *) captureImageOfView:(UIView *)srcView;
+(UIImage *) snapshotImageOfView:(UIView *) view withSize:(CGSize) newSize contentMode:(UIViewContentMode) contentMode;

// Image -> Image
+(UIImage *) makeRoundCornerImage:(UIImage*)img :(int) cornerWidth :(int) cornerHeight;
+(UIImage *) makeRoundCornerImage:(UIImage*) img newSize:(CGSize) newSize : (int) cornerWidth : (int) cornerHeight;
+(UIImage *) imageWithImage:(UIImage *)image scaledToSize:(CGSize)newSize;
+(UIImage *) imageWithImage:(UIImage *)image scaledToSize:(CGSize)newSize withTransparentBorderExpandedBy:(NSUInteger) expand;
+(UIImage *) thumbnailImageForImage:(UIImage *) image withSize:(CGSize) size;
+(UIImage *) composeImages:(NSArray *) images withSize:(CGSize) size;
+(UIImage *) resizedImage:(UIImage *) image withNewSize:(CGSize) newSize;
+(UIImage *) composeImage:(UIImage *) srcImage onImage:(UIImage *) backgroundImage atPoint:(CGPoint) point;


// Nothing(+ parameters) -> Image
// --------------------------------------------------
+(UIImage *) simpleArrowImage;
+(UIImage *) dummyImageWithSize:(CGSize) size circle:(BOOL) circle;
+ (UIImage *) imageWithColor:(UIColor *) color size:(CGSize) size;

+(UIImage *) transparentColorSymbolImage:(CGSize) size circle:(BOOL) circle;

+(UIImage *) createImageGlossyColorRect:(UIColor *) color withSize:(CGSize)size;
+(UIImage *) createImageGlossyColorRect:(UIColor *) color withSize:(CGSize)size 
                            cornerWidth:(int)cornerWidth 
                           cornerHeight:(int)cornerHeight;
+(void) drawSimpleGlossyColor:(UIColor *) color 
                         rect:(CGRect) rect 
                    inContext:(CGContextRef) context 
                  cornerWidth:(int)cornerWidth 
                 cornerHeight:(int)cornerHeight;
+(void) drawSimpleGlossyColor:(UIColor *) color rect:(CGRect) rect inContext:(CGContextRef) context cornerWidth:(int)cornerWidth cornerHeight:(int)cornerHeight colorTransitionOffset:(CGFloat) colorTransitionOffset;
+(UIImage *) createImageSimpleGlossyColorRect:(UIColor *) color withSize:(CGSize)size cornerWidth:(int)cornerWidth cornerHeight:(int)cornerHeight;
+(UIImage *) createImageGlossyFolderWithColor:(UIColor *) color withSize:(CGSize)size cornerWidth:(int)cornerWidth cornerHeight:(int)cornerHeight;

@end
