//
// Created by Vasiliy Evdokimov on 01.06.2020.
//

#include <iostream>

#include "InterfaceBinaryHeap.hpp"
#include "BinaryHeap.hpp"

void InterfaceBinaryHeap(){
    BinaryHeap<int> heap;

    int choice = 0;
    int* items = nullptr;
    size_t size = 0;
    int key = 0;
    bool end_cycle = false;

    while (true)
    {
        std::cout << "Choose the action:" << std::endl;
        std::cout <<
                  "1. Make heap" << std::endl <<
                  "2. Add element" << std::endl <<
                  "3. Remove element" << std::endl <<
                  "4. Find element" << std::endl <<
                  "5. Print heap" << std::endl <<
                  "6. Print maximum" << std::endl <<
                  "7. Print high" << std::endl <<
                  "8. Exit" << std::endl;

        std::cin >> choice;
        switch (choice)
        {
            case 1:
                std::cout << "Write the quantity of elements:" << std::endl;
                std::cin >> size;
                std::cout << "Write the elements:" << std::endl;
                items = new int[size];
                for (int i(0); i < size; ++i)
                {
                    std::cin >> items[i];
                    heap.insert(items[i]);
                }
                delete[] items;
                std::cout << "The heap is made" << std::endl;
                break;

            case 2:
                std::cout << "Write the element to add: ";
                std::cin >> key;
                heap.insert(key);
                std::cout << "The element is added" << std::endl;
                break;

            case 3:
                std::cout << "Write the element to remove: ";
                std::cin >> key;
                if (heap.search(key) == -1)
                    std::cout << "The heap is empty" << std::endl;
                else
                {
                    heap.remove(key);
                    std::cout << "The element is removed" << std::endl;
                }
                break;

            case 4:
                std::cout << "Write the element to find: ";
                std::cin >> key;
                if (heap.search(key) == -1)
                    std::cout << "Element doesn't exsist in the tree" << std::endl;
                else
                    std::cout << "Element exist in the tree" << std::endl;
                break;

            case 5:
                if (heap.getSize() == 0)
                    std::cout << "the heap is empty" << std::endl;
                else
                {
                    std::cout << "Elements of the heap: ";
                    heap.print();
                }
                break;

            case 6:
                if (heap.getSize() == 0)
                    std::cout << "Heap is empty" << std::endl;
                else
                    std::cout << heap.getMax() << std::endl;
                break;

            case 7:
                if (heap.getSize() == 0)
                    std::cout << "Heap is empty" << std::endl;
                else
                    std::cout << heap.getHigh() << std::endl;
                break;

            case 8:
                std::cout << "Goodbye!" << std::endl;
                end_cycle = true;

            default:
                std::cout << "WRONG CHOISE";
        }
        std::cout << std::endl;

        if (end_cycle) break;
    }
}