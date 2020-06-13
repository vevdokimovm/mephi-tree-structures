//
// Created by Vasiliy Evdokimov on 01.06.2020.
//

#include "Interface.hpp"
#include "InterfaceBinaryHeap.hpp"
#include "InterfaceBinaryTree.hpp"
#include <iostream>

void Interface(){
    int choice = 0;

    std::cout << "Choose algorithm: " << std::endl;
    std::cout <<
              "1. Binary tree" << std::endl <<
              "2. Binary heap" << std::endl;
    std::cin >> choice;
    if (choice == 1)
        InterfaceBinaryTree();
    else if (choice == 2)
        InterfaceBinaryHeap();
    else
        std::cout << "WRONG CHOISE!" << std::endl;

    std::cout << std::endl;
}