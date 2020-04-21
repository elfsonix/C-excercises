#include "vehicles.hpp"

#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>

std::string to_string(const Vehicle& v){

    std::ostringstream oss;

    oss<<v.getId()<<" : "<<v.getBrand();
    return oss.str();
}

std::string to_string(std::vector<Vehicle*>::const_iterator vehicles_begin,
    std::vector<Vehicle*>::const_iterator vehicles_end) {

  std::string s;
  for (auto it = vehicles_begin; it != vehicles_end; ++it) {
    const auto& vehicle = *(*it);
    s += to_string(vehicle);
    s += "\n";
  }
  return s;
}

double compute_min_travel_duration(const double distance,const Vehicle& vehicle){

    double time=distance/vehicle.getMaxSpeed();
    return time;
}
std::string compute_min_travel_duration_as_string(const double distance,const Vehicle& vehicle){

    double time=compute_min_travel_duration(distance, vehicle);
    std::ostringstream oss;
    oss<< time<< " h";
    return oss.str();
}
std::vector<Vehicle*> filter_vehicles(
    std::vector<Vehicle*>::const_iterator vehicles_begin,
    std::vector<Vehicle*>::const_iterator vehicles_end,
    std::function<bool (const Vehicle&)> predicate)
{
  std::vector<Vehicle*> vehicles_filtered;
  std::copy_if(vehicles_begin, vehicles_end, std::back_inserter(vehicles_filtered),
      [&predicate](const Vehicle* vehicle_ptr) { return predicate(*vehicle_ptr); });
  return vehicles_filtered;
}
