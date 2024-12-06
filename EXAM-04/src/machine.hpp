#ifndef MACHINE_HPP
#define MACHINE_HPP

#include <string>
#include <sstream>
#include <iostream>

class Machine {
    std::string name;
    int memoryUsage;
    int cpuUsage;

    public:
        Machine(): name(""), memoryUsage(0), cpuUsage(0){}
        Machine(std::string n, int m, int c);
        

        const std::string& getName() const { return name; }
        const int& getMemoryUsage() const { return memoryUsage; }
        const int& getCpuUsage() const { return cpuUsage; }  


        friend std::ostream& operator<<(std::ostream& oss, const Machine& m);
        
        virtual ~Machine(){}     
}; 


#endif //MACHINE_HPP



