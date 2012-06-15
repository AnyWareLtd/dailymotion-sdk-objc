//
//  DMItem.h
//  Dailymotion SDK iOS
//
//  Created by Olivier Poitrey on 14/06/12.
//
//

#import <Foundation/Foundation.h>
#import "DMAPI.h"

@interface DMItem : NSObject

@property (nonatomic, readonly, copy) NSString *name;
@property (nonatomic, readonly, copy) NSString *itemId;
@property (nonatomic, readonly, strong) DMAPICacheInfo *cacheInfo;

/**
 * Get an DMItem for a given object name (i.e.: video, user, playlist) and an object id
 *
 * @param name The item type name
 * @param objectId The item id
 *
 * @return A shared instance of DMItem for the requested object
 */
+ (DMItem *)itemWithName:(NSString *)name forId:(NSString *)itemId fromAPI:(DMAPI *)api;

/**
 * Load some fields from either API or cache and callback the passed block with the fields data
 *
 * NOTE: The callback may be called twice if the data was found in the cache but stalled.
 *       First time, the callback will be returned with `stalled` parameter to YES and second time
 *       the `stalled` parameter will be NO. If some fields are cached and other are missing, the
 *       a first callback will return all available fields data and stalled flag will be YES.
 *
 * @prarm fields A list of object fields names to load
 * @param callback The block to call with resulting field data
 */
- (void)withFields:(NSArray *)fields do:(void (^)(NSDictionary *data, BOOL stalled, NSError *error))callback;

/**
 * Flush all previously loaded cache for this item
 */
- (void)flushCache;

@end