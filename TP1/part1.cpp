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

    // 1.4
    int tabSize = 5;
    int tab[tabSize];
    fillArrayWithRandomInt(tab, tabSize, 20);
    std::cout << "Unsorted array : ";
    printArray(tab, tabSize);
    sortArrayAscend(tab, tabSize);
    std::cout << "Sorted array : ";
    printArray(tab, tabSize);

    return EXIT_SUCCESS;
}