#pragma once
#include <string>
// 3rd
#include "brpc/controller.h"
#include "google/protobuf/message.h"

using google::protobuf::Message;

namespace press {
class MessageManager {
 public:
  virtual bool Load(const std::string &fp) { throw std::runtime_error("Not implemented"); };
  virtual size_t Size() { throw std::runtime_error("Not implemented"); };
  virtual bool Empty() { return Size() == 0; };
  virtual Message *Get(brpc::Controller *cntl, size_t index) { throw std::runtime_error("Not implemented"); };
};

class ExampleMessageManager : public MessageManager {};
}  // namespace press