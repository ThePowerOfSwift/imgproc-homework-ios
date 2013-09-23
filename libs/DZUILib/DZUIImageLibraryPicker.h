//
//  DZUIImageLibraryPicker.h
//  QuickPoint_Prototype
//
//  Created by Simon Kim on 11. 4. 16..
//  Copyright 2011 DZPub.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DZUIIconGridViewController.h"
#import "DZQPFileListManager.h"

@class DZUIImageLibraryPicker;

@protocol DZUIImageLibraryPickerDelegate
- (void) imageLibraryPickerDidCancel:(DZUIImageLibraryPicker *) picker;
- (void) imageLibraryPicker:(DZUIImageLibraryPicker *) picker didSelectImageURL:(NSURL *) imageURL;
- (void) imageLibraryPicker:(DZUIImageLibraryPicker *) picker didSelectImageFile:(NSString *) imageFile;

@end


@interface DZUIImageLibraryPicker : DZUIIconGridViewController <DZUIIconGridViewControllerDelegate, DZUIIconGridViewControllerEventDelegate, UIImagePickerControllerDelegate, UINavigationControllerDelegate> 
{
    id<DZUIImageLibraryPickerDelegate> __unsafe_unretained delegate;
    NSString *baseSubdir;
    NSMutableArray *contentsOfBaseSubdir; // under the base sub directory
    NSMutableArray *dirsUnderbaseSubdir;    // These are Categories
    NSMutableArray *filesUnderbaseSubdir;   
    NSString *currentSubdirPath;    
    
    DZQPFileListManager *fileListManager;
    BOOL categorySelectedAll;
    
    UIImage *imageFolder;
}

@property (nonatomic, unsafe_unretained) id<DZUIImageLibraryPickerDelegate> delegate;
@property (nonatomic, strong) NSString *baseSubdir;
@property (nonatomic, strong) NSString *currentSubdirPath;
- (void) _loadContentsOfBaseSubdir;

- (id) init;
+ (id) imageLibraryPicker;

@end
