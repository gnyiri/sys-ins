#include "tst_proc_parser_test.h"

#include "sys_utils.h"

//--------------------------------------------------------------
void tst_proc_parser_test::test_parse_section()
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
