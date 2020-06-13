//
// Created by Vasiliy Evdokimov on 01.06.2020.
//

#pragma once


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


template <typename T>
class BinaryHeap
{
public:

    BinaryHeap()
        : data(nullptr), size(0) {}

    BinaryHeap(T const key)
    {
        this->data[0] = key;
        this->size = 1;
    }
    BinaryHeap(T const *keys , size_t const size)
    {
        for (int i(0); i < size; ++i)
            insert(keys[i]);
    }
    int getSize()
    {
        return this->size;
    }

    T* getData()
    {
        return this->data;
    }

    void insert(T key)
    {

        T *newData = new T[this->size + 1];
        for (int i = 0; i < this->size; ++i)
            newData[i] = this->data[i];
        newData[this->size] = key;
        ++this->size;

        if (this->data != nullptr) delete[] this->data;
        this->data = newData;

        int i = this->size - 1;
        int parent{(i - 1) % 2};
        while (parent >= 0 && i > 0)
        {
            if (this->data[i] > this->data[parent])
            {
                T tmp{ this->data[i] };
                this->data[i] = this->data[parent];
                this->data[parent] = tmp;
            }
            else break;
            i = parent;
            parent =(i - 1) % 2;
        }
    }

    int search(T const key)
    {
        for (int i = 0; i < this->size; ++i)
            if (this->data[i] == key) return i;

        return -1;
    }

    void remove(T const key)
    {
        int index{search(key)};
        if (index == -1)
            return;
        else if (index > 0 && index < this->size - 1)
        {
            T* newData = new T[this->size - 1];
            --this->size;
            for (int i(0); i < index; ++i)
                newData[i] = this->data[i];
            for (int i(index); i < this->size; ++i)
                newData[i] = this->data[i + 1];

            delete[] this->data;
            this->data = newData;
            heapify(0);
        }
        else if (index == 0)
            removeMax();
        else if (index == this->size - 1)
        {
            --this->size;
            T *newData = new T[this->size];
            for (int i(0); i < this->size; ++i)
                newData[i] = this->data[i];

            delete[] this->data;
            this->data = newData;
        }
    }

    void removeMax()
    {
        T *newData = new T[this->size - 1];
        const T maxKey{ this->data[0] };
        this->data[0] = this->data[this->size - 1];

        for (int i (0); i < this->size - 1; ++i)
            newData[i] = this->data[i];

        delete[] this->data;
        this->data = newData;
        --this->size;
        heapify(0);
    }


    void heapify( int i)
    {
        int high{ getHigh() };
        while (high != 0)
        {
            int left{2 * i + 1};
            int right{2 * i + 2};

            if (left <= this->size - 1)
            {
                if (this->data[i] < this->data[left])
                {
                    T tmp{ this->data[i] };
                    this->data[i] = this->data[left];
                    this->data[left] = tmp;
                    heapify(left);
                }
            }
            if (right <= this->size - 1)
            {
                if (this->data[i] < this->data[right])
                {
                    T tmp{ this->data[i] };
                    this->data[i] = this->data[right];
                    this->data[right] = tmp;
                    heapify(right);
                }
            }
            --high;
        }
    }

    int getHigh()
    {
        if (this->size == 0)
            return 0;
        return static_cast<int>(std::ceil(log(this->size + 1) / log(2)));
    }

    T getMax()
    {
        if (this->size == 0)
            return -1;
        return this->data[0];
    }

    ~BinaryHeap()
    {
        delete[] data;
        this->size = 0;
    }

    void print()
    {
        int tab{2};
        int pow{ 2};

        if (this->size < 1)
        {
            return;
        }
        std::cout << " ROOT " << this->data[0] << std::endl;

        for (int i(1); i < this->size; ++i)
        {
            if ((i - 1) % 2 == 0)
                std::cout << "(Parent " << this->data[(i - 1) / 2] << "| Left " << this->data[i] << ") ";
            else
                std::cout << "(Parent " << this->data[(i - 1) / 2] << "| Right " << this->data[i] << ") ";

            if (tab == i)
            {
                pow *= 2;
                tab += pow;
                std::cout << std::endl;
            }
        }
    }

private:

    T *data = new T[1];
    size_t size = 0;
};