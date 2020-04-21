#include "gtest/gtest.h"

#include "vehicles.hpp"


TEST(CarTest, getMaxSpeed) {
    Car c("","",200.0);

    EXPECT_EQ(c.getMaxSpeed(), 200.0);
}

TEST(BikeTest, getMaxSpeed) {

    Bike b("","",6);

    EXPECT_EQ(b.getMaxSpeed(), 18);
}
TEST(VehicleTest, tostring) {

    Bike b("A","B",0);
    Car c("C","D",0);
    EXPECT_EQ(to_string(b), "A : B");
    EXPECT_EQ(to_string(c), "C : D");
}
TEST(VehicleAuxTest, computeMinTravelDuration) {

    Bike b("","",5);
    Car c("","",100);

    EXPECT_EQ(compute_min_travel_duration(150,b), 10);
    EXPECT_EQ(compute_min_travel_duration(200,c), 2);
    EXPECT_EQ(compute_min_travel_duration_as_string(37.5,b), "2.5 h");
    EXPECT_EQ(compute_min_travel_duration_as_string(150,c), "1.5 h");
}
TEST(VehiclesAlgorithms, filter) {
    Car car1("C1", "", 100.0);
    Car car2("C2", "", 200.0);
    Bike bicycle("B1", "", 0);

    std::vector<Vehicle*> vehicles = { &car1, &bicycle, &car2 };
    std::function<bool (const Vehicle&)> fasterThan50kph = [](const Vehicle & vehicle) {
        return vehicle.getMaxSpeed() > 50;
    };
    auto filtered_vehicles = filter_vehicles(vehicles.begin(), vehicles.end(), fasterThan50kph);

    ASSERT_EQ(filtered_vehicles.size(), 2U);
    EXPECT_NE(std::find_if(filtered_vehicles.begin(), filtered_vehicles.end(), [&car1](const auto & vehicle_ptr) {
        return (vehicle_ptr == &car1);
    }), filtered_vehicles.end());
    EXPECT_NE(std::find_if(filtered_vehicles.begin(), filtered_vehicles.end(), [&car2](const auto & vehicle_ptr) {
        return (vehicle_ptr == &car2);
    }), filtered_vehicles.end());
}
TEST(VehicleAuxTest, computeMinTravelDurationAsString) {
    Car car("", "", 100.0);
    Bike bike("", "", 8);

    double distance = 50;
    std::string result_car = compute_min_travel_duration_as_string(distance, car);
    std::string result_bicycle = compute_min_travel_duration_as_string(distance, bike);

    EXPECT_EQ(result_car, "0.5 h");
    EXPECT_EQ(result_bicycle, "2.08333 h");
}
