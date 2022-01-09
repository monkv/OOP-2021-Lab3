#include "product.h"
#include "retail.h"
#include "wholesale.h"
#include "maps.h"
#include <iostream>
///\brief конструктор продутка
product::product(){
    std::cout << "\nType in the name of the product: ";
    std::cin >> name;
    std::cout << "\nType in the brand: ";
    std::cin >> brand;
    std::cout << "\nType in the country: ";
    std::cin >> country;
    std::cout << "\nType in the price: ";
    std::cin >> price;
    std::cout << "\nType in the amount of the product in storage: ";
    std::cin >> store_num;
};
///\brief конструктор нового продукта от другого продукта
product::product(product *pr) {
    name = pr->name;
    country = pr->country;
    brand = pr->brand;
    price = pr->price;
    store_num = pr->store_num;
}
///\brief функция возвращает имя товара
std::string product::get_name() {
    return name;
}
///\brief функция выводит полное инфо о товаре
void product::print_info() {
    std::cout << "name ->" << name << '\n';
    std::cout << "brand ->" << brand << '\n';
    std::cout << "country ->" << country << '\n';
    std::cout << "price ->" << price << '\n';
    std::cout << "amount in storage ->" << store_num << '\n';
    product* pr = this;
    wholesale* ch2;
    auto* ch = dynamic_cast<retail*>(pr);
    if (ch){
        std::cout << "markup ->" << ch->get_markup() << '\n';
    }
    else{
        ch2 = dynamic_cast<wholesale*>(pr);
        std::cout << "gross ->" << ch2->get_gross() << '\n';
    }
}
///\brief функция возвращает тип товара
int product::return_type() {
    product* pr = this;
    auto* ch = dynamic_cast<retail*>(pr);
    if (ch){
        //std::cout << "retail" << '\n';
        return 1;
    }
    else{
        //std::cout << "wholesale" << '\n';
        return 2;
    }
}
///\brief функция проверяет сколькотовара на складе
int product::amount_in_storage() {
    return store_num;
}
///\brief функция продажи товара, возвращается итоговая цена
double product::sell_a_product(int k) {
    double f_price;
    product* pr = this;
    wholesale* ch2;
    auto* ch = dynamic_cast<retail*>(pr);
    if (ch){
        f_price = ch->sell_r(k);
        store_num -= k;
    }
    else{
        ch2 = dynamic_cast<wholesale*>(pr);
        f_price = ch2->sell_w(k);
    }
    return f_price;
}
///\brief функция добавления товара
void product::add_more_pr(int k) {
    product* pr = this;
    wholesale* ch2;
    auto* ch = dynamic_cast<retail*>(pr);
    if (ch){
        store_num += k;
    }
    else{
        ch2 = dynamic_cast<wholesale*>(pr);
        ch2->add_wares(k);
    }
}
///\brief функция, изменяющая надбавку или же цену за опт в зависимости от типа продукта
void product::change_price() {
    std::cout << "Type in the new price" << '\n';
    std::cin >> price;
    int a;
    product* pr = this;
    wholesale* ch2;
    auto* ch = dynamic_cast<retail*>(pr);
    if (ch){
        std::cout << "The product is retail, type in the new markup" << '\n';
        std::cin >> a;
        ch->change_the_price(a);
    }
    else{
        ch2 = dynamic_cast<wholesale*>(pr);
        std::cout << "The product is retail, type in the new markup" << '\n';
        std::cin >> a;
        ch2->change_the_price(a);
    }
}



