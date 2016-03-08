#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QStringListModel>

namespace Ui {
class main_window;
}

class main_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit main_window(QWidget *parent = 0);
    ~main_window();

private:
    Ui::main_window *ui;
    QStringListModel* m_process_id_model;
    QStringList m_process_id_list;
};

#endif // MAIN_WINDOW_H
