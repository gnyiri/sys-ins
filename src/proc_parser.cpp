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
std::string proc_parser::to_string() const
{
  std::string l_str;

  std::stringstream l_pid_file_path;
  l_pid_file_path << std::string("/proc/") << m_pid << std::string("/status");

  std::ifstream l_file;
  l_file.open(l_pid_file_path.str().c_str(), std::ios::in);

  if (!l_file.is_open())
  {
    return l_str;
  }

  std::stringstream l_file_str;

  l_file_str << l_file.rdbuf();

  return l_file_str.str();
}
