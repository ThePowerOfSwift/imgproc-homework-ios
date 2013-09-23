//
//  PointRotator.h
//  FlickBall
//
//  Created by Simon Kim on 09. 05. 22.
//  Copyright 2009 DZPub.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
/*
 Example usage: rotating point 'pt' in 90 degrees with base point 'ptbase'
	PointRotator *rotator;
 
	rotator = [[PointRotator alloc] init];
	[rotator setBasePoint: ptbase];
	[rotator setAngle: M_PI_2];
	ptRotated = [rotator rotatePoint: pt];
 
	// now 'ptRotated' has the rotated point.
 
 */
@interface PointRotator : NSObject {
	CGAffineTransform trTranslationIn;
	CGAffineTransform trRotation;
	CGAffineTransform trTranslationOut;
}
-(void) setBasePoint:(CGPoint) pt;
-(void) setAngle:(CGFloat) angle;
-(CGPoint) rotatePoint:(CGPoint) pt;

+ (CGFloat) radianFromSecond:(CGFloat) second;
+ (CGFloat) angleFor12SlotsRoundIndex:(NSUInteger) index outOf:(NSUInteger) count;
+ (CGPoint) rotatePoint:(CGPoint) src withBasePoint:(CGPoint) basePoint ofAngle:(CGFloat) radian;
+ (PointRotator *) sharedRotator;

@end
