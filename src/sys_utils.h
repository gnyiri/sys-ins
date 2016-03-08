#ifndef SYS_UTILS_H
#define SYS_UTILS_H

#include <vector>

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
