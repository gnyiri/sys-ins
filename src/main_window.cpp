#include "main_window.h"
#include "ui_main_window.h"

#include "sys_utils.h"

#include <sstream>

//--------------------------------------------------
main_window::main_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::main_window)
{
  ui->setupUi(this);

  m_process_id_model = new QStringListModel(this);

  ui->m_process_view->setModel(m_process_id_model);

  m_process_id_model->setStringList(m_process_id_list);

  update_process_id_model();
}
//--------------------------------------------------
main_window::~main_window()
{
  delete m_process_id_model;
  delete ui;
}
//--------------------------------------------------
void main_window::update_process_id_model()
{
  std::vector<int> l_process_ids = sys_utils::get_instance().get_process_ids();

  for (std::vector<int>::const_iterator l_pid = l_process_ids.begin(); l_pid != l_process_ids.end(); l_pid++)
  {
    std::stringstream l_string_stream;
    l_string_stream << *l_pid;

    m_process_id_list << l_string_stream.str().c_str();
  }

  m_process_id_model->setStringList(m_process_id_list);
}
