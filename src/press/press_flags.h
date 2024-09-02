#pragma once
#include "gflags/gflags.h"

namespace press {
DECLARE_int32(dummy_port);
DECLARE_string(proto);
DECLARE_string(inc);
DECLARE_string(method);
DECLARE_string(server);
DECLARE_string(input);
DECLARE_string(output);
DECLARE_string(lb_policy);
DECLARE_int32(thread_num);
DECLARE_string(protocol);
DECLARE_string(connection_type);
DECLARE_int32(timeout_ms);
DECLARE_int32(connection_timeout_ms);
DECLARE_int32(max_retry);
DECLARE_int32(request_compress_type);
DECLARE_int32(response_compress_type);
DECLARE_int32(attachment_size);
DECLARE_int32(duration);
DECLARE_int32(qps);
DECLARE_bool(pretty);
}  // namespace press