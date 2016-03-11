#include "proc_parser.h"

#include "utils.h"

#include <fstream>
#include <sstream>

#include <QDebug>

//--------------------------------------------------
proc_parser::proc_parser(const int p_pid) :
  m_pid(p_pid)
{
}
