//
//  MPLocationsProvider.h
//  MapsIndoors SDK for iOS
//
//  Created by Daniel Nielsen on 1/14/14.
//  Copyright (c) 2014 MapsPeople A/S. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MPLocationDataset.h"
#import "MPLocationQuery.h"
#import "MPLocation.h"

typedef void(^mpLocationDetailsHandlerBlockType)(MPLocation* location, NSError* error);
typedef void(^mpLocationListHandlerBlockType)(MPLocationDataset* locationData, NSError* error);

/**
 Locations provider delegate.
 */
@protocol MPLocationsProviderDelegate <NSObject>
/**
 Locations data ready event method.
 @param  LocationsCollection The Locations data collection.
 */
@required
- (void) onLocationsReady: (MPLocationDataset*)locationData;

@required
- (void) onLocationDetailsReady: (MPLocation*)location;
@end


/**
 Locations provider protocol.
 */
@protocol MPLocationsProvider <NSObject>

@property (weak) id <MPLocationsProviderDelegate> delegate;

/**
 Method to initiate fetching of all locations from the provider in a specific translation.
 @param  solutionId The MapsIndoors solution ID.
 @param  language The language code. Must be one of the MapsIndoors solutions supported content languages.
 */
- (void)getLocationsAsync: (NSString*) solutionId language: (NSString*) language DEPRECATED_MSG_ATTRIBUTE("Use getLocations instead");

/**
 Method to initiate fetching of all locations from the provider in the current transation ([MapsIndoors getLanguage]).
 */
- (void)getLocations;

/**
 Method to initiate fetching of all locations from the provider in a specific translation.
 @param  solutionId The MapsIndoors solution ID.
 @param  language The language code. Must be one of the MapsIndoors solutions supported content languages.
 @param  handler The handler callback block. Contains the MPLocation object (can be nil) and an NSError object (can be nil).
 */
- (void)getLocationsAsync: (NSString*) solutionId language: (NSString*) language completionHandler: (mpLocationListHandlerBlockType) handler DEPRECATED_MSG_ATTRIBUTE("Use getLocationsCompletionHandler instead");

/**
 Method to initiate fetching of all locations from the provider in the current transation ([MapsIndoors getLanguage]).
 @param  handler The handler callback block. Contains the MPLocation object (can be nil) and an NSError object (can be nil).
 */
- (void)getLocationsWithCompletion: (mpLocationListHandlerBlockType) handler;

/**
 Method to query a unique location from the provider based on an id.
 @param  solutionId The MapsIndoors solution ID.
 @param  locationId The MapsIndoors location ID.
 @param  language The language code. Must be one of the MapsIndoors solutions supported content languages.
 */
- (void)getLocationDetailsAsync: (NSString*) solutionId withId:(NSString*)locationId language: (NSString*) language DEPRECATED_MSG_ATTRIBUTE("Use getLocationWithId: instead");

/**
 Method to query a unique location from the provider based on an id.
 Data is returned in the current transation ([MapsIndoors getLanguage]).
 @param  locationId The MapsIndoors location ID.
 */
- (void)getLocationWithId:(NSString*)locationId;

/**
 Method to query a unique location from the provider based on an id.
 @param  solutionId The MapsIndoors solution ID.
 @param  locationId The MapsIndoors location ID.
 @param  language The language code. Must be one of the MapsIndoors solutions supported content languages.
 @param  handler The handler callback block. Contains the MPLocation object (can be nil) and an NSError object (can be nil).
 */
- (void)getLocationDetailsAsync: (NSString*) solutionId withId:(NSString*)locationId language: (NSString*) language completionHandler: (mpLocationDetailsHandlerBlockType) handler DEPRECATED_MSG_ATTRIBUTE("Use getLocationWithId:completionHandler: instead");

/**
 Method to query a unique location from the provider based on an id.
 Data is returned in the current transation ([MapsIndoors getLanguage]).
 @param  locationId The MapsIndoors location ID.
 */
@required
- (void)getLocationWithId:(NSString*)locationId completionHandler:(mpLocationDetailsHandlerBlockType) handler;

/**
 Method to query a subset of locations from the provider.
 @param  locationQuery Locations query object. Must at least define your MapsIndoors solution ID (MPLocationQuery.solutionId)
 @param  language The language code. Must be one of the MapsIndoors solutions supported content languages.
 */
<<<<<<< HEAD
- (void)getLocationsUsingQueryAsync: (MPLocationQuery*) locationQuery language: (NSString*) language DEPRECATED_MSG_ATTRIBUTE("Use getLocationsUsingQuery: instead");
=======
@required
- (void)getLocationsUsingQueryAsync: (MPLocationQuery*) locationQuery language: (NSString*) language completionHandler: (mpLocationListHandlerBlockType) handler;

/**
 Determine if cached or preloaded data is available for the given solutionId.
 
 @param solutionId
 @param language
 @return YES if offline or preloaded data is available, else NO,
 */
+ (BOOL) isOfflineDataAvailableForSolutionId:(NSString*)solutionId language:(NSString*)language;

@end

>>>>>>> 5168bf5a9e34df5e00f496f1239e6c60f995ed3d

/**
 Determine if cached or preloaded data is available for the given solutionId.
 
 @param solutionId
 @param language
 @return YES if offline or preloaded data is available, else NO,
 */
+ (BOOL) isOfflineDataAvailableForSolutionId:(NSString*)solutionId language:(NSString*)language;

/**
 Method to query a subset of locations from the provider.
 Data is returned in the current transation ([MapsIndoors getLanguage]).
 @param  locationQuery Locations query object. Must at least define your MapsIndoors solution ID (MPLocationQuery.solutionId)
 */
- (void)getLocationsUsingQuery:(MPLocationQuery*) locationQuery;

/**
 Method to query a subset of locations from the provider.
 @param  locationQuery Locations query object. Must at least define your MapsIndoors solution ID (MPLocationQuery.solutionId)
 @param  language The language code. Must be one of the MapsIndoors solutions supported content languages.
 @param  handler The handler callback block. Contains the MPLocationDataset object (can be nil) and an NSError object (can be nil).
 */
- (void)getLocationsUsingQueryAsync: (MPLocationQuery*) locationQuery language: (NSString*) language completionHandler: (mpLocationListHandlerBlockType) handler DEPRECATED_MSG_ATTRIBUTE("Use getLocationsUsingQuery:completionHandler: instead");

/**
 Method to query a subset of locations from the provider.
 Data is returned in the current translation ([MapsIndoors getLanguage]).
 @param  locationQuery Locations query object. Must at least define your MapsIndoors solution ID (MPLocationQuery.solutionId)
 @param  handler The handler callback block. Contains the MPLocationDataset object (can be nil) and an NSError object (can be nil).
 */
- (void)getLocationsUsingQuery:(MPLocationQuery*)locationQuery completionHandler:(mpLocationListHandlerBlockType)handler;

@end


/**
 Locations provider that defines a delegate and a method to initiate fetching of locations from the provider.
 */
@interface MPLocationsProvider : NSObject<MPLocationsProvider>

@end
