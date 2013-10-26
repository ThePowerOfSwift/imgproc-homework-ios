//
//  DIPMenuViewController.h
//  ImageProcessing
//
//  Created by Simon Kim on 13. 9. 10..
//  Copyright (c) 2013년 DZPub.com. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    DIPMenuItemAutoContrast = 0,
    DIPMenuItemFocusMeasure,
    DIPMenuItemTransform
} DIPMenuItem;

@class DIPMenuViewController;
@protocol DIPMenuViewControllerDelegate <NSObject>
- (void) dipMenu:(DIPMenuViewController *) menu didSelect:(DIPMenuItem) menuItem;
@end

@interface DIPMenuViewController : UITableViewController
@property (nonatomic) DIPMenuItem selectedMenuItem;
@property (nonatomic, weak) id<DIPMenuViewControllerDelegate> delegate;
@end
