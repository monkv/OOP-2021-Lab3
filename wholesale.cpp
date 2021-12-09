#include "wholesale.h"

int wholesale::get_gross() {
    return gross;
}

int wholesale::sell_a_product(int amount) {
    return amount * price;
}