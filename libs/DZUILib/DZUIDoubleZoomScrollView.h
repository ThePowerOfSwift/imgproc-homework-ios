//
//  DZUIDoubleZoomScrollView.h
//  PhotoClipper
//
//  Created by Simon Kim on 12. 1. 18..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DZUIDoubleZoomScrollView : UIScrollView
@property (nonatomic, strong) UIView *imageView;
@property (nonatomic, strong, readonly) UIView *containerView;

@end
