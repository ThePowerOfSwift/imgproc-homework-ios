//
//  DZUISeamlessModalViewController.h
//  DZUILib
//
//  Created by Simon Kim on 12. 3. 7..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#import <UIKit/UIKit.h>
@class DZUISeamlessModalViewController;

@protocol DZUISeamlessModalViewControllerDelegate <NSObject>
- (void) seamlessModalViewControllerDone:(DZUISeamlessModalViewController *) viewController;
@end

@interface DZUISeamlessModalViewController : UIViewController

@property (nonatomic, strong, readonly) UIView *artBoardView;
@property (nonatomic, strong, readonly) UIView *targetObjectView;
@property (nonatomic, assign) id<DZUISeamlessModalViewControllerDelegate> delegate;

- (id)initWithArtBoardView:(UIView *) artBoardView targetObjectView:(UIView *)targetObjectView;
- (id)initWithArtBoardView:(UIView *) artBoardView targetObjectView:(UIView *)targetObjectView targetNeedsVisualCopy:(BOOL) targetNeedsVisualCopy;

@end
