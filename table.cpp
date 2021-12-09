#include "table.h"
#include "retail.h"
#include "wholesale.h"
#include <map>

void table::add_an_item(){
    int type, index, gross;
    double markup;
    product *pr; //тут пэрент который закинется в таблицу
    std::cout << "\nIs the product retail (1) or wholesale (0)?";
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
    std::map <int, product*> :: iterator it;
    it = box.find(index);
    if (it == box.end()){
        throw std::exception("no product with such code found");
    }
    else
        return it->second;
}

void table::delete_by_code(int index){
    std::map <int, product*> :: iterator it;
    it = box.find(index);
    if (it == box.end()){
        throw std::exception("no product with such code found");
    }
    else box.erase(it);
}

void table::print_table() {
    std::cout << "table contains:\n";
    std::string name;
    for (auto it = box.begin(); it != box.end(); ++it){
        name = it->second->get_name();
        std::cout << it->first << " => " << it->second << name << '\n';
    }
}

void table::sell_product(product* del) {
    int index;
    for (auto it = box.begin(); it != box.end(); ++it) {
        if (it->second == del)
            index = it->first;
    }

    box.erase(index);

}