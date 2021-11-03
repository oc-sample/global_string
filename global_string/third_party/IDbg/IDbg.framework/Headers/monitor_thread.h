//
//  Created by mjzheng on 2021/4/13.
//  Copyright © 2021 mjzheng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "monitor_interface.h"

#ifndef IDBG_MONITOR_MONITOR_THREAD_H_
#define IDBG_MONITOR_MONITOR_THREAD_H_

NS_ASSUME_NONNULL_BEGIN

/**
 */
@interface MonitorThread : NSObject

- (instancetype)initWithCb:(IDbg::ThreadInterface*) p;

- (void)start;

- (void)stop;

@end

NS_ASSUME_NONNULL_END

#endif  // IDBG_MONITOR_MONITOR_THREAD_H_
