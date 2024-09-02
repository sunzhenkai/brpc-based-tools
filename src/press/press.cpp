// 3rd
#include <brpc/server.h>
// self
#include "press/press.h"

namespace press {
bool SetPressOptions(press::PressOptions* options, int argc, char* argv[]) {
  // read command line flags
  google::ParseCommandLineFlags(&argc, &argv, true);

  // set options
  size_t dot_pos = FLAGS_method.find_last_of('.');
  if (dot_pos == std::string::npos) {
    LOG(ERROR) << "-method must be in form of: package.service.method";
    return false;
  }
  options->service = FLAGS_method.substr(0, dot_pos);
  options->method = FLAGS_method.substr(dot_pos + 1);
  options->lb_policy = FLAGS_lb_policy;
  options->test_req_rate = FLAGS_qps;
  if (FLAGS_thread_num > 0) {
    options->test_thread_num = FLAGS_thread_num;
  } else {
    if (FLAGS_qps <= 0) {  // unlimited qps
      options->test_thread_num = 50;
    } else {
      options->test_thread_num = FLAGS_qps / 10000;
      if (options->test_thread_num < 1) {
        options->test_thread_num = 1;
      }
      if (options->test_thread_num > 50) {
        options->test_thread_num = 50;
      }
    }
  }

  const int rate_limit_per_thread = 1000000;
  double req_rate_per_thread = options->test_req_rate / options->test_thread_num;
  if (req_rate_per_thread > rate_limit_per_thread) {
    LOG(ERROR) << "req_rate: " << (int64_t)req_rate_per_thread << " is too large in one thread. The rate limit is "
               << rate_limit_per_thread << " in one thread";
    return false;
  }

  options->input = FLAGS_input;
  options->output = FLAGS_output;
  options->connection_type = FLAGS_connection_type;
  options->connect_timeout_ms = FLAGS_connection_timeout_ms;
  options->timeout_ms = FLAGS_timeout_ms;
  options->max_retry = FLAGS_max_retry;
  options->protocol = FLAGS_protocol;
  options->request_compress_type = FLAGS_request_compress_type;
  options->response_compress_type = FLAGS_response_compress_type;
  options->attachment_size = FLAGS_attachment_size;
  options->host = FLAGS_server;
  options->proto_file = FLAGS_proto;
  options->proto_includes = FLAGS_inc;
  return true;
}

void Start(press::PressOptions* options) {
  if (FLAGS_dummy_port >= 0) {
    brpc::StartDummyServerAt(FLAGS_dummy_port);
  }
  auto* rpc_press = new press::RpcPress;
  if (0 != rpc_press->init(options)) {
    LOG(FATAL) << "Fail to init rpc_press";
    return;
  }

  rpc_press->start();
  if (FLAGS_duration <= 0) {
    while (!brpc::IsAskedToQuit()) {
      sleep(1);
    }
  } else {
    sleep(FLAGS_duration);
  }
  rpc_press->stop();
  delete rpc_press;
}

void Start(int argc, char* argv[]) {
  press::PressOptions options;
  if (!SetPressOptions(&options, argc, argv)) return;
  Start(&options);
}
}  // namespace press
