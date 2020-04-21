#include "vehicles.hpp"

#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>

std::int64_t Vehicle::nextId = 1;

std::string to_string(const Vehicle& vehicle) {
    std::ostringstream oss;
    oss << vehicle.getId() << " :  " << vehicle.getBrand();
    return oss.str();
}

std::string to_string(std::vector<Vehicle*>::const_iterator vehicles_begin,
                      std::vector<Vehicle*>::const_iterator vehicles_end) {

    std::string s;
    for(auto it = vehicles_begin; it != vehicles_end; ++it) {
        const auto& vehicle = *(*it);
        s += to_string(vehicle);
        s += "\n";
    }

//  Wersja z użyciem biblioteki standardowej - mniej czytelna...
//  std::string s = std::accumulate(vehicles_begin, vehicles_end, std::string(),
//      [](std::string &s, const Vehicle* vehicle_ptr) -> std::string& {
//    return s += to_string(*vehicle_ptr); });

    return s;
}

double compute_min_travel_duration(double distance, const Vehicle& vehicle) {
    return distance / vehicle.getMaxSpeed();
}

std::string compute_min_travel_duration_as_string(double distance, const Vehicle& vehicle) {
    std::ostringstream oss;
    oss  << std::setprecision(3) << std::fixed
         << compute_min_travel_duration(distance, vehicle) << " h";
    return oss.str();
}

Driver& Driver::operator=(Driver& other) {
    _name = other._name;
    _vehicle_ptr = std::move(other._vehicle_ptr);

    return (*this);
}

std::vector<Vehicle*> filter_vehicles(
    std::vector<Vehicle*>::const_iterator vehicles_begin,
    std::vector<Vehicle*>::const_iterator vehicles_end,
    std::function<bool (const Vehicle&)> predicate) {

    std::vector<Vehicle*> vehicles_filtered;
    std::copy_if(vehicles_begin, vehicles_end, std::back_inserter(vehicles_filtered),
    [&predicate](const Vehicle * vehicle_ptr) { return predicate(*vehicle_ptr); });
    return vehicles_filtered;
}
std::string to_string(const Driver& driver){
    std::ostringstream oss;
    if(driver.getVehicle() !=nullptr){
        oss << driver.getName() << " : [" << to_string(*driver.getVehicle())<<"]";
    }
    else{
        oss << driver.getName() << " : [no vehicle]";
    }
    return oss.str();
}
void assign_vehicle_to_driver(std::vector<std::unique_ptr<Vehicle>>& vehicles, Driver& owner){
    if(vehicles.size()>0){
        auto it=vehicles.end()-1;
        owner.assignVehicle(std::move(*it));
        vehicles.erase(it);
    }
    else{
        owner.assignVehicle(nullptr);
    }
}
