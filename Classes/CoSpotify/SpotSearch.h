//
//  SpotSearch.h
//  Spot
//
//  Created by Patrik Sjöberg on 2009-05-25.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SpotPlaylist.h"
#import "SpotSession.h"

#import "despotify.h"

@interface SpotSearch : NSObject { 
  NSArray *artists;
  NSArray *tracks;
  NSArray *albums;
  SpotPlaylist *playlist;
  NSString *query;
  NSString *suggestion;
  int totalTracks;
  int totalArtists;
  int totalAlbums;
  
  //for -moreResults
  SpotSession *session;
  int maxResults;
  struct search_result *searchResult;
}

+(SpotSearch *)searchFor:(NSString *)searchText session:(SpotSession*)session maxResults:(int)maxResults;
+(SpotSearch *)searchFor:(NSString *)searchText maxResults:(int)maxResults;

-(id)initWithSearchText:(NSString *)searchText session:(SpotSession*)session maxResults:(int)maxResults;
-(id)initWithSearchResult:(struct search_result*)sr;

//Get next batch of results
-(SpotSearch *)moreResults;

@property (readonly) NSArray *tracks;
@property (readonly) NSArray *artists;
@property (readonly) NSArray *albums;
@property (readonly) SpotPlaylist *playlist;
@property (readonly) int totalTracks;
@property (readonly) int totalArtists;
@property (readonly) int totalAlbums;
@property (readonly) NSString *suggestion;
@property (readonly) NSString *query;

@end
