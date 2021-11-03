//
//  Created by mjzheng on 2021/7/22.
//  Copyright © 2021 mjzheng. All rights reserved.
//


#include "singleton.h"
#include "monitor_interface.h"

#ifndef IDBG_MONITOR_PERFORMANCE_DISPATCH_H_
#define IDBG_MONITOR_PERFORMANCE_DISPATCH_H_

namespace IDbg {

class PerformanceDispatch : public Singleton<PerformanceDispatch> {
  friend class Singleton<PerformanceDispatch>;
 private:
  PerformanceDispatch();
  ~PerformanceDispatch();

 public:
  int Start();
  void Stop();
  void OnTimer();
  void SetDelegate(PerformanceDelegate* p);

 public:
  void Dispatch(const PerformanceData& data);

 public:
  uint64_t performance_type_;
  std::shared_ptr<ThreadCpuConfig> thread_cpu_config_;
  std::shared_ptr<HighCpuConfig> high_cpu_config_;

 private:
  PerformanceData data_;
  std::unique_ptr<ThreadInterface> thread_wrapper_;
  std::vector<std::unique_ptr<MonitorInterface>> listener_;
  PerformanceDelegate* delegate_;
};

}  // namespace IDbg

#endif  // IDBG_MONITOR_PERFORMANCE_DISPATCH_H_
