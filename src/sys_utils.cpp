#include "sys_utils.h"

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
