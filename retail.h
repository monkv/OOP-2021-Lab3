#pragma once
#include "product.h"


class retail: public product{
private:
    double markup; ///< надбавка в процентах на стоиость товара
public:
    explicit retail(double a) : product(), markup(a) {}
    explicit retail(product* pr, int a) : product(pr), markup(a) {};
    double get_markup();
    double sell_r(int price);
    void change_the_price(int price);
};