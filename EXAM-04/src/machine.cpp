#include <machine.hpp>

Machine::Machine(std::string n, int m, int c){
    name = n;
    memoryUsage = m;
    cpuUsage = c;
} 

std::ostream& operator<<(std::ostream& oss, const Machine& m){
    oss << "Machine: " << m.name << ", Memory Usage: " << std::to_string(m.memoryUsage) << " MB, CPU Usage: " << std::to_string(m.cpuUsage) << "%";
    return oss;
}
