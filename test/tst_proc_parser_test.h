#ifndef TST_PROC_PARSER_TEST_H
#define TST_PROC_PARSER_TEST_H

#include "proc_parser.h"

#include <QString>
#include <QtTest>
#include <QDebug>

/*!
 * \brief The proc_parser_test class
 */
class tst_proc_parser_test : public QObject
{
  Q_OBJECT

public:
  tst_proc_parser_test()
  {
  }

private Q_SLOTS:
  void test_parse_section();
};
#endif // TST_PROC_PARSER_TEST_H
