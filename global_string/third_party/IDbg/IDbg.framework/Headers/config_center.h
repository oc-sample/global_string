//
//  Created by mjzheng on 2021/4/13.
//  Copyright © 2021 mjzheng. All rights reserved.
//

#ifndef IDBG_MONITOR_CONFIG_CENTER_H_
#define IDBG_MONITOR_CONFIG_CENTER_H_

#include <map>
#include <string>
#include <memory>
#include "singleton.h"

namespace IDbg {

enum class MonitorType : uint64_t {
  kMonitorNone = 0,
  kHighCpu = 1 << 0,
  kThreadCpu = 1 << 1,
};

struct CpuConditionConfig {
  int64_t duration;
  float threshold;
  float max_threshold;
  std::string cpu_type;
};

struct HighCpuConfig {
  CpuConditionConfig app_condition = {10000, 1, 90, "app"};
  CpuConditionConfig sys_condition = {10000, 1, 99, "sys"};
  float thread_cpu_threshold = 1;

  int64_t dump_count = 3;
  int64_t dump_interval_ms = 500;
  int64_t dump_thread_number = 3;

  int64_t max_sample_count = 3;
  int64_t sample_interval_ms = 60000;

  std::map<std::string, int> block_thread_list;
};

struct ThreadCpuConfig {
  bool is_report_range = false;
};

}  // namespace IDbg

#endif  // IDBG_MONITOR_CONFIG_CENTER_H_
