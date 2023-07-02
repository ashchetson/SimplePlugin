#include <iostream>

#include "plugin_interface.hpp"

class Behemoth : public GameCharacter {
 public:
  void make_a_noise() override {
    std::cout << "meowww" << std::endl;
  }
};

std::unique_ptr<GameCharacter> create() {
  return std::make_unique<Behemoth>();
}
