#include <iostream>
#include <vector>
#include "table.h"
std::vector<std::string> MENU_MSG = {"0. Quit", "1. Find an item by #code", "2. Add a new item to the table",
                                     "3.Delete an item", "4. Print the table", "5. Work with an item (choose for more options)", "6. Print info about all products in storage", "7. Print info about missing products"};
std::vector<std::string> MENU_MSG_ITEM = {"0. Quit working with an item", "1. Get info about a product", "2. Get the type of a product",
                                          "3. Get the amount in storage", "4. Sell a product", "5. Add items to storage",
                                          "6. Change the price (and gross if it's wholesale)", "7. Change the type of a product"};
int main(){
    int c = 0, s = 0, index;
    table Table;
    do{
        for (int i = 0; i < MENU_MSG.size(); i++)
            std::cout << MENU_MSG[i] << "\n";
        std::cout << "\nChoose an option: ";
        std::cin >> c;
        switch(c){
            case 0:
                break;
            case 1:
                std::cout << "\nType in code of a product: " << "\n";
                std::cin >> index;
                Table.findp(index);
                break;
                case 2: //add item
                Table.add_an_item();
                break;
                case 3:
                    std::cout << "\nType in code of a product: " << "\n";
                    std::cin >> index;
                    try {
                        Table.delete_by_code(index);
                    }
                    catch (std::invalid_argument &msg){
                        std::cerr << msg.what() << std::endl;
                    }
                    break;
                    case 4:
                        Table.print_table();
                        break;
                        case 5:
                            do{
                                for (int i = 0; i < MENU_MSG_ITEM.size(); i++)
                                    std::cout << MENU_MSG_ITEM[i] << "\n";
                                std::cout << "\nChoose an option: ";
                                std::cin >> s;
                                switch(s){
                                    case 0:
                                        break;
                                    case 1:
                                        std::cout << "\nType in code of a product: " << "\n";
                                        std::cin >> index;
                                        Table.print_info(index);
                                        break;
                                        case 2:
                                            std::cout << "\nType in code of a product: " << "\n";
                                            std::cin >> index;
                                            Table.type(index);
                                            break;
                                            case 3:
                                                std::cout << "\nType in code of a product: " << "\n";
                                                std::cin >> index;
                                                Table.instore(index);
                                                break;
                                                case 4:
                                                    std::cout << "\nType in code of a product: " << "\n";
                                                    std::cin >> index;
                                                    Table.sell_product(index);
                                                    break;
                                                    case 5:
                                                        std::cout << "\nType in code of a product: " << "\n";
                                                        std::cin >> index;
                                                        Table.adding(index);
                                                        break;
                                                        case 6:
                                                            std::cout << "\nType in code of a product: " << "\n";
                                                            std::cin >> index;
                                                            Table.change(index);
                                                            break;
                                                            case 7:
                                                                std::cout << "\nType in code of a product: " << "\n";
                                                                std::cin >> index;
                                                                Table.change_type(index);
                                }
                            }while(s);
                            break;
                            case 6:
                                Table.reference();
                                break;
                                case 7:
                                    Table.reference_empty();
                                    break;
        }
    }while (c);
    return 0;
}
