#ifndef PROC_PARSER_H
#define PROC_PARSER_H

#include "utils.h"

#include <string>
#include <fstream>
#include <sstream>

/*!
 * \brief The proc_parser class
 */
class proc_parser
{
public:
  /*!
   * \brief proc_parser
   */
  proc_parser(const int p_pid);
  /*!
   * \brief parse_section
   */
  //--------------------------------------------------
  template <typename T>
  int parse_section(const std::string& p_section, T& p_value)
  {
    T l_value;

    if (p_section.empty())
    {
      throw sys_exception("Empty section");

      return 1;
    }


    std::stringstream l_pid_file_path;
    l_pid_file_path << std::string("/proc/") << m_pid << std::string("/status");

    std::ifstream l_file;
    l_file.open(l_pid_file_path.str().c_str(), std::ios::in);

    if (!l_file.is_open())
    {
      return 1;
    }

    std::string l_line;

    while(std::getline(l_file, l_line))
    {
      std::size_t l_found = l_line.find(p_section);

      if (std::string::npos != l_found)
      {
        std::stringstream l_line_ss(l_line);

        std::string l_section;
        l_line_ss >> l_section;
        l_line_ss >> l_value;

        break;
      }
    }

    p_value = l_value;

    l_file.close();

    return 0;
  }

private:
  /*!
   * \brief m_pid
   */
  int m_pid;
  /*!
   * \brief operator =
   * \param p_other
   * \return
   */
  proc_parser& operator=(proc_parser& p_other);
  /*!
   * \brief proc_parser
   * \param p_other
   */
  proc_parser(proc_parser& p_other);
};

#endif // PROC_PARSER_H
