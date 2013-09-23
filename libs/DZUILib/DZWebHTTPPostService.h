//
//  DZWebHTTPPostService.h
//  DZUILib
//
//  Created by Simon Kim on 12. 5. 18..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DZWebHTTPPostServiceLocalFileDescription.h"

@interface DZWebHTTPPostService : NSObject
@property (nonatomic, strong) NSURL *remoteURL;

- (id) initWithRemoteURL:(NSURL *) remoteURL;
// localFiles: array of DZWebHTTPPostServiceLocalFileDescription objects
//- (NSURLRequest *)uploadRequestWithFormData:(NSDictionary *) formData headerFields:(NSDictionary *) headerFields localFiles:(NSArray *)localFiles;
- (NSURLRequest *)uploadRequestWithHeaderFields:(NSDictionary *) headerFields formData:(NSDictionary *) formData localFile:(DZWebHTTPPostServiceLocalFileDescription *)localFile;

- (NSURLRequest *)uploadRequestWithFormData:(NSDictionary *) formData headerFields:(NSDictionary *) headerFields;
- (NSURLRequest *)uploadRequestWithFileURL:(NSURL *)fileURL formId:(NSString *) formId mimeType:(NSString *) contentType;
- (BOOL) postUploadAtLocalURL:(NSURL *) localURL formId:(NSString *) formId statusReportBlock:(void (^)(NSURLResponse *response, NSError *error, NSData *data)) statusReportBlock;

- (BOOL) postUploadAtLocalURLs:(NSArray *) localURLs formId:(NSString *) formId statusReportBlock:(void (^)(NSURLResponse *response, NSError *error, NSData *data)) statusReportBlock;
- (BOOL) postUploadAtLocalURLs:(NSArray *) localURLs formId:(NSString *) formId formData:(NSDictionary *) formData statusReportBlock:(void (^)(NSURLResponse *response, NSError *error, NSData *data)) statusReportBlock;

@end
