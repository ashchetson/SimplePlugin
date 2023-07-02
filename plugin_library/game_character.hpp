#pragma once

/// @brief Game character that can make noise plugin interface
class GameCharacter {
 public:
  virtual void make_a_noise() = 0;
  virtual ~GameCharacter() = default;
};
