//
// Created by Vasiliy Evdokimov on 01.06.2020.
//

#include <iostream>

#include "InterfaceBinaryTree.hpp"
#include "BinaryTree.hpp"


void InterfaceBinaryTree(){
    BinaryTree<int> tree;
    BinaryTree<int>* subTree{nullptr};

    int choice = 0;
    size_t item = 0;
    int *items = nullptr;
    size_t size = 0;
    bool end_cycle = false;

    BinaryTree<int>* tree2 = new BinaryTree<int>;

    while (true)
    {
        std::cout << "Choose the action:" << std::endl;
        std::cout <<
                  "1. Make tree" << std::endl <<
                  "2. Add element" << std::endl <<
                  "3. Remove element" << std::endl <<
                  "4. Find element" << std::endl <<
                  "5. Print tree" << std::endl <<
                  "6. Print maximum" << std::endl <<
                  "7. Print minimum" << std::endl <<
                  "8. Make subtree" << std::endl <<
                  "9. Print subtree" << std::endl <<
                  "10. Check subtree for entry" << std::endl <<
                  "11. Exit" << std::endl;

        std::cin >> choice;

        switch (choice)
        {
            case 1:
                std::cout << "Write the quantaty of elements:" << std::endl;
                std::cin >> size;
                if (size == 0)
                    std::cout << "The tree is not made" << std::endl;
                else
                {
                    std::cout << "Write the elements:" << std::endl;
                    items = new int[size];
                    for (int i(0); i < size; ++i)
                    {
                        std::cin >> items[i];
                        tree.insert(items[i]);
                    }
                    delete[] items;
                    std::cout << "The tree is made" << std::endl;
                }
                break;

            case 2:
                std::cout << "Write the element to add: ";
                std::cin >> item;
                tree.insert(item);
                std::cout << "The element is added" << std::endl;
                break;

            case 3:
                std::cout << "Write the element to remove: ";
                std::cin >> item;
                if(tree.search(item) == nullptr)
                    std::cout << "Element for removing is not exsist" << std::endl;
                else
                {
                    tree.remove(item);
                    std::cout << "The element is removed" << std::endl;
                }
                break;

            case 4:
                std::cout << "Write the element to find: ";
                std::cin >> item;
                if (tree.search(item) == nullptr)
                    std::cout << "Element doesn't exsist in the tree" << std::endl;
                else
                    std::cout << "Element exist in the tree" << std::endl;
                break;

            case 5:
                if (tree.getRoot() == nullptr)
                    std::cout << "Tree is empty";
                else
                {
                    std::cout << "Elements or the tree (symetrical order): ";
                    tree.print();
                }
                break;

            case 6:
                if (tree.getRoot() == nullptr)
                    std::cout << "The tree isn't exist" << std::endl;
                else
                {
                    std::cout << "Maximum is : ";
                    std::cout << tree.getMax(tree.getRoot()) << std::endl;
                }
                break;

            case 7:
                if (tree.getRoot() == nullptr)
                    std::cout << "The tree isn't exist" << std::endl;
                else
                {
                    std::cout << "Mininum is : ";
                    std::cout << tree.getMin(tree.getRoot()) << std::endl;
                }
                break;

            case 8:
                std::cout << "Write the element - root of subtree: ";
                std::cin >> item;
                subTree = tree.subTree(item);
                std::cout << "The subtree is made" << std::endl;
                break;
            case 9:
                if (subTree == nullptr)
                    std::cout << "Subtree isn't made" << std::endl;
                else
                    subTree->print();
                break;
            case 10:
                std::cout << "Write the quantaty of  other tree's elements to check:" << std::endl;
                std::cin >> size;
                std::cout << "Write the elements of other tree to check:" << std::endl;
                items = new int[size];
                for (int i(0); i < size; ++i)
                    std::cin >> items[i];

                tree2 = new BinaryTree<int>{ items, size };
                delete[] items;

                if (tree.getRoot() == nullptr)
                    std::cout << "The tree to check isn't exist";
                else if (tree.subTreeCheck(tree2) == true)
                    std::cout << "true" << std::endl;
                else
                    std::cout << "false" << std::endl;
                break;


            case 11:
                std::cout << "Goodbye!" << std::endl;
                end_cycle = true;
                break;

            default:
                std::cout << "WRONG CHOISE!" << std::endl;
        }
        std::cout << std::endl;
        if (end_cycle) break;
    }
}