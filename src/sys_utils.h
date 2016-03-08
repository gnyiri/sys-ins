#ifndef SYS_UTILS_H
#define SYS_UTILS_H

#include <vector>
#include <string>

/*!
 * \brief The proc_info struct
 */
struct proc_info
{
  int m_pid;
  std::string m_name;
};

/*!
 * \brief The sys_utils class
 */
class sys_utils
{
public:
  /*!
   * \brief get_instance
   * \return the only instance
   */
  static sys_utils& get_instance();
  /*!
   * \brief get_process_ids
   * \return list of process id-s
   */
  std::vector<int>& get_process_ids();
  /*!
   * \brief get_process_info
   * \param p_pid
   * \return process info
   */
  proc_info get_process_info(const int p_pid);
private:
  /*!
   * \brief sys_utils CTOR
   */
  sys_utils();
  /*!
   * \brief ~sys_utils DTOR
   */
  virtual ~sys_utils();
  /*!
   * \brief m_process_ids
   */
  std::vector<int> m_process_ids;
};

#endif // SYS_UTILS_H
