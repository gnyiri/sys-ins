#include <QString>
#include <QtTest>

#include "sys_utils.h"

class sys_utils_test : public QObject
{
  Q_OBJECT

public:
  sys_utils_test();

private Q_SLOTS:
  void testCase1();
};

sys_utils_test::sys_utils_test()
{
}

void sys_utils_test::testCase1()
{
  QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(sys_utils_test)

#include "tst_sys_utils_test.moc"
