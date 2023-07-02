#pragma once

#include <memory>
#include <string>

#include "game_character.hpp"

/// @brief Helper class for load/unload library and provide interface to plugin
class PluginHolder : public GameCharacter {
 public:
  /// @brief loads library and creates GameCharacter
  /// @param lib_path path to plugin
  /// @throw std::runtime_error
  explicit PluginHolder(const std::string& lib_path);
  /// @brief call make_a_noise function from plugin
  void make_a_noise() override;

 private:
  std::shared_ptr<void> load_lib(const std::string& lib_path);
  std::unique_ptr<GameCharacter> create_impl();

  std::shared_ptr<void> m_lib_handle;
  /// plugin implementation
  std::unique_ptr<GameCharacter> m_impl;
};
