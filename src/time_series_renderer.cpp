#include "time_series_renderer.h"

//--------------------------------------------------
time_series_renderer::time_series_renderer(const float p_x_min, const float p_x_max, const float p_y_min, const float p_y_max)
{
  m_extent[0] = p_x_min;
  m_extent[1] = p_x_max;
  m_extent[2] = p_y_min;
  m_extent[3] = p_y_max;

  m_time_series.clear();
}
//--------------------------------------------------
void time_series_renderer::add(const time_series &p_time_series)
{
  m_time_series.push_back(p_time_series);

  unsigned long l_size = 0ul;

  for (unsigned int l_i = 0; l_i < m_time_series.size(); l_i++)
  {
    time_series& l_time_series = m_time_series[l_i];
    l_size += l_time_series.get_size() * 3 * sizeof(GLfloat);
  }

  m_obuf.destroy();
  m_obuf.allocate(l_size);
  m_obuf.bind();

  unsigned long l_offset = 0ul;
  GLfloat* l_vertex_buffer = new GLfloat[3 * l_size];

  for (unsigned int l_i = 0; l_i < m_time_series.size(); l_i++)
  {
    time_series& l_time_series = m_time_series[l_i];
    m_obuf.write(l_offset, l_vertex_buffer, l_time_series.get_size() * sizeof(GLfloat));
  }

  QOpenGLFunctions* f = QOpenGLContext::currentContext()->functions();
  f->glEnableVertexAttribArray(0);
  f->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);
  m_obuf.release();
}
//--------------------------------------------------
unsigned long time_series_renderer::get_size()
{
  unsigned long l_size = 0ul;

  for (unsigned int l_i = 0; l_i < m_time_series.size(); l_i++)
  {
    time_series& l_time_series = m_time_series[l_i];
    l_size += l_time_series.get_size() * 3 * sizeof(GLfloat);
  }

  return l_size;
}
//--------------------------------------------------
void time_series_renderer::init_render()
{

}
//--------------------------------------------------
void time_series_renderer::render()
{

}

