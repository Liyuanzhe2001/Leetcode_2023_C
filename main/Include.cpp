//
// Created by LiYuanzhe on 2023/12/23.
//
#include "iostream"
#include "vector"
#include "algorithm"
#include "stack"
#include "queue"
#include "string"

#include <iostream>

int main() {
    int arr[5] = { 1,2,100,4,5 };

    int* p = arr;

    std::cout << "*(p+2)=" << *(p + 2) << std::endl;
    std::cout << "*p+2=" << *p + 2 << std::endl;
    std::cout << "arr[2]=" << arr[2] << std::endl;
    std::cout << "*(arr+2)=" << *(arr + 2) << std::endl;
    return 0;
}

