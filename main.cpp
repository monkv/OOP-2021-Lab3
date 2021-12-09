#include <iostream>
#include <vector>
#include "table.h"
std::vector<std::string> MENU_MSG = {"0. Quit", "1. Find an item by a #code", "2. Add a new item to the table ",
                                     "3.Delete an item", "4. Print the table", "5. Work with an item (choose for more options)"};
std::vector<std::string> MENU_MSG_ITEM = {"0. Quit working with an item", "2. Get info about a product", "3. Get the type of a product",
                                     "4. Get the amount in storage", "5. Sell a product", "6. Add items to storage",
                                     "7. Change the price (and gross if it's wholesale)", "8. Change the type of a product"};
 int main(){
     int c = 0, s = 0;
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
                 break;
             case 2: //add item

                 break;
             case 3:
                 break;
             case 4:
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
                             break;
                         case 2:
                             break;
                         case 3:
                             break;
                         case 4:
                             break;
                         case 5:
                             break;
                         case 6:
                             break;
                         case 7:
                             break;
                         case 8:
                             break;
                         case 9:
                             break;
                     }
                 }while(s);
                 break;
         }
     }while (c);
     return 0;
}