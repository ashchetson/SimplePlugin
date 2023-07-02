cmake_minimum_required (VERSION 3.22)

project(plugin)

set(CXX_STANDARD 20)

add_subdirectory(plugin_library)
add_subdirectory(plugins)

add_executable(sample main.cpp)
target_link_libraries(sample plugin_library)
