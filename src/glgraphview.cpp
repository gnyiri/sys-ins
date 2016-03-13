#include "glgraphview.h"

#include <QMouseEvent>
#include <QOpenGLShaderProgram>
#include <QCoreApplication>

static const char* vertexShaderSourceCore =
    "#version 150\n"
    "in vec4 vertex;\n"
    "in vec3 normal;\n"
    "out vec3 vert;\n"
    "out vec3 vertNormal;\n"
    "uniform mat4 projMatrix;\n"
    "uniform mat4 mvMatrix;\n"
    "uniform mat3 normalMatrix;\n"
    "void main() {\n"
    "   vert = vertex.xyz;\n"
    "   vertNormal = normalMatrix * normal;\n"
    "   gl_Position = projMatrix * mvMatrix * vertex;\n"
    "}\n";

static const char* fragmentShaderSourceCore =
    "#version 150\n"
    "in highp vec3 vert;\n"
    "in highp vec3 vertNormal;\n"
    "out highp vec4 fragColor;\n"
    "uniform highp vec3 lightPos;\n"
    "void main() {\n"
    "   highp vec3 L = normalize(lightPos - vert);\n"
    "   highp float NL = max(dot(normalize(vertNormal), L), 0.0);\n"
    "   highp vec3 color = vec3(0.39, 1.0, 0.0);\n"
    "   highp vec3 col = clamp(color * 0.2 + color * 0.8 * NL, 0.0, 1.0);\n"
    "   fragColor = vec4(col, 1.0);\n"
    "}\n";

static const char* vertexShaderSource =
    "attribute vec4 vertex;\n"
    "attribute vec3 normal;\n"
    "varying vec3 vert;\n"
    "varying vec3 vertNormal;\n"
    "uniform mat4 projMatrix;\n"
    "uniform mat4 mvMatrix;\n"
    "uniform mat3 normalMatrix;\n"
    "void main() {\n"
    "   vert = vertex.xyz;\n"
    "   vertNormal = normalMatrix * normal;\n"
    "   gl_Position = projMatrix * mvMatrix * vertex;\n"
    "}\n";

static const char* fragmentShaderSource =
    "varying highp vec3 vert;\n"
    "varying highp vec3 vertNormal;\n"
    "uniform highp vec3 lightPos;\n"
    "void main() {\n"
    "   highp vec3 L = normalize(lightPos - vert);\n"
    "   highp float NL = max(dot(normalize(vertNormal), L), 0.0);\n"
    "   highp vec3 color = vec3(0.39, 1.0, 0.0);\n"
    "   highp vec3 col = clamp(color * 0.2 + color * 0.8 * NL, 0.0, 1.0);\n"
    "   gl_FragColor = vec4(col, 1.0);\n"
    "}\n";


//--------------------------------------------------
glgraphview::glgraphview(QWidget* p_parent) :
  QOpenGLWidget(p_parent),
  m_program(0)
{
  m_core = QCoreApplication::arguments().contains(QStringLiteral("--coreprofile"));
}
//--------------------------------------------------
glgraphview::~glgraphview()
{
  cleanup();
}
//--------------------------------------------------
void glgraphview::cleanup()
{
  makeCurrent();
  delete m_program;
  m_program = 0;
  doneCurrent();
}
//--------------------------------------------------
QSize glgraphview::minimumSizeHint() const
{
  return QSize(50, 50);
}
//--------------------------------------------------
QSize glgraphview::sizeHint() const
{
  return QSize(400, 400);
}
//--------------------------------------------------
void glgraphview::initializeGL()
{
  connect(context(), &QOpenGLContext::aboutToBeDestroyed, this, &glgraphview::cleanup);

  initializeOpenGLFunctions();
  glClearColor(0, 0, 0, 1);

  m_program = new QOpenGLShaderProgram;
  m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, m_core ? vertexShaderSourceCore : vertexShaderSource);
  m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, m_core ? fragmentShaderSourceCore : fragmentShaderSource);
  m_program->bindAttributeLocation("vertex", 0);
  m_program->bindAttributeLocation("normal", 1);
  m_program->link();
  m_program->bind();

  m_projMatrixLoc = m_program->uniformLocation("projMatrix");
  m_mvMatrixLoc = m_program->uniformLocation("mvMatrix");
  m_normalMatrixLoc = m_program->uniformLocation("normalMatrix");
  m_lightPosLoc = m_program->uniformLocation("lightPos");

  m_vao.create();
  QOpenGLVertexArrayObject::Binder vaoBinder(&m_vao);

  setupVertexAttribs();

  m_camera.setToIdentity();
  m_camera.translate(0, 0, -1);

  m_program->setUniformValue(m_lightPosLoc, QVector3D(0, 0, 70));

  m_program->release();
}
//--------------------------------------------------
void glgraphview::setupVertexAttribs()
{
  m_logoVbo.bind();
  QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
  f->glEnableVertexAttribArray(0);
  f->glEnableVertexAttribArray(1);
  f->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), 0);
  f->glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), reinterpret_cast<void *>(3 * sizeof(GLfloat)));
  m_logoVbo.release();
}
//--------------------------------------------------
void glgraphview::paintGL()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  m_world.setToIdentity();

  QOpenGLVertexArrayObject::Binder vaoBinder(&m_vao);
  m_program->bind();
  m_program->setUniformValue(m_projMatrixLoc, m_proj);
  m_program->setUniformValue(m_mvMatrixLoc, m_camera * m_world);
  QMatrix3x3 normalMatrix = m_world.normalMatrix();
  m_program->setUniformValue(m_normalMatrixLoc, normalMatrix);

  m_program->release();
}
//--------------------------------------------------
void glgraphview::resizeGL(int w, int h)
{
  m_proj.setToIdentity();
  m_proj.perspective(45.0f, GLfloat(w) / h, 0.01f, 100.0f);
}
