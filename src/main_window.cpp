#include "main_window.h"
#include "ui_main_window.h"

main_window::main_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::main_window)
{
  ui->setupUi(this);

  m_process_id_model = new QStringListModel(this);
  m_process_id_list << "p1" << "p2";

  ui->m_process_view->setModel(m_process_id_model);

  m_process_id_model->setStringList(m_process_id_list);
}

main_window::~main_window()
{
  delete m_process_id_model;
  delete ui;
}
