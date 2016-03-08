#include "proc_parser.h"

#include "utils.h"

#include <fstream>
#include <sstream>

//--------------------------------------------------
proc_parser::proc_parser(const int p_pid) :
  m_pid(p_pid)
{
}
//--------------------------------------------------
template<typename T>
T proc_parser::parse_section(const std::string& p_section)
{
  if (p_section.empty())
  {
    throw sys_exception("Empty section");
  }


  std::stringstream l_pid_file_path;
  l_pid_file_path << std::string("/proc/") << m_pid;

  std::ifstream l_file;
  l_file.open("/proc/");
}

