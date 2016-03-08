#include "proc_parser.h"

#include "utils.h"

#include <fstream>
#include <sstream>

#include <QDebug>

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
  l_file.open(l_pid_file_path.str().c_str(), std::ios::in);

  if (!l_file.is_open())
  {
    throw sys_exception("Could not open process info file");
  }



  l_file.close();
}

