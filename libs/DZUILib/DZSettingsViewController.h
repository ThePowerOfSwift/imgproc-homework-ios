//
//  SettingsViewController.h
//  PhotoClockCal
//
//  Created by Simon Kim on 10. 1. 1..
//  Copyright 2010 DZPub.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DZSimpleTableViewDataSource.h"
#import "DZUITextEntryViewController.h"

@class DZSettingsViewController;

@protocol DZSettingsViewControllerDelegate
// informs delegate that it's safe to call addTableViewSection: and addTableViewSections:
- (void) settingsViewControllerNeedSections:(DZSettingsViewController *)settingsViewController;
- (void) settingsViewControlllerDone:(DZSettingsViewController *)settingsViewController;
@end


@interface DZSettingsViewController : UIViewController <UITableViewDelegate, DZSettingsViewControllerDelegate, DZUIEntryViewControllerDelegate, UIActionSheetDelegate, UINavigationControllerDelegate, UIImagePickerControllerDelegate> {
	UITableView *_tableView;
	DZSimpleTableViewDataSource *tableViewDataSource;
	id<DZSettingsViewControllerDelegate> __unsafe_unretained internalDelegate;
	NSIndexPath *indexPathChecked;						// for execlusive checkmark selection mode
	NSIndexPath *indexPathLastSelected;						// for later reference
	UIToolbar *_toolbar;
}
@property (nonatomic, unsafe_unretained) id<DZSettingsViewControllerDelegate> internalDelegate;
@property (nonatomic, strong) NSIndexPath *indexPathChecked;
@property (nonatomic, strong) NSIndexPath *indexPathLastSelected;
@property (nonatomic, readonly) DZSimpleTableViewDataSource *tableViewDataSource;
@property (nonatomic, assign) BOOL toolbarEnabled;
@property (unsafe_unretained, nonatomic, readonly) UIToolbar *toolbar;

- (void) addTableViewSection:(TableViewSection *) section;
- (void) addTableViewSections:(NSArray *) sections;

- (void) enteredText:(NSString *) text ofRowAtIndexPath:(NSIndexPath *) indexPath;
// Perform table view transion to show different style (or layout) of table view
- (void) animateTableViewTranstion: (UIViewAnimationTransition) transition;
@end
