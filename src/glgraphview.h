#ifndef GLGRAPHVIEW_H
#define GLGRAPHVIEW_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QMatrix4x4>

#include <vector>

#include "time_series_renderer.h"

QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)

/*!
 * \brief The glgraphview class
 */
class glgraphview : public QOpenGLWidget, protected QOpenGLFunctions
{
  Q_OBJECT
public:
  /*!
   * \brief glgraphview
   * \param parent
   * \param f
   */
  glgraphview(QWidget* p_parent = 0);
  /*!
    * \brief DTOR
    */
  ~glgraphview();
  /*!
   * \brief
   */
  QSize minimumSizeHint() const Q_DECL_OVERRIDE;
  /*!
   * \brief
   */
  QSize sizeHint() const Q_DECL_OVERRIDE;
  /*!
   * \brief
   */
  void cleanup();
protected:
  /*!
   * \brief
   */
  void initializeGL() Q_DECL_OVERRIDE;
  /*!
   * \brief
   */
  void paintGL() Q_DECL_OVERRIDE;
  /*!
   * \brief
   */
  void resizeGL(int width, int height) Q_DECL_OVERRIDE;

private:
  /*!
   * \brief
   */
  void setupVertexAttribs();
  /*!
   * \brief
   * the shader program
   */
  QOpenGLShaderProgram* m_program;
  /*!
   * \brief
   */
  bool m_core;
  /*!
   * \brief
   */
  int m_projMatrixLoc;
  /*!
   * \brief
   */
  int m_mvMatrixLoc;
  /*!
   * \brief
   */
  int m_normalMatrixLoc;
  /*!
   * \brief
   */
  int m_lightPosLoc;
  /*!
   * \brief
   */
  QOpenGLVertexArrayObject m_vao;
  /*!
   * \brief m_obuf
   * GPU dynamic memory handle
   */
  QOpenGLBuffer m_obuf;
  /*!
   * \brief
   */
  QMatrix4x4 m_proj;
  /*!
   * \brief
   */
  QMatrix4x4 m_camera;
  /*!
   * \brief
   */
  QMatrix4x4 m_world;
  /*!
   * \brief m_time_series_renderer
   */
  time_series_renderer m_time_series_renderer;
};

#endif // GLGRAPHVIEW_H
