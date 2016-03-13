#ifndef GLGRAPHVIEW_H
#define GLGRAPHVIEW_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QMatrix4x4>

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
  QSize minimumSizeHint() const Q_DECL_OVERRIDE;
  QSize sizeHint() const Q_DECL_OVERRIDE;
  void cleanup();

protected:
  void initializeGL() Q_DECL_OVERRIDE;
  void paintGL() Q_DECL_OVERRIDE;
  void resizeGL(int width, int height) Q_DECL_OVERRIDE;

private:
  void setupVertexAttribs();
  bool m_core;
  int m_projMatrixLoc;
  int m_mvMatrixLoc;
  int m_normalMatrixLoc;
  int m_lightPosLoc;

  QOpenGLVertexArrayObject m_vao;
  QOpenGLShaderProgram* m_program;
  QOpenGLBuffer m_logoVbo;

  QMatrix4x4 m_proj;
  QMatrix4x4 m_camera;
  QMatrix4x4 m_world;
};

#endif // GLGRAPHVIEW_H
