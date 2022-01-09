#pragma once
#include "product.h"


class wholesale: public product{
protected:
    int gross; ///< размер опта
public:
    explicit wholesale(int a) : product(), gross(a) {};
    explicit wholesale(product* pr, int a) : product(pr), gross(a) {};
    int get_gross();
    double sell_w(int amount);
    void add_wares(int amount); //добавление товара на склад(указ. кол-во товара, стоимость)
    void change_the_price(int gross);
};
