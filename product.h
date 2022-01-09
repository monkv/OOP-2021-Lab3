#pragma once
#include <iostream>

class product{
protected:
    std::string name; ///< название товара
    std::string country; ///< страна-изготовитель
    std::string brand; ///< название фирмы
    int store_num; ///< наличие на складе
    int price; ///< цена
public:
    product();
    explicit product(product* pr);
    virtual ~product() = default;
    std::string get_name();
    void print_info();
    int amount_in_storage();
    int return_type();
    double sell_a_product(int k);
    void add_more_pr(int k);
    void change_price();
};


