#include <iostream>

#include "plugin_interface.hpp"

class Korovyev : public GameCharacter {
 public:
  void make_a_noise() {
    std::cout << "hahaha" << std::endl;
  }
};

std::unique_ptr<GameCharacter> create() {
  return std::make_unique<Korovyev>();
}
