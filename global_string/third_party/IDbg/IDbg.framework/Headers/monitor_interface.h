//
// Created by mjzheng on 2021/3/18.
//  Copyright © 2021年 mjzheng. All rights reserved.
//

#ifndef IDBG_MONITOR_MONITOR_INTERFACE_H_
#define IDBG_MONITOR_MONITOR_INTERFACE_H_

#include <stdint.h>
#include "thread_cpu_info.h"
#include "config_center.h"

namespace IDbg {

struct PerformanceData {
  ThreadStackArray cpu_info;
  float app_cpu;
  float sys_cpu;
};

class PerformanceDelegate {
 public:
  virtual ~PerformanceDelegate() = default;

  virtual void OnStack(const ThreadStackSlices& slices) {}
};

class MonitorInterface {
 public:
  explicit MonitorInterface(PerformanceDelegate* p) : delegate_(p) {}
  virtual ~MonitorInterface() = default;
  virtual int Start() = 0;
  virtual void Stop() = 0;
  virtual void OnTimer() = 0;
  virtual void OnUpdate(const PerformanceData& data) = 0;

 protected:
  PerformanceDelegate* delegate_;
};

class ThreadInterface {
 public:
  virtual ~ThreadInterface() = default;

  virtual int Start() = 0;

  virtual void Stop() = 0;

  virtual void OnTimer() = 0;
};

std::unique_ptr<MonitorInterface> CreateHighCpuMonitor(PerformanceDelegate* p);

std::unique_ptr<MonitorInterface> CreateThreadCpuMonitor(PerformanceDelegate* p);

}  // namespace IDbg

#endif  // IDBG_MONITOR_MONITOR_INTERFACE_H_
