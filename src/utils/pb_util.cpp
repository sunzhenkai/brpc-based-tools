#include "pb_util.h"

#include <butil/logging.h>

using google::protobuf::Descriptor;
using google::protobuf::DescriptorPool;
using google::protobuf::DynamicMessageFactory;
using google::protobuf::Message;
using google::protobuf::MessageFactory;
using google::protobuf::MethodDescriptor;
using google::protobuf::ServiceDescriptor;
using google::protobuf::compiler::Importer;
using std::string;

namespace utils {

const MethodDescriptor *find_method_by_name(const string &service_name, const string &method_name, Importer *importer) {
  const ServiceDescriptor *descriptor = importer->pool()->FindServiceByName(service_name);
  if (nullptr == descriptor) {
    LOG(FATAL) << "Fail to find service=" << service_name;
    return nullptr;
  }
  return descriptor->FindMethodByName(method_name);
}

const Message *get_prototype_by_method_descriptor(const MethodDescriptor *descripter, bool is_input,
                                                  DynamicMessageFactory *factory) {
  if (nullptr == descripter) {
    LOG(FATAL) << "Param[descripter] is nullptr";
    return nullptr;
  }
  const Descriptor *message_descriptor = nullptr;
  if (is_input) {
    message_descriptor = descripter->input_type();
  } else {
    message_descriptor = descripter->output_type();
  }
  return factory->GetPrototype(message_descriptor);
}

const Message *get_prototype_by_name(const string &service_name, const string &method_name, bool is_input,
                                     Importer *importer, DynamicMessageFactory *factory) {
  const MethodDescriptor *descripter = find_method_by_name(service_name, method_name, importer);
  return get_prototype_by_method_descriptor(descripter, is_input, factory);
}

}  // namespace utils
