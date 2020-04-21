#ifndef _CATALOGUE_HPP_
#define _CATALOGUE_HPP_
#include <string>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <functional>

class Product
{
private:
    std::string _id;
    std::string _name;
    double _price;
public:
    Product(std::string id, std::string name, double price) : _id(id), _name(name), _price(price){};
    std::string getId() const {return _id;};
    std::string getName() const {return _name;};
    double getPrice() const {return _price;};

};
class Catalogue
{
public:
    using inventory_t = std::map<std::string, Product>;
    Catalogue(const inventory_t& inventory=inventory_t{}) : _inventory(inventory) {};
    bool contains(std::string id) const;
    void addProduct(const Product& p);
    std::vector<Product> getProductsWithAppropriatePrice(std::function<bool(double)> predicate);
    std::vector<Product> getProductsByNamePart(std::string chunk, bool ignoreCase) const;
private:
    inventory_t _inventory;
};

std::string to_string(const Product& p);

#endif // _CATALOGUE_HPP
