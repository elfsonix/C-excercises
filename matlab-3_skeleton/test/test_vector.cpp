#include "gtest/gtest.h"

#include "matlab.hpp"

TEST(MatlabVectorTest, createWithSize) {
    MatVect v(2U);

    ASSERT_EQ(v.size(), 2U);
    EXPECT_EQ(v[0], 0);
    EXPECT_EQ(v[1], 0);
}

TEST(MatlabVectorTest, createFromVector) {
    std::vector<int> vs{ 1, 2 };
    MatVect v(vs);

    ASSERT_EQ(v.size(), 2U);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
}

TEST(MatlabVectorTest, add) {
    MatVect v1(std::vector<int> { 1, 2 });
    MatVect v2(std::vector<int> { 4, 5 });

    MatVect v_sum = add_vectors(v1, v2);

    ASSERT_EQ(v_sum.size(), 2U);
    EXPECT_EQ(v_sum[0], 5);
    EXPECT_EQ(v_sum[1], 7);
}

TEST(MatlabVectorTest, to_string) {
    std::vector<int> v0{ 1, 2, 3 };
    MatVect v(v0);
    std::string vs=to_string(v);

    ASSERT_EQ(v.size(), 3U);
    EXPECT_EQ(vs, "1 2 3 ");
}
