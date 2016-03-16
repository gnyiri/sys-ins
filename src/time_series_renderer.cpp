#include "time_series_renderer.h"

#include <QOpenGLFunctions>

//--------------------------------------------------
time_series_renderer::time_series_renderer()
{
  m_extent[0] = -1.0;
  m_extent[1] = 1.0;
  m_extent[2] = -1.0;
  m_extent[3] = 1.0;

  m_time_series.clear();
}
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
}
//--------------------------------------------------
unsigned long time_series_renderer::get_size()
{
  unsigned long l_size = 0ul;

  for (unsigned int l_i = 0; l_i < m_time_series.size(); l_i++)
  {
    time_series& l_time_series = m_time_series[l_i];
    l_size += l_time_series.get_size();
  }

  return l_size;
}
//--------------------------------------------------
void time_series_renderer::init_render()
{
  unsigned long l_size = get_size();

  m_obuf.destroy();
  m_obuf.allocate(l_size * 3 * sizeof(GLfloat));
  m_obuf.bind();

  unsigned long l_offset = 0ul;

  for (unsigned int l_i = 0; l_i < m_time_series.size(); l_i++)
  {
    time_series& l_time_series = m_time_series[l_i];

    std::vector<GLfloat> l_vertex_buffer;

    for (unsigned int l_v = 0; l_v < l_time_series.get_size(); l_v++)
    {
      GLfloat l_x = l_v * (2.0 / l_time_series.get_size()) - 1.0;
      GLfloat l_y = l_time_series.get(l_v);
      GLfloat l_z = 1.0;

      l_vertex_buffer.push_back(l_x);
      l_vertex_buffer.push_back(l_y);
      l_vertex_buffer.push_back(l_z);
    }

    m_obuf.write(l_offset, l_vertex_buffer.data(), l_vertex_buffer.size() * sizeof(GLfloat));
    l_offset += l_vertex_buffer.size() * sizeof(GLfloat);
  }

  QOpenGLFunctions* f = QOpenGLContext::currentContext()->functions();
  f->glEnableVertexAttribArray(0);
  f->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);
  m_obuf.release();
}
//--------------------------------------------------
void time_series_renderer::render()
{
  glDrawArrays(GL_LINES, 0, get_size());
}

