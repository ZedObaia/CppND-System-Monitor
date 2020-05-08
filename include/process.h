#ifndef PROCESS_H
#define PROCESS_H

#include <string>
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  Process(int pid);
  int Pid() const;
  std::string User() const;
  std::string Command() const;
  float CpuUtilization() const;
  std::string Ram() const;
  int getRam() const;
  long int UpTime() const;
  bool operator<(Process const& a) const;

 private:
  int m_pid;
  long m_ram;
  float m_utilization;
  long m_uptime;
  std::string m_command;
  std::string m_user;

};

#endif