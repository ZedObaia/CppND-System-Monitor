#include "system.h"

#include <unistd.h>

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

// TODO: Return a container composed of the system's processes
vector<Process>& System::Processes() { return processes_; }

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

// TODO: Return the number of seconds since the system started running
long int System::UpTime() {
  long uptime = LinuxParser::UpTime();
  return uptime;
}