//
//  PYATableEditorBase.h
//  PrototypeYourApp_Prototype1
//
//  Created by Simon Kim on 09. 11. 8..
//  Copyright 2009 DZPub.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@interface TableViewSection : NSObject {
	NSString *headerText;
	NSString *footerText;
	BOOL exclusiveSelection;			// User shall choose one of rows in this section
										// cellStyle is ignore and used Checkmark
	NSUInteger checkedRow;				// index of checked row, valid only when exclusiveSelection == YES
	id configKey;								// key for configuration dictionary
	id configValue;							// value for configuration dictionary
	
	id cookie;							// general purpose object holder. retained.
@public
	NSMutableArray *arrayRows;
}
@property (nonatomic, strong) NSString *headerText;
@property (nonatomic, strong) NSString *footerText;
@property (nonatomic, readonly) NSMutableArray *arrayRows;
@property (nonatomic, assign) BOOL exclusiveSelection;
@property (nonatomic, assign) NSUInteger checkedRow;
@property (nonatomic, strong) id configKey;
@property (nonatomic, strong) id configValue;
@property (nonatomic, strong) id cookie;
@end

typedef enum {
	DZSimpleTableViewRowStyleNone,
	DZSimpleTableViewRowStyleDrillDownChoose,
	DZSimpleTableViewRowStyleSwitch,
	DZSimpleTableViewRowStyleText,				// ADDED: to support text entry
	DZSimpleTableViewRowStyleImage,
} DZSimpleTableViewRowStyle;

@interface TableViewRow : NSObject {
	NSString *text;
	NSString *detailedText;
	UIImage *image;
	UITableViewCellStyle cellStyle;
	UITableViewCellAccessoryType accessoryType;
	DZSimpleTableViewRowStyle tableViewRowStyle;
	NSMutableArray *nestedTableViewSections;
	
	id configKey;								// key for configuration dictionary
	id configValue;							// value for configuration dictionary
	
	id cookie;								// to hold temporary data or private data for specific application
	
}
@property (nonatomic, strong) NSString *text;
@property (nonatomic, strong) NSString *detailedText;
@property (nonatomic, strong) UIImage *image;
@property (nonatomic, assign) UITableViewCellStyle cellStyle;
@property (nonatomic, assign) UITableViewCellAccessoryType accessoryType;
@property (nonatomic, assign) DZSimpleTableViewRowStyle tableViewRowStyle;
@property (nonatomic, readonly) NSMutableArray *nestedTableViewSections;
@property (nonatomic, strong) id configKey;
@property (nonatomic, strong) id configValue;
@property (nonatomic, strong) id cookie;

- (BOOL) copyTo:(TableViewRow *)row;
@end




@interface DZSimpleTableViewDataSource : NSObject <UITableViewDataSource> {
	NSMutableArray *arraySections;
	CGSize _sizeLimitForImageRow;
}
@property(nonatomic, readonly) NSMutableArray *arraySections;
@property(nonatomic, readonly) CGSize sizeLimitForImageRow;
@end

@interface PYATableEditorBase : NSObject {

}

@end
