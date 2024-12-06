#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <string>
#include <iostream>
#include <map>

class Vehicle {
public:
    std::string name;
    int maxSpeed;

public:
    Vehicle() : name("Unknown"), maxSpeed(0) {}
    Vehicle(std::string n, int s) : name(n), maxSpeed(s) {}

    virtual void displayInfo() const {
        std::string infos = "Nom : " + name + " Max speed : " + std::to_string(maxSpeed) + "\n";
        std::cout << infos << std::endl;
    }

    Vehicle(Vehicle&& v) noexcept : name(std::move(v.name)), maxSpeed(v.maxSpeed) {
        v.maxSpeed = 0;
    }

    Vehicle(Vehicle& v): name(v.name), maxSpeed(v.maxSpeed) {}

    Vehicle& operator=(Vehicle&& v) noexcept {
        if (this != &v) { 
            name = std::move(v.name);
            maxSpeed = v.maxSpeed;
            v.maxSpeed = 0; 
        }
        return *this;
    }

    virtual ~Vehicle() {}
};

class Fuel {
public:
    int fuelLevel;

public:
    Fuel() : fuelLevel(0) {}
    Fuel(int f) : fuelLevel(f) {}
    
    const int& getFuelLevel() const { return fuelLevel; }

    void consume(int fuelConsumed) {
        if (fuelConsumed < fuelLevel) {
            fuelLevel -= fuelConsumed;
        }
    }

    void refuel(int fuel) {
        fuelLevel += fuel;
    }

    Fuel(Fuel&& f) noexcept : fuelLevel(f.fuelLevel) {
        f.fuelLevel = 0;  
    }

    Fuel& operator=(Fuel&& f) noexcept {
        if (this != &f) {
            fuelLevel = f.fuelLevel;
            f.fuelLevel = 0;
        }
        return *this;
    }

    virtual ~Fuel() {}
};

class Car : public Vehicle, public Fuel {
public:
    Car() : Vehicle(), Fuel() {}
    Car(std::string n, int s) : Vehicle(n, s), Fuel() {}
    Car(std::string n, int s, int f) : Vehicle(n, s), Fuel(f) {}

    Car(Car&& c) noexcept : Vehicle(std::move(c)), Fuel(std::move(c)) {}

    Car(Car& c) : Vehicle(c.name, c.maxSpeed), Fuel(c.fuelLevel) {}

    Car& operator=(Car&& c) noexcept {
        if (this != &c) {  
            Vehicle::operator=(std::move(c)); 
            Fuel::operator=(std::move(c));
        }
        return *this;
    }

    bool operator==(const Car& o) const
    {
        return o.name == name && o.maxSpeed == maxSpeed && o.fuelLevel == fuelLevel;
    }

    bool operator!=(const Car& o) const
    {
        return o.name != name || o.maxSpeed != maxSpeed || o.fuelLevel != fuelLevel;
    }
};

class Truck : public Vehicle, public Fuel {
public:
    Truck() : Vehicle(), Fuel() {}
    Truck(std::string n, int s) : Vehicle(n, s), Fuel() {}
    Truck(std::string n, int s, int f) : Vehicle(n, s), Fuel(f) {}

    Truck(Truck&& t) noexcept : Vehicle(std::move(t)), Fuel(std::move(t)) {}
    Truck(Truck& t) : Vehicle(t.name, t.maxSpeed), Fuel(t.fuelLevel) {}

    Truck& operator=(Truck&& t) noexcept {
        if (this != &t) {  
            Vehicle::operator=(std::move(t));
            Fuel::operator=(std::move(t));
        }
        return *this;
    }
};

bool operator<(const Car& c1, const Car& c2)
{
    return c1.maxSpeed < c2.maxSpeed;
}

bool operator<(const Truck& t1, const Truck& t2)
{
    return t1.maxSpeed < t2.maxSpeed;
}

template <typename T>
class Garage {
    std::multimap<std::string, std::string> vehicles;

    public:
        template <typename TV>
        void addVehicle(TV v)  {
            vehicles.emplace(typeid(TV).name(), "Unknown");      
        }

        void addVehicle(Car c)
        {
            vehicles.emplace(typeid(c).name(), c.name);
        }

        void addVehicle(Truck t)
        {
            vehicles.emplace(typeid(t).name(), t.name);
        }

        void display()
        {
           for (auto it : vehicles)
           {
                std::cout << "[" <<  it.first << "] :" << it.second << std::endl;
           }
        }
};


template <typename T>
void introspect(const T& obj) {
    std::cout << "Object is of type: " << typeid(obj).name() << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Car& car) {
    os 
       << "Vehicle Name: " << car.name << "\n"
       << "Max Speed: " << car.maxSpeed << " km/h\n"
       << "Fuel Level: " << car.fuelLevel << " L\n";
    return os;
}

#endif //VEHICLE_HPP
