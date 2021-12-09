#pragma once
#include "product.h"
#include <map>

class table{
private:
    std::map<int, product*> box; //массив ячеек
public:
    table() = default;
    //void sort_table();
    void add_an_item();
    product* find_by_code(int code);
    void delete_by_code(int code);
    void print_table();
    void sell_product(product* del);
};

class warehouse{
private:
    table Table;
public:
    warehouse() = default;
};


