//
//  TextEntryViewController.h
//  LogEverything_Prototype
//
//  Created by Simon Kim on 09. 11. 14..
//  Copyright 2009 DZPub.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "EntryViewController.h"



@interface DZUITextEntryViewController : UITableViewController <DZUIEntryViewController> 
@property (nonatomic, unsafe_unretained) NSArray *arrayTextOptions;
@property (nonatomic, strong) NSString *fieldName;
@property (nonatomic, strong) NSString *defaultText;
@property (nonatomic, strong) NSString *placeHolder;
@property (nonatomic, strong, readonly) NSString *enteredText;
@property (nonatomic, assign) id cookie;
@property (nonatomic) BOOL useTextView;     // insead of textField
- (void) actionBarButtonDone:(id) sender;
- (void) actionBarButtonCancel:(id) sender;

- (UITableViewCell *) tableViewCellFrom:(UITableView *)tableView withStyle:(UITableViewCellStyle) cellStyle;

@end
