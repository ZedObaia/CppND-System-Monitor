#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization();
  long CurrentTotal();
  long CurrentActive();
  long CurrentIdle();

  long PrevTotal();
  long PrevIdle();
  long PrevActive();
  void Update(long idle, long active, long total);

 private:
  long m_idle;
  long m_active;
  long m_total;
};

#endif