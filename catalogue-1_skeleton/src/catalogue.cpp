#include "catalogue.hpp"

#include <sstream>
#include <iomanip>
#include <cctype>
#include <algorithm>

std::string to_string(const Product& p){
    std::ostringstream oss;
    oss<<p.getName() << "["<<p.getId()<<"] : $"<<std::setprecision(2)<<std::fixed<<p.getPrice();
    return oss.str();
}
bool Catalogue::contains(std::string id) const
{
    return(_inventory.find(id) != _inventory.end());
}
void Catalogue::addProduct(const Product& p)
{
    _inventory.emplace(p.getId(),p);
}
std::vector<Product> Catalogue::getProductsWithAppropriatePrice(std::function<bool(double)> predicate)
{
    std::vector<Product> v;
    for(const auto& it : _inventory) {
        const auto& product=it.second;
        if(predicate(product.getPrice()))
            v.push_back(product);
    }
    return v;
}
std::vector<Product> Catalogue::getProductsByNamePart(std::string chunk, bool ignoreCase) const
{
    std::vector<Product> v;
    auto chunkTransformed=chunk;
    if(ignoreCase)
        std::transform(chunk.begin(), chunk.end(), chunkTransformed.begin(), ::tolower);
    for(const auto& it: _inventory)
    {
        auto nameTransformed=it.second.getName();

        if(ignoreCase)
            std::transform(it.second.getName().begin(), it.second.getName().end(), nameTransformed.begin(), ::tolower);
        if(nameTransformed.find(chunkTransformed))
            v.push_back(it.second);
    }
    return v;
}
