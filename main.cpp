#include <iostream>
#include "console.h"
#include "core.h"
int main() {
    int choice  = 0;
    while (true) {
        console();
        std :: cin >> choice ;
        if (choice == 1) {
            int specialization;
            std::string name;
            bool status;
            std::cin >> specialization >> name >> status;
            add(specialization, name, status);
        } else if (choice == 2) {
            print_all();
        } else if (choice == 3) {
            std::cout << "Enter specialization : ";
            int specialization;
            std::cin >> specialization;
            if (Size[specialization - 1] == 0) {
                std::cout << "no patient at the moment. Have rest , Dr\n";
            } else {
                std::cout << arr[specialization][Size[specialization - 1]] << "\n", --Size[specialization - 1];
            }
        }
        else if (! (choice >= 1 and choice <= 4) ){
            std :: cout << "invalid number . please try again\n" ;
        }
        else {
            break;
        }
    }

}
