//
//  DZSFXLaserStrokeAttributes.h
//  PhotoSFX
//
//  Created by Simon Kim on 12. 3. 21..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface DZUIViewEffectAttributes : NSObject <NSCopying>
@property (nonatomic, strong) UIColor *shadowColor;
@property (nonatomic) CGFloat radius;
@property (nonatomic) CGFloat opacity;
@property (nonatomic) CGFloat outlineWidth;    // outline
@property (nonatomic) CGFloat strokeWidth;  // stroke
@property (nonatomic) BOOL useOutlineWidthForStroke;
@property (nonatomic) CGFloat pathLineWidth;        // selected between outlineWidth and strokeWith depending on the value of useOutlineWidthForStrke

- (void) applyToView:(UIView *) view;
- (id)initWithDictionaryRepresentation:(NSDictionary *) dictionary;
- (NSDictionary *) dictionaryRepresentation;
- (void) setDictionaryRepresentation:(NSDictionary *) dictionary;


+ (void) applyAttributes:(DZUIViewEffectAttributes *) attributes toView:(UIView *) view;

+ (void) giveShadowEffectToView:(UIView *)view;

+ (void) giveShadowEffectToView:(UIView *) view color:(UIColor *) color shadowRadius:(CGFloat) radius shadowOpacity:(CGFloat) opacity offset:(CGSize) shadowOffset;

// radius: positive points
// opacity: 0 ~ 1.0
+ (void) giveGlowEffectToView:(UIView *) view color:(UIColor *) color shadowRadius:(CGFloat) radius shadowOpacity:(CGFloat) opacity;
+ (void) disableGlowEffectFromView:(UIView *) view;

+ (DZUIViewEffectAttributes *) attributesWithColor:(UIColor *) color;
+ (DZUIViewEffectAttributes *) attributesWithDictionary:(NSDictionary *) dictionary;
+ (CGFloat) getAlphaFromColor:(UIColor *) color;

@end
