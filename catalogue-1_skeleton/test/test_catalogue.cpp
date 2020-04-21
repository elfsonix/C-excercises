#include "gtest/gtest.h"

#include "catalogue.hpp"

TEST(CatalogueTest, containsKeyIsPresent) {
    Product p("a", "Robot", 250);
    Catalogue c;
    c.addProduct(p);
    EXPECT_TRUE(c.contains(p.getId()));
}
TEST(CatalogueTest, containsKeyIsNotPresent) {
    Product p("a", "Robot", 250);
    Catalogue c;
    EXPECT_FALSE(c.contains(p.getId()));
}
TEST(CatalogueTest, getProductsWithAppropriatePrice) {
    Product p1("X1", "Toy X1", 10.3);
    Product p2("X2", "Toy X2", 8.3);

    Catalogue catalogue(Catalogue::inventory_t{
        {p1.getId(), p1},
        {p2.getId(), p2},
    });

    std::function<bool (double)> predicate = [](double price) {
        return (price < 10.0);
    };
    auto filtered_products = catalogue.getProductsWithAppropriatePrice(predicate);

    ASSERT_EQ(filtered_products.size(), 1U);
    EXPECT_EQ(filtered_products[0].getId(), p2.getId());
}
TEST(CatalogueTest, getProductsByNamePartCaseSensitive) {
    Product p1("X1", "TOY uppercase", 10);
    Product p2("X2", "toy lowercase", 10);

    Catalogue catalogue(Catalogue::inventory_t{
        {p1.getId(), p1},
        {p2.getId(), p2},
    });

    auto filtered_products = catalogue.getProductsByNamePart("toy", true);

    ASSERT_EQ(filtered_products.size(), 1U);
    EXPECT_EQ(filtered_products[0].getId(), p2.getId());
}

TEST(CatalogueTest, getProductsByNamePartCaseInsensitive) {
    Product p1("X1", "TOY uppercase", 10);
    Product p2("X2", "toy lowercase", 10);

    Catalogue catalogue(Catalogue::inventory_t{
        {p1.getId(), p1},
        {p2.getId(), p2},
    });

    auto filtered_products = catalogue.getProductsByNamePart("toy", false);

    ASSERT_EQ(filtered_products.size(), 2U);
    // Nie wiemy, w jakiej kolejnoœci produkty z mapy bêd¹ rozpatrywane, wiec nie mo¿emy u¿yæ indeksowania...
    EXPECT_NE(std::find_if(filtered_products.begin(), filtered_products.end(), [&p1](const auto& product) { return product.getId() == p1.getId(); }), filtered_products.end());
    EXPECT_NE(std::find_if(filtered_products.begin(), filtered_products.end(), [&p2](const auto& product) { return product.getId() == p2.getId(); }), filtered_products.end());
}
