#pragma once
#include "product.h"
#include "maps.h"

class table{
private:
    map<int, product*> box; ///< массив ячеек таблицы
public:
    table() = default;
    void add_an_item();
    product* find_by_code(int code);
    void findp(int k);
    void delete_by_code(int code);
    void print_table();
    void sell_product(int index);
    void print_info(int index);
    void type(int index);
    void instore(int index);
    void adding(int index);
    void change(int index);
    void reference();
    void reference_empty();
    void change_type(int index);
};