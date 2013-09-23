//
//  DZUIAnimationUtility.h
//  PhotoSFX
//
//  Created by Simon Kim on 12. 3. 23..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface DZUIAnimationUtility : NSObject


+ (void) moveView:(UIView *) view toCenter:(CGPoint) center;
+ (void) moveView:(UIView *) view toCenter:(CGPoint) center animated:(BOOL) animated duration:(NSTimeInterval) duration;

+ (void) setView:(UIView *) view hidden:(BOOL)hidden animated:(BOOL) animated;
+ (void) setView:(UIView *) view hidden:(BOOL)hidden animated:(BOOL) animated duration:(NSTimeInterval) duration;

+ (void) setView:(UIView *) view alpha:(CGFloat)alpha;
+ (void) setView:(UIView *) view alpha:(CGFloat)alpha animated:(BOOL) animated duration:(NSTimeInterval) duration;

@end
