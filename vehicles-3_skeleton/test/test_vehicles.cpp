#include "gtest/gtest.h"

#include "vehicles.hpp"

TEST(CarTest, getMaxSpeed) {
    Car car("", "", 100.0);

    EXPECT_EQ(car.getMaxSpeed(), 100.0);
}

TEST(BicycleTest, getMaxSpeed) {
    Bicycle bike("", "", 8);

    EXPECT_EQ(bike.getMaxSpeed(), 24);
}

TEST(VehicleTest, toString) {
    Car car("KR 00001", "Toyota", 100.0);

    std::string str = to_string(car);

    ASSERT_EQ(str, "KR 00001 :  Toyota");
}

TEST(VehicleAuxTest, computeMinTravelDuration) {
    Car car("", "", 100.0);
    Bicycle bike("", "", 8);

    double distance = 50;
    double result_car = compute_min_travel_duration(distance, car);
    double result_bicycle = compute_min_travel_duration(distance, bike);

    EXPECT_DOUBLE_EQ(result_car, distance / car.getMaxSpeed());
    EXPECT_DOUBLE_EQ(result_bicycle, distance / bike.getMaxSpeed());
}

TEST(VehicleAuxTest, computeMinTravelDurationAsString) {
    Car car("", "", 100.0);
    Bicycle bike("", "", 8);

    double distance = 50;
    std::string result_car = compute_min_travel_duration_as_string(distance, car);
    std::string result_bicycle = compute_min_travel_duration_as_string(distance, bike);

    EXPECT_EQ(result_car, "0.500 h");
    EXPECT_EQ(result_bicycle, "2.083 h");
}

// TODO: test fixture - zerowanie pola statycznego

TEST(VehicleAuxTest, filter) {
    Car car1("C1", "", 100.0);
    Car car2("C2", "", 200.0);
    Bicycle bicycle("B1", "", 0);

    std::vector<Vehicle*> vehicles = { &car1, &bicycle, &car2 };
    std::function<bool (const Vehicle&)> fasterThan50kph = [](const Vehicle & vehicle) {
        return vehicle.getMaxSpeed() > 50;
    };
    auto filtered_vehicles = filter_vehicles(vehicles.begin(), vehicles.end(), fasterThan50kph);

    ASSERT_EQ(filtered_vehicles.size(), 2U);
    // Nie wiemy, w jakiej kolejności produkty z mapy będą rozpatrywane, wiec nie możemy użyć indeksowania...
    EXPECT_NE(std::find_if(filtered_vehicles.begin(), filtered_vehicles.end(), [&car1](const auto & vehicle_ptr) {
        return (vehicle_ptr == &car1);
    }), filtered_vehicles.end());
    EXPECT_NE(std::find_if(filtered_vehicles.begin(), filtered_vehicles.end(), [&car2](const auto & vehicle_ptr) {
        return (vehicle_ptr == &car2);
    }), filtered_vehicles.end());
}
