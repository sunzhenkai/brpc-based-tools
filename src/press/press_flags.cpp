#include "press/press_flags.h"

namespace press {
DEFINE_int32(dummy_port, 8888, "Port of dummy server");
DEFINE_string(proto, "", "User's proto files with path");
DEFINE_string(inc, "", "Include paths for proto, separated by semicolon(;)");
DEFINE_string(method, "example.EchoService.Echo", "The full method name");
DEFINE_string(server, "0.0.0.0:8002",
              "ip:port of the server when -load_balancer is empty, the naming service otherwise");
DEFINE_string(input, "", "Input file containing requests");
DEFINE_string(output, "", "The file containing responses in json format");
DEFINE_string(lb_policy, "", "The load balancer algorithm: rr, random, la, c_murmurhash, c_md5");
DEFINE_int32(thread_num, 0, "Number of threads to send requests. 0: automatically chosen according to -qps");
DEFINE_string(protocol, "baidu_std", "baidu_std hulu_pbrpc sofa_pbrpc http public_pbrpc nova_pbrpc ubrpc_compack...");
DEFINE_string(connection_type, "", "Type of connections: single, pooled, short");
DEFINE_int32(timeout_ms, 1000, "RPC timeout in milliseconds");
DEFINE_int32(connection_timeout_ms, 500, " connection timeout in milliseconds");
DEFINE_int32(max_retry, 3, "Maximum retry times by RPC framework");
DEFINE_int32(request_compress_type, 0, "Snappy:1 Gzip:2 Zlib:3 LZ4:4 None:0");
DEFINE_int32(response_compress_type, 0, "Snappy:1 Gzip:2 Zlib:3 LZ4:4 None:0");
DEFINE_int32(attachment_size, 0, "Carry so many byte attachment along with requests");
DEFINE_int32(duration, 0, "how many seconds the press keep");
DEFINE_int32(qps, 100, "how many calls  per seconds");
DEFINE_bool(pretty, true, "output pretty jsons");
}  // namespace press