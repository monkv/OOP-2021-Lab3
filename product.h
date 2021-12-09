#pragma once
#include <iostream>

class product{
private:
    std::string name; //название товара
    std::string country; // страна-изготовитель
    std::string brand; //название фирмы
    int store_num; //наличие на складе
    int price;
public:
    product();
    virtual ~product() = default;
    std::string get_name();
    void print_info();
    int amount_in_storage();
    void return_type();
};


