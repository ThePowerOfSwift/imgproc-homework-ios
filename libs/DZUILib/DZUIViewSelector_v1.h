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


@class DZUIViewSelector;

@protocol DZUIViewSelectorDelegate
// informs delegate that it's safe to call addTableViewSection: and addTableViewSections:
- (void) viewSelector:(DZUIViewSelector *)viewSelector changedCenter:(CGPoint) dcenter Size:(CGSize) dsize atMark:(SelectorMarkType) markType;
- (void) viewSelectorDidTap:(DZUIViewSelector *)viewSelector ;
@end



@interface DZUIViewSelector : UIView {
    CGRect rectSelectorMarks[SELECT_MARK_TYPE_NUM];
    UIView *targetView;
    UIImage *imageBall;
    
    BOOL _beganMoving;
    CGPoint _previousPoint;
    SelectorMarkType _currentMark;
    
    id<DZUIViewSelectorDelegate> __unsafe_unretained delegate;
}

@property (unsafe_unretained, nonatomic) UIView *targetView;
@property (unsafe_unretained, nonatomic) id<DZUIViewSelectorDelegate> delegate;

- (id)initWithTargetView:(UIView *)p;
- (SelectorMarkType) getSelectorMarkTypeAtPoint:(CGPoint) point;
+(void) updateView:(UIView *) view withChangedCenter:(CGPoint) dcenter withChangedSize:(CGSize) dsize;


@end
