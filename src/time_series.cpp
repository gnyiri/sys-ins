#include "time_series.h"

#include "utils.h"

//--------------------------------------------------
time_series::time_series() :
  m_size(100u),
  m_position(0u)
{
  m_data.resize(m_size, 0u);
}
//--------------------------------------------------
time_series::time_series(const unsigned int p_size) :
  m_size(p_size)
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
unsigned int time_series::get_size() const
{
  return m_data.size();
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

