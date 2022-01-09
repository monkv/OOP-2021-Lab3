#include "table.h"
#include "retail.h"
#include "wholesale.h"
#include "maps.h"

void table::add_an_item(){
    int type, index, gross;
    double markup;
    product *pr; //тут пэрент который закинется в таблицу
    std::cout << "\nIs the product retail (1) or wholesale (0)? ";
    std::cin >> type;
    if (type){
        std::cout << "\nWhat is the markup for the product? ";
        std::cin >> markup;
        pr = new retail(markup); //тут создаю ритейл и закидываю его в пэрент
    }
    else{
        std::cout << "\nWhat is the gross for the product? ";
        std::cin >> gross;
        pr = new wholesale(gross);
    }
    std::cout << "\nEnter the code of the product";
    std::cin >> index;
    box.emplace(index, pr);
};


product* table::find_by_code(int index){
    iterator<int, product*> it = iterator<int, product*>(&*box.find(index));
    if (it == box.end()){
        throw std::exception("no product with such code found");
    }
    else
        return (*it).second;
}

void table::findp(int k) {
    product* f = find_by_code(k);
    std::cout << "the product was found, the name - " << f->get_name() << "\n";
}

void table::delete_by_code(int index){
    iterator<int, product*> it = box.find(index);
    if (it == box.end()){
        throw std::exception("no product with such code found");
    }
    else box.erase((*it).first);
}

void table::print_table() {
    std::cout << "table contains:\n";
    std::string name;
    for (auto it = box.begin(); it != box.end(); it++){
        std::cout << (*it).first << " => " << (*it).second->get_name() << '\n';
    }
}
///\brief функция "продает товар"
///\detailed узнает сколько надо продать и считает конечную стоимость
void table::sell_product(int index) {
    product* a = find_by_code(index);
    int k;
    std::cout << "How much do you want to sell:\n";
    std::cin >> k;
    std::cout << "the final cost -> " << a->sell_a_product(k) << "\n";
}

void table::print_info(int index) {
    product* a = find_by_code(index);
    a->print_info();
}

void table::type(int index){
    product* a = find_by_code(index);
    int k = a->return_type();
    if (k)
        std::cout << "retail" << '\n';
    else std::cout << "wholesale" << '\n';
}

void table::instore(int index) {
    product* a = find_by_code(index);
    std::cout << "in store -> " << a->amount_in_storage() << "\n";
}

void table::adding(int index) {
    product* a = find_by_code(index);
    int k;
    std::cout << "How much do you want to add:\n";
    std::cin >> k;
    a->add_more_pr(k);
}

void table::change_type(int k){
    product* old = find_by_code(k);
    product *n_pr;
    int a;
    if (old->return_type()){
        std::cout << "The product is retail, we can change it into wholesale" << '\n';
        std::cout << "Type in the new gross" << '\n';
        std::cin >> a;
        n_pr = new wholesale(old, a); ///< конструктор нового опта от старого продукта и a (gross)
    }
    else{
        std::cout << "The product is wholesale, we can change it into retail" << '\n';
        std::cout << "Type in the new markup" << '\n';
        std::cin >> a;
        n_pr = new retail(old, a); ///< конструктор нового ритейла от старого продукта и a (markup)
    }
    old = n_pr; ///< меняем указатели  в таблице
    delete(n_pr);
}

void table::change(int index){
    product* a = find_by_code(index);
    a->change_price();
}

void table::reference() {
    for (auto it = box.begin(); it != box.end(); ++it){
        std::cout << "---------------------------------- \n";
        (*it).second->print_info();
    }
}

void table::reference_empty() {
    for (auto it = box.begin(); it != box.end(); ++it){
        if ((*it).second->amount_in_storage() == 0){
            std::cout << "---------------------------------- \n";
            (*it).second->print_info();
        }
    }
}
