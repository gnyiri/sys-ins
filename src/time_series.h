#ifndef TIME_SERIES_H
#define TIME_SERIES_H

#include <vector>

/*!
 * \brief The time_series class
 */
class time_series
{
public:
  /*!
   * \brief time_series
   */
  time_series();
  /*!
   * \brief time_series
   */
  time_series(const unsigned int p_size);
  /*!
   * \brief ~time_series
   */
  ~time_series();
  /*!
   * \brief add new element
   * \param p_time_data
   */
  void add(const unsigned int p_time_data);
  /*!
   * \brief get
   * \param p_index
   * \return
   */
  unsigned int get(const unsigned int p_index) const;
  /*!
   * \brief get size
   * \return size
   */
  unsigned int get_size() const;
private:
  /*!
   * \brief m_size
   */
  unsigned int m_size;
  /*!
   * \brief m_position
   */
  unsigned int m_position;
  /*!
   * \brief m_data
   */
  std::vector<unsigned int> m_data;
};

#endif // TIME_SERIES_H
