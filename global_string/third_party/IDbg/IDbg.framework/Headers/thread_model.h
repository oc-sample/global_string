//
// Created by mjzheng on 2021/3/18.
//  Copyright © 2021年 mjzheng. All rights reserved.
//

#ifndef IDBG_BASE_THREAD_MODEL_H_
#define IDBG_BASE_THREAD_MODEL_H_

#include <thread>
#include <mutex>
#include <condition_variable>

#include <queue>
#include <string>

#include <memory>

namespace IDbg {

class ThreadModel {
 public:
  explicit ThreadModel(const std::string& thread_name);

  ~ThreadModel();

 public:
  int PushTask(std::function<void()> func);

  int Sleep(int64_t interval);

 protected:
  void Run();

  void DoAllTask();

 private:
  int StartThread();

  int StopThread();

 private:
  bool quited_;
  std::condition_variable cv_;
  std::mutex mu_;
  std::queue<std::function<void()>> task_list_;

 private:
  std::unique_ptr<std::thread> th_;
  std::string thread_name_;
};

}  // namespace IDbg

#endif  // IDBG_BASE_THREAD_MODEL_H_
