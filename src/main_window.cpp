#include "main_window.h"
#include "ui_main_window.h"

#include "sys_utils.h"
#include "proc_parser.h"
#include <sstream>

#include <QDebug>

//--------------------------------------------------
main_window::main_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::main_window)
{
  ui->setupUi(this);
  m_process_id_model = new QStringListModel(this);
  ui->m_process_view->setModel(m_process_id_model);
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
//--------------------------------------------------
void main_window::on_m_process_view_clicked(const QModelIndex &index)
{
  QString l_pid_str = m_process_id_list.at(index.row());

  int l_pid = l_pid_str.toInt();

  proc_parser l_proc_parser(l_pid);

  QString l_proc_details = l_proc_parser.to_string().c_str();

  ui->m_process_details->setText(l_proc_details);
}
