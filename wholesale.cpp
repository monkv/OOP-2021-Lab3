#include "wholesale.h"
///\brief возвращает gross
int wholesale::get_gross() {
    return gross;
}
///\brief считает стоимость k товара
double wholesale::sell_w(int k) {
    store_num -= k*gross;
    return k * double(price)* gross;
}
///\brief добавляет на склад k товара
void wholesale::add_wares(int k) {
    store_num += k*gross;
}
///\brief меняет gross
void wholesale::change_the_price(int k) {
    gross = k;
}