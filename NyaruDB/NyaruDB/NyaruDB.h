//
//  NyaruDB.h
//  NyaruDB
//
//  Created by Kelp on 2013/02/18.
//

#import <Foundation/Foundation.h>
#import "NyaruCollection.h"
#import "NyaruQuery.h"


@interface NyaruDB : NSObject {
    // key: collection name, value: collection
    NSMutableDictionary *_collections;
    
    // data base path
    NSString *_databasePath;
}

#pragma mark - Static methods
/**
 Get the shared instance for iOS.
 @return NyaruDB shared instance
 */
+ (id)instance;

/**
 Remove all database for iOS.
 if you init database error, maybe need to call this message.
 */
+ (void)reset;


#pragma mark - Init
/**
 Init NyaruDB for iOS.
 The folder of NyaruDB is /your-app/Documents/NyaruDB
 @return NyaruDB instance
 */
- (id)init;
/**
 Init NyaruDB for OS X.
 @param path Database files are in this path.
 @return NyaruDB instance
 */
- (id)initWithPath:(NSString *)path;


#pragma mark - Collection
/**
 Get all collections.
 @return @[NyaruCollection]
 */
- (NSArray *)collections;
/**
 Get the collection with name. If collection is not exist then create it.
 @param name collection name
 @return NyaruCollection / nil
 */
- (NyaruCollection *)collection:(NSString *)name;
/**
 Please use [NyaruDB collection:name]
 This method just for 1.3, It will be removed in 1.4.
 */
- (NyaruCollection *)collectionForName:(NSString *)name;
/**
 Remove the collection with name.
 @param name collection name
 */
- (void)removeCollection:(NSString *)name;
- (void)removeAllCollections;

/**
 Close all file handles and collections for OS X.
 Before release instance you should invoke this method.
 */
- (void)close;

@end
