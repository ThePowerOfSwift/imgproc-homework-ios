//
//  DZUIIconGridViewController.h
//  PhotoClockCal
//
//  Created by Simon Kim on 10. 1. 5..
//  Copyright 2010 DZPub.com. All rights reserved.
//
#if 1
#import <UIKit/UIKit.h>
#import "DZUIIconGridCell.h"


@class DZUIIconGridViewController;

@protocol DZUIIconGridViewControllerDelegate

- (NSUInteger) numberOfImagesInGridViewController:(DZUIIconGridViewController *) gridViewController;
- (UIImage *) gridViewController:(DZUIIconGridViewController *) gridViewController imageAtIndex:(NSUInteger) index;
- (UIImage *) gridViewController:(DZUIIconGridViewController *) gridViewController imageRemovedAtIndex:(NSUInteger) index;
- (void) gridViewController:(DZUIIconGridViewController *) gridViewController insertImage:(UIImage *)image atIndex:(NSUInteger) index;
- (void) gridViewController:(DZUIIconGridViewController *) gridViewController addImage:(UIImage *)image;
- (void) gridViewController:(DZUIIconGridViewController *) gridViewController replaceImageAtIndex:(NSUInteger) index withImage:(UIImage *)image;
- (BOOL) gridViewController:(DZUIIconGridViewController *) gridViewController isImageSelectedAtIndex:(NSUInteger) index;
- (void) gridViewController:(DZUIIconGridViewController *) gridViewController setImageSelected:(BOOL) selected atIndex:(NSUInteger) index;

@end

@protocol DZUIIconGridViewControllerEventDelegate
- (void) gridViewController:(DZUIIconGridViewController *) gridViewController didTapImageAtIndex:(NSUInteger) index;
@end

@interface DZUIIconGridViewController : UIViewController <UITableViewDelegate, UITableViewDataSource, UIGestureRecognizerDelegate> {
	UITableView *tableView;
	NSMutableArray *_arrayImages;
	NSUInteger _numImages;
	
	NSUInteger _columnNum;
	UITableViewStyle _tableViewStyle;
	
	UIImageView *imageViewPickedUp;
	CGSize _touchDistanceFromCenter;
	DZUIIconGridCell *cellImageViewOrigin;	
	CGPoint _centerImageViewOriginal;
	NSUInteger imageIndexPickedUp;
	NSUInteger imageIndexEmpty;
	UIImage *emptyImage;
	
	// Mar. 9 2011
	// Icon size, offset
	CGRect rectFirstIcon;
		
	BOOL allowReorder;			// Long press gesture is ignored if allowReorder == NO
	BOOL allowSelection;
    
    // Apr. 18th
    UIViewContentMode imageContentMode;
	
	id<DZUIIconGridViewControllerDelegate> __unsafe_unretained private_delegate;
	id<DZUIIconGridViewControllerEventDelegate> __unsafe_unretained eventDelegate;
    
	
}
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) UIImageView *imageViewPickedUp;
@property (nonatomic, strong) UIImage *emptyImage;
@property (nonatomic, assign) BOOL allowReorder;
@property (nonatomic, unsafe_unretained) id<DZUIIconGridViewControllerDelegate> private_delegate;
@property (nonatomic, unsafe_unretained) id<DZUIIconGridViewControllerEventDelegate> eventDelegate;
@property (nonatomic, assign) NSUInteger columnNum;
@property (nonatomic, assign) UIViewContentMode imageContentMode;

+ (id<DZUIIconGridViewControllerDelegate>) defaultDataSource;
- (id) initWithStyle:(UITableViewStyle)style;
- (void) addImage:(UIImage *) image;
- (void) insertImage:(UIImage *) image atIndex:(NSUInteger) index;
- (void) removeImageAtIndex:(NSUInteger) index;
- (BOOL) isImageSelectedAtIndex:(NSUInteger) index;
- (void) setImageSelected:(BOOL) selected atIndex:(NSUInteger) index;
- (void) setFirstIconFrame: (CGRect) firstIconFrame;
- (UIImage *) imageAtInex:(NSUInteger) index;
@end
#endif