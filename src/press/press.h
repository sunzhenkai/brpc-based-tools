#pragma once
// self
#include "press/press_flags.h"
#include "press/rpc_press_impl.h"

namespace press {
bool SetPressOptions(press::PressOptions* options, int argc, char* argv[]);
void Start(press::PressOptions* options);
void Start(int argc, char* argv[]);
}  // namespace press