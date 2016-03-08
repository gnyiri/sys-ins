#ifndef UTILS_HXX
#define UTILS_HXX

#include <stdexcept>
#include <iostream>

/*!
 * \brief The sys_exception class
 */
class sys_exception : public std::exception
{
public:
  /*!
   * \brief CTOR
   */
  explicit sys_exception(const std::string& p_what)
  {
    std::cout << "Exception! Details: " << p_what << std::endl;
  }
};

#endif // UTILS_HXX

