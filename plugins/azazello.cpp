#include "plugin_interface.hpp"

#include <iostream>

/// @brief Azazello character that says azaza
class Azazello : public GameCharacter {
 public:
  void make_a_noise() override {
    std::cout << "azaza" << std::endl;
  }
};

std::unique_ptr<GameCharacter> create() {
  return std::make_unique<Azazello>();
}
