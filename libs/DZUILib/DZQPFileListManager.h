//
//  DZQPFileListManager.h
//  QuickPoint_Prototype
//
//  Created by Simon Kim on 10. 1. 24..
//  Copyright 2010 DZPub.com. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface DZQPFileListManager : NSObject {
	NSMutableArray *arrayFileNames;
	NSString *extension;
	NSString *baseSubdir;		// subdirectory under Documents directory of application home directory
	NSString *filenamePrefix;
    
    NSMutableArray *dirsOnly;
    NSMutableArray *filesOnly;
}
@property (unsafe_unretained, nonatomic, readonly) NSArray *fileNames;
@property (nonatomic, strong) NSString *extension;
@property (nonatomic, strong) NSString *baseSubdir;
@property (nonatomic, strong) NSString *filenamePrefix;

- (void) loadFileList;
- (NSString *) generateNewFileNameWithExtension:(NSString *) ext;
- (NSString *) generateNewFileName;
- (NSString *) fullPathOf:(NSString *) file;
- (NSArray *) dirList;
- (NSArray *) filesOnlyList;
@end
