#include	"LibManager.hpp"

LibManager::LibManager(const std::string &p_path)
{
  if ((m_lib = dlopen(p_path.c_str(), RTLD_NOW)) == NULL)
    throw LibManager::Error(dlerror());
  m_window_creator = NULL;
}

IWindow		*LibManager::createWindow(size_t p_width, size_t p_height, const std::string &p_name, size_t ratio)
{
  if (m_window_creator == NULL)
    if ((m_window_creator = reinterpret_cast<IWindow *(*)(size_t, size_t, const std::string &, size_t)>
	 (dlsym(m_lib, "createWindow"))) == NULL)
      throw LibManager::Error(dlerror());
  return (m_window_creator(p_width, p_height, p_name, ratio));
}

LibManager::~LibManager()
{
  dlclose(m_lib);
}
