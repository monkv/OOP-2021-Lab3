#include "product.h"
#include "retail.h"
#include "wholesale.h"
#include <iostream>

product::product(){
    std::cout << "\nType in the name of the product: ";
    std::cin >> name;
    std::cout << "\nType in the brand: ";
    std::cin >> brand;
    std::cout << "\nType in the country: ";
    std::cin >> country;
    std::cout << "\nType in the price: ";
    std::cin >> price;
    std::cout << "\nType in the amount of the product in storage: ";
    std::cin >> store_num;
};

std::string product::get_name() {
    return name;
}

void product::print_info() {
    std::cout << "name ->" << name << '\n';
    std::cout << "brand ->" << brand << '\n';
    std::cout << "country ->" << country << '\n';
    std::cout << "price ->" << price << '\n';
    std::cout << "amount in storage ->" << store_num << '\n';
    product* pr = this;
    wholesale* ch2;
    auto* ch = dynamic_cast<retail*>(pr);
    if (ch){
        std::cout << "markup ->" << ch->get_markup() << '\n';
    }
    else{
        ch2 = dynamic_cast<wholesale*>(pr);
        std::cout << "gross ->" << ch2->get_gross() << '\n';
    }
}

void product::return_type() {
    product* pr = this;
    auto* ch = dynamic_cast<retail*>(pr);
    if (ch){
        std::cout << "retail" << '\n';
    }
    else{
        std::cout << "wholesale" << '\n';
    }
}

int product::amount_in_storage() {
    return store_num;
}