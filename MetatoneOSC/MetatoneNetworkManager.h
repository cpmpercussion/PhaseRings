//
//  MetatoneNetworkManager.h
//  Metatone
//
//  Created by Charles Martin on 10/04/13.
//  Copyright (c) 2013 Charles Martin. All rights reserved.
//  Updated Version to work with F53OSC.
//

#import <Foundation/Foundation.h>
#import "F53OSC.h"

// IP Address method
#import <ifaddrs.h>
#import <arpa/inet.h>

@protocol MetatoneNetworkManagerDelegate <NSObject>

-(void) searchingForLoggingServer;
-(void) loggingServerFoundWithAddress: (NSString *) address andPort: (int) port andHostname:(NSString *) hostname;
-(void) stoppedSearchingForLoggingServer;
-(void) didReceiveMetatoneMessageFrom:(NSString*)device withName:(NSString*)name andState:(NSString*)state;

@end

@interface MetatoneNetworkManager : NSObject <F53OSCPacketDestination,F53OSCClientDelegate, NSNetServiceDelegate, NSNetServiceBrowserDelegate>

@property (strong,nonatomic) F53OSCClient *oscClient;
@property (strong,nonatomic) F53OSCServer *oscServer;

//@property (strong, nonatomic) OSCConnection *connection;
@property (strong, nonatomic) NSString *remoteIPAddress;
@property (nonatomic) NSInteger remotePort;
@property (strong, nonatomic) NSString *remoteHostname;
@property (strong, nonatomic) NSString *deviceID;
@property (strong, nonatomic) NSString *localIPAddress;
@property (strong, nonatomic) NSNetService *metatoneNetService;
@property (strong, nonatomic) NSNetServiceBrowser *oscLoggerServiceBrowser;
@property (strong, nonatomic) NSNetServiceBrowser *metatoneServiceBrowser;
@property (strong, nonatomic) NSNetService *oscLoggerService;
@property (strong, nonatomic) NSMutableArray *remoteMetatoneIPAddresses;
@property (strong, nonatomic) NSMutableArray *remoteMetatoneNetServices;
@property (nonatomic) bool oscLogging;


@property (weak,nonatomic) id<MetatoneNetworkManagerDelegate> delegate;


+ (NSString *)getIPAddress;
+ (NSString *)getLocalBroadcastAddress;

// Designated Initialiser
- (MetatoneNetworkManager *) initWithDelegate: (id<MetatoneNetworkManagerDelegate>) delegate  shouldOscLog: (bool) osclogging;
// Stops all searches and deletes records of remote services and addresses.
- (void)stopSearches;

- (void)sendMessageWithAccelerationX:(double) X Y:(double) Y Z:(double) Z;
- (void)sendMessageWithTouch:(CGPoint) point Velocity:(CGFloat) vel;
- (void)sendMessageTouchEnded;
- (void)sendMesssageSwitch:(NSString *)name On:(BOOL)on;
- (void)sendMetatoneMessage:(NSString *)name withState:(NSString *)state;


@end