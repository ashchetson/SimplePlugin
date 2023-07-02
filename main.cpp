#include <vector>
#include <iostream>
#include <filesystem>

#include "plugin_library/plugin_holder.hpp"

namespace fs = std::filesystem;

int main() {
  std::vector<PluginHolder> holders;
  
  for (const auto & entry : fs::directory_iterator("plugins")) {
    std::string s{entry.path()};
    
    if (s.find(".so") != std::string::npos) {
      try {
        // load plugins
        holders.emplace_back(s);
      }
      catch (std::exception& e) {
        std::cout << e.what() << std::endl;
      }
    }
  }

  for (auto& holder : holders) {
    // run function from plugin
    holder.make_a_noise();
  }
  
  return 0;
}
