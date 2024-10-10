#include <iostream>
#include <iomanip>
#include <cmath>

void gen(int p[], int size, int minValue, int maxValue, int i = 0) {
    if (i == size) return;

    p[i] = minValue + rand() % (maxValue - minValue + 1);  
    gen(p, size, minValue, maxValue, i + 1);
}

void print(const int p[], int size, int i = 0) {
    if (i == size) {
        std::cout << std::endl;
        return;
    }

    std::cout << std::setw(4) << p[i] << " ";
    print(p, size, i + 1);
}

int countElements(const int p[], int size, int i = 0) {
    if (i == size) return 0;

    return ((p[i] % 2 == 0 && i % 13 == 0) ? 1 : 0) + countElements(p, size, i + 1);
}

int sumElements(const int p[], int size, int i = 0) {
    if (i == size) return 0;

    return ((p[i] % 2 == 0 && i % 13 == 0) ? p[i] : 0) + sumElements(p, size, i + 1);
}

void Zero(int p[], int size, int i = 0) {
    if (i == size) return;

    if (p[i] % 2 == 0 && i % 13 == 0) {
        p[i] = 0;
    }

    Zero(p, size, i + 1);
}

int main() {
    const int size = 25;
    int p[size];
    int minValue = 15, maxValue = 94;


    gen(p, size, minValue, maxValue);

    std::cout << "Initial array: ";
    print(p, size); 

    int count = countElements(p, size); 
    int sum = sumElements(p, size);   
    Zero (p, size);          

    std::cout << "Count of elements that meet the criterion: " << count << std::endl;
    std::cout << "Sum of these elements: " << sum << std::endl;

    std::cout << "Modified array: ";
    print(p, size); 

    return 0;
}
