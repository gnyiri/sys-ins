#ifndef PROC_PARSER_H
#define PROC_PARSER_H

#include <string>

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
  template<typename T>
  T parse_section(const std::string& p_section);
private:
  /*!
   * \brief m_pid
   */
  int m_pid;
};

#endif // PROC_PARSER_H
