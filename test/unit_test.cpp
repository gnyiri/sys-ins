#include <QString>
#include <QtTest>
#include <QDebug>

#include "sys_utils.h"
#include "proc_parser.h"
#include "time_series.h"

/*!
 * \brief The sys_utils_test class
 */
class sys_utils_test : public QObject
{
  Q_OBJECT

public:
  sys_utils_test()
  {
  }

private Q_SLOTS:
  void test_process_id_list();
};
/*!
 * \brief The proc_parser_test class
 */
class proc_parser_test : public QObject
{
  Q_OBJECT

public:
  proc_parser_test()
  {
  }

private Q_SLOTS:
  void test_parse_section();
};
/*!
 * \brief The time_series class
 */
class time_series_test : public QObject
{
  Q_OBJECT

public:
  time_series_test()
  {
  }

private Q_SLOTS:
  void test_time_series();
};

//--------------------------------------------------------------
void sys_utils_test::test_process_id_list()
{
  std::vector<int> l_process_ids = sys_utils::get_instance().get_process_ids();

  QCOMPARE(false, l_process_ids.empty());

  for (std::vector<int>::const_iterator l_pid = l_process_ids.begin(); l_pid != l_process_ids.end(); l_pid++)
  {
    QVERIFY(*l_pid > 0);
  }
}
//--------------------------------------------------------------
void proc_parser_test::test_parse_section()
{
  std::vector<int> l_process_ids = sys_utils::get_instance().get_process_ids();

  Q_ASSERT(!l_process_ids.empty());

  for (std::vector<int>::const_iterator l_pid = l_process_ids.begin(); l_pid != l_process_ids.end(); l_pid++)
  {
    try
    {
      proc_parser l_proc_parser(l_process_ids[*l_pid]);

      {
        const std::string l_section("WRONG_SECTION123");
        std::string l_value;

        if (0 == l_proc_parser.parse_section<std::string>(l_section, l_value))
        {
          QVERIFY(l_value.empty());
        }
      }

      {
        const std::string l_section("VmSize");
        std::string l_value;

        if(0 == l_proc_parser.parse_section<std::string>(l_section, l_value))
        {
          QVERIFY(!l_value.empty());
        }
      }
    }
    catch(sys_exception& e)
    {
      std::cout << e.what() << std::endl;
    }
  }
}
//--------------------------------------------------------------
void time_series_test::test_time_series()
{
  time_series l_time_series(200);
}
//--------------------------------------------------------------
int main(int argc, char** argv)
{
  int status = 0;

  {
    sys_utils_test l_test;
    status |= QTest::qExec(&l_test, argc, argv);
  }

  {
    proc_parser_test l_test;
    status |= QTest::qExec(&l_test, argc, argv);
  }

  {
    time_series_test l_test;
    status |= QTest::qExec(&l_test, argc, argv);
  }

  return status;
}

#include "tst_sys_utils_test.moc"