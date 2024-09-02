#include "press/press.h"

int main(int argc, char* argv[]) {
  press::PressOptions options;
  press::SetPressOptions(&options, argc, argv);
  options.message_manager = press::ExampleMessageManager();
  press::Start(&options);
  return 0;
}
