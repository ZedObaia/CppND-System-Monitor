#include "processor.h"

#include "linux_parser.h"

float Processor::Utilization() {
  // Return the aggregate CPU utilization
  long total_old, total_new, active_new, idle_old, idle_new;
  total_new = CurrentTotal();
  active_new = CurrentActive();
  idle_new = CurrentIdle();

  total_old = PrevTotal();
  idle_old = PrevIdle();

  Update(idle_new, active_new, total_new);

  float totalDelta = float(total_new) - float(total_old);
  float idleDetla = float(idle_new) - float(idle_old);

  float utilization = (totalDelta - idleDetla) / totalDelta;
  return utilization;
}

long Processor::CurrentTotal() { return LinuxParser::Jiffies(); }
long Processor::CurrentActive() { return LinuxParser::ActiveJiffies(); }
long Processor::CurrentIdle() { return LinuxParser::IdleJiffies(); }

long Processor::PrevTotal() { return m_total; }
long Processor::PrevActive() { return m_active; }
long Processor::PrevIdle() { return m_idle; }
void Processor::Update(long idle, long active, long total) {
  m_idle = idle;
  m_active = active;
  m_total = total;
}
