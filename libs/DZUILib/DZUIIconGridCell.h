//
//  DZUIIconGridCell.h
//  PhotoClockCal
//
//  Created by Simon Kim on 10. 1. 5..
//  Copyright 2010 DZPub.com. All rights reserved.
//

#if 1
#import <UIKit/UIKit.h>


@interface DZUIIconGridCell : UITableViewCell {
	NSMutableArray *_arrayImageViews;
	CGFloat iconWidth;
	CGFloat iconHeight;
	CGFloat iconHorzGap;
	CGFloat iconTopMargin;
	
	UIImage *_imageCheckIcon;
	UIImage *_imageUncheckIcon;
	
	NSUInteger _touchedImageIndex;		// set in touchesBegan, cleared in touchesEnded
	UIView *_viewSelectedImageBackground;
    
    // 7th Apr. Check status option
    BOOL checkStatusEnabled;
    UIViewContentMode contentMode;
}
@property (nonatomic, assign) BOOL checkStatusEnabled;
@property (nonatomic, assign) UIViewContentMode contentMode;

- (void) setImages:(NSArray *) arrayImages;
- (UIImageView *) imageViewAtPoint:(CGPoint) point;
- (NSUInteger) imageIndexAtPoint:(CGPoint) point;
- (void) clearDisplayedImages;
- (void) setIconWidth:(CGFloat) width height:(CGFloat) height horzGap:(CGFloat) horzGap vertGap:(CGFloat) vertGap;
- (void) setImageSelected:(BOOL) selected atIndex:(NSUInteger) index;
- (NSUInteger) imageCount;
- (void) setImageHighlighted:(BOOL) highlighted atIndex: (NSUInteger) index;

@end

#endif