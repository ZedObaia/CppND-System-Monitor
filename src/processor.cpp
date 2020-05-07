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

  long totalDelta = total_new - total_old;
  long idleDetla = idle_new - idle_old;

  float utilization = (totalDelta - idleDetla) / totalDelta;
  if (utilization > 0) return utilization;
  return 0;
}

long Processor::CurrentTotal() { return LinuxParser::ActiveJiffies(); }
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