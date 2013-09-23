//
//  DZUIImageViewController.h
//  PhotoClipper
//
//  Created by Simon Kim on 12. 1. 22..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#import "DZUIDoubleZoomScrollView.h"

@class DZUIImageViewController;

@protocol DZUIImageViewControllerDelegate <NSObject>

- (void) imageViewControllerDone:(DZUIImageViewController *) imageViewController;
@optional
- (void) imageViewControllerDone:(DZUIImageViewController *) imageViewController withBarButtonItem:(UIBarButtonSystemItem) barButtonSystemItem;

@end

@interface DZUIImageViewController : UIViewController
@property (strong, nonatomic) DZUIDoubleZoomScrollView *scrollView;
@property (nonatomic, strong) UIImage *image;
@property (nonatomic, assign) id<DZUIImageViewControllerDelegate> delegate;
@property (nonatomic) UIBarButtonSystemItem leftBarButtonSystemItem;
@property (nonatomic) UIBarButtonSystemItem rightBarButtonSystemItem;
@property (nonatomic) BOOL customLeftBarButtonSystemItem;
@property (nonatomic) BOOL customRightBarButtonSystemItem;
@property (nonatomic, strong) void (^doneBlock)(DZUIImageViewController *viewController, UIBarButtonSystemItem barBUttonSystemItem);
+ (DZUIImageViewController *) imageViewControllerWithNibName:(NSString *)nibName;
+ (DZUIImageViewController *) imageViewController;

@end
