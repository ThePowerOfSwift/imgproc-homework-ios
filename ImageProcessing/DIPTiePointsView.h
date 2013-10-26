//
//  DIPTiePointsView.h
//  ImageProcessing
//
//  Created by Simon Kim on 13. 10. 23..
//  Copyright (c) 2013년 DZPub.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DIPTiePointsView : UIView
// array of NSValue (CGPoint)
- (NSArray *) tiePointsScaleBySize:(CGSize) size;

@end
