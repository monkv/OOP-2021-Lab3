#pragma once
#include "product.h"

class wholesale: public product{
protected:
    int gross; //размер опта
public:
    explicit wholesale(int a) : product(), gross(a) {}
    int get_gross();
    int sell_a_product(int amount);
    //void add_wares(int amount); //добавление товара на склад(указ. кол-во товара, стоимость)
    //void change_the_price_and_gross(int gross);
    //void change_to_retail();
};

