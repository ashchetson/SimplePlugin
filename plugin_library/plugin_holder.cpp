#include "plugin_holder.hpp"
#include "plugin_interface.hpp"

#include <dlfcn.h>
#include <stdexcept>

#define GET_FUNCTION_POINTER(lib_handle, name) reinterpret_cast<decltype(name)*>(dlsym(lib_handle, #name))

PluginHolder::PluginHolder(const fs::path& lib_path)
  : m_lib_handle{load_lib(lib_path)}
  , m_impl{create_impl()} {
}

void PluginHolder::make_a_noise() {
  m_impl->make_a_noise();
}

std::shared_ptr<void> PluginHolder::load_lib(const fs::path& lib_path) {
  auto handle = dlopen(lib_path.c_str(), RTLD_NOW);
    
  if (!handle) {
    throw std::runtime_error(dlerror());
  }

  return std::shared_ptr<void>(handle, dlclose);
}

std::unique_ptr<GameCharacter> PluginHolder::create_impl() {
  auto create_plugin = GET_FUNCTION_POINTER(m_lib_handle.get(), create);

  if (!create_plugin) {
    throw std::runtime_error(dlerror());
  }

  return create_plugin();
}

#undef GET_FUNCTION_POINTER
