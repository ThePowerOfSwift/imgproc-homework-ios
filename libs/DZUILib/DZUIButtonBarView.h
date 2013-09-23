//
//  DZUIButtonBarView.h
//  DZUILib
//
//  Created by Simon Kim on 12. 3. 3..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#import <UIKit/UIKit.h>
@class DZUIButtonBarView;
@protocol DZUIButtonBarViewDelegate <NSObject>

- (void) buttonBarView:(DZUIButtonBarView *) buttonBarView didTouchButtonIndex:(NSUInteger) buttonIndex;

@end
@interface DZUIButtonBarView : UIView
@property (nonatomic, copy) NSArray *images;    // must be 6 UIImage objects
@property (nonatomic, assign) id<DZUIButtonBarViewDelegate> delegate;
@property (nonatomic, assign) id cookie;
@property (nonatomic) NSUInteger buttonCount;

- (UIButton *) buttonAtIndex:(NSUInteger) buttonIndex;
@end
