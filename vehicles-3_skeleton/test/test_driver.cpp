#include "gtest/gtest.h"

#include "vehicles.hpp"

TEST(DriverTest, toStringNoVehicle) {
    Driver owner("Adam Abacki");

    std::string str = to_string(owner);

    ASSERT_EQ(str, "Adam Abacki : [no vehicle]");
}

TEST(DriverTest, toStringWithVehicle) {
    Driver owner("Adam Abacki", std::make_unique<Car>("C1", "Lexus", 500.0));

    std::string str = to_string(owner);

    std::string vehicle_str = to_string(*(owner.getVehicle()));
    ASSERT_EQ(str, "Adam Abacki : ["+ vehicle_str +"]");
}

TEST(DriverAuxTest, assignVehicleToDriver) {
    std::vector<std::unique_ptr<Vehicle>> vehicles;
    vehicles.push_back(std::make_unique<Car>("C1", "Lexus", 300));
    vehicles.push_back(std::make_unique<Bicycle>("B1", "Unibike", 8));
    vehicles.push_back(std::make_unique<Car>("C2", "Honda", 200));

    Driver owner("");
    assign_vehicle_to_driver(vehicles, owner);

    ASSERT_EQ(vehicles.size(), 2U);
    EXPECT_EQ(vehicles[0]->getId(), "C1");
    EXPECT_EQ(vehicles[1]->getId(), "B1");

    EXPECT_EQ((owner.getVehicle())->getId(), "C2");
}

TEST(DriverAuxTest, copying) {
    Driver driver1("Adam Abacki", std::make_unique<Car>("C1", "Lexus", 500.0));

    Driver driver2(driver1);

    EXPECT_EQ(driver1.getVehicle(), nullptr);
    EXPECT_EQ((driver2.getVehicle())->getId(), "C1");
}

TEST(DriverAuxTest, assignment) {
    Driver driver1("Adam Abacki", std::make_unique<Car>("C1", "Lexus", 500.0));
    Driver driver2("Bogdan Babacki");

    driver2 = driver1;

    EXPECT_EQ(driver1.getVehicle(), nullptr);
    EXPECT_EQ((driver2.getVehicle())->getId(), "C1");
}
