#pragma once
#include "product.h"

class retail: public product{
protected:
    double markup; //надбавка в % на стоимость товара
public:
    explicit retail(double a) : product(), markup(a) {}
    double get_markup();
    //int sell_a_product(int amount);
    //void add_wares(int n, int price); //добавление товара на склад(указ. кол-во товара, стоимость)
    //void change_the_price(int price);
    //void* change_to_wholesale(int n);
};


