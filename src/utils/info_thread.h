#pragma once
#include <bvar/bvar.h>
#include <pthread.h>

namespace utils {

struct InfoThreadOptions {
  bvar::LatencyRecorder* latency_recorder;
  bvar::Adder<int64_t>* sent_count;
  bvar::Adder<int64_t>* error_count;

  InfoThreadOptions() : latency_recorder(NULL), sent_count(NULL), error_count(NULL) {}
};

class InfoThread {
 public:
  InfoThread();
  ~InfoThread();
  void run();
  bool start(const InfoThreadOptions&);
  void stop();

 private:
  bool _stop;
  InfoThreadOptions _options;
  pthread_mutex_t _mutex;
  pthread_cond_t _cond;
  pthread_t _tid;
};

}  // namespace utils
