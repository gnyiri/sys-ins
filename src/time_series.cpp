#include "time_series.h"
#include "limits"

#include "utils.h"

//--------------------------------------------------
time_series::time_series() :
  m_size(100u),
  m_position(0u),
  m_min(std::numeric_limits<unsigned int>::max()),
  m_max(std::numeric_limits<unsigned int>::min()),
  m_sum(0ul)
{
  m_data.resize(m_size, 0u);
}
//--------------------------------------------------
time_series::time_series(const unsigned int p_size) :
  m_size(p_size),
  m_position(0u),
  m_min(std::numeric_limits<unsigned int>::max()),
  m_max(std::numeric_limits<unsigned int>::min()),
  m_sum(0ul)
{
  if (0 == m_size)
  {
    throw sys_exception("Wrong size!");
  }

  m_data.resize(m_size, 0u);
}
//--------------------------------------------------
time_series::~time_series()
{
  m_data.clear();
}
//--------------------------------------------------
void time_series::add(const unsigned int p_time_data)
{
  if (m_size != m_data.size())
  {
    throw sys_exception("Size mismatch!");
  }

  if (m_position < m_size)
  {
    m_data[m_position++] = p_time_data;
    m_min = std::min(p_time_data, m_min);
    m_max = std::max(p_time_data, m_max);
    m_sum += p_time_data;
  }
  else
  {
    for (unsigned int l_i = 0; l_i < m_data.size() - 1; l_i++)
    {
      m_data[l_i] = m_data[l_i + 1];
    }

    m_data[m_data.size() - 1] = p_time_data;
  }
}
//--------------------------------------------------
unsigned int time_series::get(const unsigned int p_index) const
{
  if (p_index >= m_data.size())
  {
    throw sys_exception("Wrong index!");
  }

  return m_data[p_index];
}
//--------------------------------------------------
unsigned int time_series::get_size() const
{
  return m_data.size();
}
//--------------------------------------------------
unsigned int time_series::get_max() const
{
  return m_max;
}
//--------------------------------------------------
unsigned int time_series::get_min() const
{
  return m_min;
}
//--------------------------------------------------
unsigned int time_series::get_avg() const
{
  return static_cast<unsigned int>(m_sum / static_cast<float>(m_data.size()) + 0.5f);
}
//--------------------------------------------------
void* time_series::get_buff()
{
  return static_cast<void*>(m_data.data());
}


