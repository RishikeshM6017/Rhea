#pragma once

#ifdef ENGINE_EXPORT
#ifdef _MSC_VER
#define RAPI __declspec(dllexport)
#else
#define RAPI __attribute__((visibility("default")))
#endif
#else
#ifdef _MSC_VER
#define RAPI __declspec(dllimport)
#else
#define RAPI
#endif
#endif

#include "Types.h"

#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>