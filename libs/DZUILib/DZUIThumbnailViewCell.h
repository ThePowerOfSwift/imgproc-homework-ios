//
//  DZUIThumbnailViewCell.h
//  PhotoClockCal
//
//  Created by Simon Kim on 10. 1. 7..
//  Copyright 2010 DZPub.com. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface DZUIThumbnailViewCell : UITableViewCell {
	NSMutableArray *_arrayImageViews;
	NSMutableArray *_arrayImages;
	CGFloat iconWidth;
	CGFloat iconHeight;
	CGFloat iconHorzGap;
	CGFloat iconTopMargin;
	BOOL alignCenter;
	BOOL respectImageSize;
	
	
}
- (void) setImages:(NSArray *) arrayImages;
- (UIImageView *) imageViewAtPoint:(CGPoint) point;

+ (DZUIThumbnailViewCell *)obtainGridCellFromTable:(UITableView *)tableViewParam withStyle:(UITableViewCellStyle) cellStyle;

@end


/*
 Example of using DZUIThumbnailViewCell
 
 // Customize the appearance of table view cells.
 - (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
 
 DZUIThumbnailViewCell *cell = [DZUIThumbnailViewCell obtainGridCellFromTable:tableView withStyle:UITableViewCellStyleDefault];
 
 UIImage *image = [_arrayImages objectAtIndex:indexPath.row];
 CGSize zoomedSize = [self _zoomedSize:image.size zoomLevel:_zoomLevel];
 image = [ImageManipulator imageWithImage:image scaledToSize:zoomedSize];
 
 
 [cell setImages:[NSArray arrayWithObject:image]];
 return cell;
 
 } 
*/