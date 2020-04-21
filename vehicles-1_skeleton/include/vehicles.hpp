#ifndef VEHICLES_HPP_
#define VEHICLES_HPP_

#include <cstddef>
#include <vector>
#include <iostream>
#include <string>
#include <functional>

//CLASSES

class Vehicle{
public:
    Vehicle(std::string id, std::string brand) : _id(id), _brand(brand){};
    std::string getId() const {return _id;}
    std::string getBrand() const {return _brand;}
    virtual double getMaxSpeed() const = 0;
    virtual ~Vehicle() = default;
private:
    std::string _id;
    std::string _brand;
};

class Car : public Vehicle{
public:
    Car(std::string id, std::string brand, double engineHP) : Vehicle(id, brand), _engineHP(engineHP) {}
    double getMaxSpeed() const override {return _engineHP;}
private:
    double _engineHP;
};

class Bike : public Vehicle{
public:
    Bike(std::string id, std::string brand, int nGears) : Vehicle(id,brand), _nGears(nGears) {}
    double getMaxSpeed() const override {return 3*_nGears;}
private:
    int _nGears;
};

//FUNCTIONS

std::string to_string(const Vehicle& v);
std::string to_string(std::vector<Vehicle*>::const_iterator vehicles_begin,
    std::vector<Vehicle*>::const_iterator vehicles_end);

double compute_min_travel_duration(const double distance,const Vehicle& vehicle);

std::string compute_min_travel_duration_as_string(const double distance,const Vehicle& vehicle);

std::vector<Vehicle*> filter_vehicles(
    std::vector<Vehicle*>::const_iterator vehicles_begin,
    std::vector<Vehicle*>::const_iterator vehicles_end,
    std::function<bool (const Vehicle&)> predicate);

#endif /* VEHICLES_HPP_ */
