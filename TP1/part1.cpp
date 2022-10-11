#include <iostream>
#include <time.h>
#include <stdlib.h>

int addTwoNumber(int a, int b) {
    return a + b;
}

void reverseNumbers(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void addNumberToRef(int a, int b, int &c) {
    c = a+b;
}

void addNumberToPointer(int a, int b, int *c) {
    *c = a+b;
}

void printArray(int array[], int size) {
    for(int i = 0; i < size; i++) {
        std::cout << array[i] << " | ";
    }
    std::cout << std::endl;
}

void fillArrayWithRandomInt(int array[], int size, int maxVal) {
    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        array[i] = rand() % maxVal;
    }
}

void sortArrayAscend(int arr[], int size) {
    int temp;
    for(int i = 0; i < size - 1; ++i) {
        for(int j = 0; j < size - 1 - i; ++j) {
            if(arr[j] > arr[j+1]) {
                reverseNumbers(arr[j], arr[j+1]);
            }
        }
    }
}

void sortArrayDescend(int arr[], int size) {
    int temp;
    for(int i = 0; i < size - 1; ++i) {
        for(int j = 0; j < size - 1 - i; ++j) {
            if(arr[j] < arr[j+1]) {
                reverseNumbers(arr[j], arr[j+1]);
            }
        }
    }
}

void invertOrder(int arr[], int size) {
    int i = 0;
    int j = size - 1;
    while(i < j){
        reverseNumbers(arr[i], arr[j]);
        i++;
        j--;
    }
}

int main() {
    // 1.1
    std::cout << "add two number (3 & 5): " << addTwoNumber(3, 5) << std::endl;

    // 1.2
    int n1 = 5;
    int n2 = 9;
    std::cout << "Before reverse: n1: " << n1 << " n2: " << n2 << std::endl;
    reverseNumbers(n1, n2);
    std::cout << "After reverse: n1: " << n1 << " n2: " << n2 << std::endl;

    // 1.3
    int res = 0;
    addNumberToRef(2, 10, res);
    std::cout << "add two number via ref: " << res << std::endl;

    int res2 = 0;
    addNumberToPointer(4, 14, &res2);
    std::cout << "add two number via pointer: " << res2 << std::endl;

    // 1.4 + bonus 1 + bonus 2
    int tabSize = 0;
    std::cout << "Createing a random number array. Wich size do you want ?" << std::endl;
    
    do{
        std::cout << "Give me a positive integer: ";
        std::cin >> tabSize;
        std::cout << std::endl;
    } while(tabSize <= 0);

    int order = 0;
    std::cout << "Choose your sort:\n1 for ascending\n2 dot descending" << std::endl;
    
    do {
        std::cout << "Type 1 or 2: ";
        std::cin >> order;
        std::cout << std::endl;
    } while(order != 1 && order != 2);

    int tab[tabSize];
    fillArrayWithRandomInt(tab, tabSize, 20);
    std::cout << "Unsorted array : ";
    printArray(tab, tabSize);
    if(order == 1) {
        sortArrayAscend(tab, tabSize);
        std::cout << "Sorted ascend array : ";
    } else {
        sortArrayDescend(tab, tabSize);
        std::cout << "Sorted descend array : ";
    }
    printArray(tab, tabSize);

    invertOrder(tab, tabSize);
    std::cout << "Array sorted in the other way :";
    printArray(tab, tabSize);

    return EXIT_SUCCESS;
}