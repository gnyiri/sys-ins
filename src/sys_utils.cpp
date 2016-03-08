#include "sys_utils.h"
#include "utils.h"
#include "proc_parser.h"

#include <fts.h>
#include <sys/stat.h>
#include <algorithm>
#include <fstream>
#include <sstream>

#include <QDebug>

//--------------------------------------------------------------
sys_utils::sys_utils()
{
  m_process_ids.clear();
}
//--------------------------------------------------------------
sys_utils::~sys_utils()
{
  m_process_ids.clear();
}
//--------------------------------------------------------------
sys_utils& sys_utils::get_instance()
{
  static sys_utils _sys_utils;
  return _sys_utils;
}
//--------------------------------------------------------------
std::vector<int>& sys_utils::get_process_ids()
{
  m_process_ids.clear();

  char* l_paths[] = { "//proc//", 0 };

  FTS *l_file_tree = fts_open(l_paths, FTS_NOCHDIR, 0);

  if(0 == l_file_tree)
  {
    throw sys_exception("Could not open path");
  }

  FTSENT* l_node = 0;

  while((l_node = fts_read(l_file_tree)))
  {
    if ((l_node->fts_info & FTS_D) && (l_node->fts_level == 1))
    {
      qDebug() << l_node->fts_name;

      int l_process_id = 0;
      std::stringstream l_stream(l_node->fts_name);
      l_stream >> l_process_id;
      m_process_ids.push_back(l_process_id);
    }
  }

  if(fts_close(l_file_tree))
  {
    throw sys_exception("Could not close file");
  }

  return m_process_ids;
}
//--------------------------------------------------------------
proc_info sys_utils::get_process_info(const int p_pid)
{
  proc_info l_proc_info;

  if (p_pid <= 0)
  {
    throw sys_exception("Invalid process id");
  }

  l_proc_info.m_pid = p_pid;
}
