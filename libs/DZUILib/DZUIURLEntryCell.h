//
//  DZUIURLEntryCell.h
//  SeminarSamples
//
//  Created by Simon Kim on 12. 4. 6..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#import <UIKit/UIKit.h>
typedef void(^TextFieldPressedReturnBlock)(NSString *text);

@interface DZUIURLEntryCell : UITableViewCell
@property (nonatomic, strong) IBOutlet UITextField *textFieldURL;
@property (nonatomic, strong) TextFieldPressedReturnBlock returnBlock;
@end
