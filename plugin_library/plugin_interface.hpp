#pragma once

#define EXPORT __attribute__((visibility("default")))
#define IMPORT

#if defined(COMPILE_PLUGIN) && COMPILE_PLUGIN
#   define PLUGIN_INTERFACE EXPORT
#else
#   define PLUGIN_INTERFACE IMPORT
#endif

#include <memory>
#include "game_character.hpp"

/// @brief function signature for plugin creation
/// @return pointer to GameCharacter (plugin interface)
extern "C" PLUGIN_INTERFACE std::unique_ptr<GameCharacter> create();
