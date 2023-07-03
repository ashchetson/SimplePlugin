#include <iostream>
#include <regex>
#include <map>

#include "plugin_library/plugin_holder.hpp"

namespace fs = std::filesystem;

int main() {
  std::map<std::string, PluginHolder> holders;
  std::regex regex{".*\\.so"};
  
  for (const auto & entry : fs::directory_iterator("plugins")) {
    const auto& path{entry.path()};

    if (std::regex_search(path.c_str(), regex)) {
      try {
        // load plugins
        holders.emplace(path.c_str(), path);
      }
      catch (std::exception& e) {
        std::cout << path << " returned " << e.what() << std::endl;
      }
    }
  }

  for (auto& holder : holders) {
    // run function from plugin
    std::cout << holder.first << " says ";
    holder.second.make_a_noise();
  }
  
  return 0;
}
