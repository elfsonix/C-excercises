#ifndef VEHICLES_HPP_
#define VEHICLES_HPP_

#include <string>
#include <vector>
#include <functional>
#include <cstdint>
#include <memory>

class Vehicle {
public:
    Vehicle(std::string id, std::string brand) : _id(id), _brand(brand) {
        _vin = nextId++;
    }
    Vehicle(const Vehicle&) = default;
    std::int64_t getVIN() const { return _vin; }
    std::string getId() const { return _id; }
    std::string getBrand() const { return _brand; }
    virtual double getMaxSpeed() const = 0;
    virtual ~Vehicle() = default;
private:
    static std::int64_t nextId;
    std::int64_t _vin;
    std::string _id;
    std::string _brand;
};

std::string to_string(const Vehicle& vehicle);
std::string to_string(std::vector<Vehicle*>::const_iterator vehicles_begin,
                      std::vector<Vehicle*>::const_iterator vehicles_end);

class Car : public Vehicle {
public:
    Car(std::string id, std::string brand, double engineHP) : Vehicle(id, brand), _engineHP(engineHP) {}
    Car(const Car&) = default;
    double getMaxSpeed() const override { return _engineHP; }
private:
    double _engineHP;
};

class Bicycle : public Vehicle {
public:
    Bicycle(std::string id, std::string brand, int nGears) : Vehicle(id, brand), _nGears(nGears) {}
    Bicycle(const Bicycle&) = default;
    double getMaxSpeed() const override { return _nGears * 3; }
private:
    int _nGears;
};


class Driver {
public:
    Driver(std::string name) : Driver(name, nullptr) {}
    Driver(std::string name, std::unique_ptr<Vehicle> vehicle_ptr) : _name(name), _vehicle_ptr(std::move (vehicle_ptr)) {}
    Driver(Driver& other) : _name(other._name), _vehicle_ptr(std::move(other._vehicle_ptr)) {}
    Driver& operator=(Driver& other);

    void assignVehicle(std::unique_ptr<Vehicle> vehicle_ptr) { _vehicle_ptr = std::move(vehicle_ptr);}

    std::string getName() const {return _name;}
    const Vehicle* getVehicle() const {return _vehicle_ptr.get();}
private:
    std::string _name;
    std::unique_ptr<Vehicle> _vehicle_ptr;
};

void assign_vehicle_to_driver(std::vector<std::unique_ptr<Vehicle>>& vehicles, Driver& owner);

double compute_min_travel_duration(double distance, const Vehicle& vehicle);
std::string compute_min_travel_duration_as_string(double distance, const Vehicle& vehicle);

std::vector<Vehicle*> filter_vehicles(
    std::vector<Vehicle*>::const_iterator vehicles_begin,
    std::vector<Vehicle*>::const_iterator vehicles_end,
    std::function<bool (const Vehicle&)> predicate);

std::string to_string(const Driver& driver);


#endif /* VEHICLES_HPP_ */
