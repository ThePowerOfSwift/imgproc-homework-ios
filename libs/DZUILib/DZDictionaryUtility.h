//
//  DZDictionaryUtility.h
//  DZUILib
//
//  Created by Simon Kim on 12. 3. 14..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface DZDictionaryUtility : NSObject
+ (id) dictionaryValueForBool:(BOOL )value;
+ (id) dictionaryValueForFloat:(CGFloat )value;
+ (id) dictionaryValueForUIColor:(UIColor *) color;
+ (id) dictionaryValueForCGPoint:(CGPoint ) point;
+ (id) dictionaryValueForCGLineCap:(CGLineCap) lineCap;
+ (id) dictionaryValueForCGLineJoin:(CGLineJoin) lineJoin;
+ (id) dictionaryValueForPathElementType:(CGPathElementType) elementType;
+ (id) dictionaryValueForCGSize:(CGSize) size;

+ (BOOL) boolFromDictionaryValue:(id) value;
+ (CGFloat) floatFromDictionaryValue:(id) value;
+ (UIColor *) colorFromDictionaryValue:(id) value;
+ (CGPoint) pointFromDictionaryValue:(id) value;
+ (CGLineCap) lineCapFromDictionaryValue:(id) value;
+ (CGLineJoin) lineJoinFromDictionaryValue:(id) value;
+ (CGPathElementType) pathElementTypeFromDictionaryValue:(id) value;
+ (CGSize) sizeFromDictionaryValue:(id) value;
@end
