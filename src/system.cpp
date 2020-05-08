#include "system.h"

#include <unistd.h>

#include <algorithm>
#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "format.h"
#include "linux_parser.h"
#include "process.h"
#include "processor.h"
using std::set;
using std::size_t;
using std::string;
using std::vector;

Processor& System::Cpu() {
  //  Return the system's CPU
  return cpu_;
}

// Return a container composed of the system's processes
vector<Process>& System::Processes() {
  vector<int> pids = LinuxParser::Pids();
  processes_.clear();
  for (long unsigned int i = 0; i < pids.size(); i++) {
    if (!LinuxParser::Ram(pids[i]).empty()) {
      Process process(pids[i]);
      processes_.push_back(process);
    }
  }
  // std::sort(processes_.begin(), processes_.end(),
  //           [](const Process& a, const Process& b) -> bool {
  //             return a.getRam() < b.getRam();
  //           });  
  std::sort(processes_.rbegin(), processes_.rend());
  return processes_;
}

std::string System::Kernel() {
  // Return the system's kernel identifier
  return LinuxParser::Kernel();
}

float System::MemoryUtilization() {
  // Return the system's memory utilization
  return LinuxParser::MemoryUtilization();
}

std::string System::OperatingSystem() {
  // Return the operating system name
  return LinuxParser::OperatingSystem();
}

int System::RunningProcesses() {
  // Return the number of processes actively running on the system
  return LinuxParser::RunningProcesses();
}

int System::TotalProcesses() {
  // Return the total number of processes on the system
  return LinuxParser::TotalProcesses();
}

long int System::UpTime() {
  // Return the number of seconds since the system started running
  long uptime = LinuxParser::UpTime();
  return uptime;
}