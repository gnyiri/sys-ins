#ifndef TIME_SERIES_RENDERER_H
#define TIME_SERIES_RENDERER_H

#include "time_series.h"

#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>

#include <vector>

class time_series_renderer
{
public:
  /*!
   * \brief time_series_renderer
   */
  time_series_renderer();
  /*!
   * \brief time_series_renderer
   */
  time_series_renderer(const float p_x_min, const float p_x_max, const float p_y_min, const float p_y_max);
  /*!
   * \brief add
   * \param p_time_series
   */
  void add(const time_series& p_time_series);
  /*!
   * \brief get_size
   * \param
   */
  unsigned long get_size();
  /*!
   * \brief init_render
   */
  void init_render();
  /*!
   * \brief render
   */
  void render();
private:
  /*!
   * \brief m_extent
   */
  float m_extent[4];
  /*!
   * \brief m_time_series
   */
  std::vector<time_series> m_time_series;
  /*!
   * \brief m_obuf
   */
  QOpenGLBuffer m_obuf;
};

#endif // TIME_SERIES_RENDERER_H
