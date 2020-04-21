#include "gtest/gtest.h"

#include "catalogue.hpp"

TEST(ProductTest, create) {
    Product product("RB01", "Robot", 10.2);

    EXPECT_EQ(product.getId(), "RB01");
    EXPECT_EQ(product.getName(), "Robot");
    EXPECT_EQ(product.getPrice(), 10.2);
}
TEST(ProductTest, toString) {
    Product product("RB01", "Robot", 10.2);

    EXPECT_EQ(to_string(product), "Robot[RB01] : $10.20");
}
