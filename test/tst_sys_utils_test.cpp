#include <QString>
#include <QtTest>

#include "sys_utils.h"

class sys_utils_test : public QObject
{
  Q_OBJECT

public:
  sys_utils_test();

private Q_SLOTS:
  void test_process_ids();
};
//--------------------------------------------------------------
sys_utils_test::sys_utils_test()
{
}
//--------------------------------------------------------------
void sys_utils_test::test_process_ids()
{
  QVERIFY(false == sys_utils::get_instance().get_process_ids().empty());
}

QTEST_APPLESS_MAIN(sys_utils_test)

#include "tst_sys_utils_test.moc"
