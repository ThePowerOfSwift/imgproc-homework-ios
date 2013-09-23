//
//  DZUIViewSelector.h
//  testsample
//
//  Created by Simon Kim on 11. 11. 15..
//  Copyright (c) 2011년 DZPub.com. All rights reserved.
//
// Requires selectorBlueBall.png present in the bundle
//
#import <UIKit/UIKit.h>


typedef enum {
	SELECTOR_MARK_NONE		= -1,
	SELECTOR_MARK_TOPLEFT	= 0,
	SELECTOR_MARK_TOPCENTER,
	SELECTOR_MARK_TOPRIGHT,
	SELECTOR_MARK_MIDLEFT,
	SELECTOR_MARK_MIDRIGHT,
	SELECTOR_MARK_BOTTOMLEFT,
	SELECTOR_MARK_BOTTOMCENTER,
	SELECTOR_MARK_BOTTOMRIGHT
} SelectorMarkType;
#define SELECT_MARK_TYPE_NUM	(SELECTOR_MARK_BOTTOMRIGHT +1)

typedef enum {
    DZUIViewSelectorMarkStyleNone           = -1,
    DZUIViewSelectorMarkStyleDefault        = 0,    // MIDRIGHT, BOTTOMCENTER, BOTTOMRIGHT
    DZUIViewSelectorMarkStyleBottomRight    = 1,
    DZUIViewSelectorMarkStyleAll            = 2
} DZUIViewSelectorMarkStyle;

typedef enum {
  DZUIViewSelectorGestureStateBegan,
  DZUIViewSelectorGestureStateChanging,
  DZUIViewSelectorGestureStateFinished
} DZUIViewSelectorGestureState;

@class DZUIViewSelector;

@protocol DZUIViewSelectorDelegate <NSObject>
- (void) viewSelectorDidTap:(DZUIViewSelector *)viewSelector ;
// informs delegate that it's safe to call addTableViewSection: and addTableViewSections:
// Move's coordinate is of self.targetView.superview
// Size's coordinate is of self.targetView
- (void) viewSelector:(DZUIViewSelector *)viewSelector changedCenter:(CGPoint) dcenter Size:(CGSize) dsize atMark:(SelectorMarkType) markType;
@optional
- (void) viewSelector:(DZUIViewSelector *)viewSelector didRotate:(CGFloat) rotation changedTransform:(CGAffineTransform) transform;
@optional
- (void) viewSelector:(DZUIViewSelector *)viewSelector didScale:(CGFloat) scale;
- (void) viewSelector:(DZUIViewSelector *)viewSelector didScale:(CGFloat) scale ended:(BOOL) ended;
@end



@interface DZUIViewSelector : UIView 
@property (unsafe_unretained, nonatomic) UIView *targetView;
@property (unsafe_unretained, nonatomic) id<DZUIViewSelectorDelegate> delegate;
@property (nonatomic, retain) UIImage *imageSelectorMark;   // recommended 16x16
@property (nonatomic) BOOL hideSelectorMarks;
@property (nonatomic) CGSize minimumSize;       // can't be resized smaller than this. 32x32 by default
@property (nonatomic) CGSize maximumSize;
@property (nonatomic, readonly) DZUIViewSelectorGestureState panState;  // The delegate can check this property to detect the current stage of the panning
@property (nonatomic, readonly) DZUIViewSelectorGestureState pinchState;
@property (nonatomic, readonly) DZUIViewSelectorGestureState rotationState;
@property (nonatomic) DZUIViewSelectorMarkStyle selectorMarkStyle;

- (id)initWithTargetView:(UIView *)p;
- (SelectorMarkType) getSelectorMarkTypeAtPoint:(CGPoint) point;

+(void) updateView:(UIView *) view withChangedCenter:(CGPoint) dcenter withChangedSize:(CGSize) dsize;
- (void) updateFrameSize;   // for subclasses

@end
