//
//  DZUILayer.h
//  PhotoClipper
//
//  Created by Simon Kim on 12. 1. 20..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DZUILayer : NSObject
@property (nonatomic, readonly) CGSize size;
@property (nonatomic, readonly) CGContextRef layerContext;
@property (nonatomic, readonly) CGLayerRef layer;

- (id) initWithContext:(CGContextRef) context size:(CGSize) size;

@end
