include_directories(../plugin_library)

function(add_plugin name)
  add_library(${name} SHARED ${name}.cpp)
  target_compile_definitions(${name} PRIVATE COMPILE_PLUGIN)
endfunction()

add_plugin(azazello)
add_plugin(behemoth)
add_plugin(korovyev)
