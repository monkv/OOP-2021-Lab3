#include "retail.h"
#include "product.h"
#include <iostream>
#include <string>

double retail::get_markup() {
    return markup;
}

double retail::sell_r(int k) {
    return double(price) * markup * k;
}

void retail::change_the_price(int k) {
    markup = k;
}
