#include <iostream>

int main() {
    float a = pow(2, 24);
    float b = 1.f;
    float c = 1.f;

    std::cout << ((a+b)+c == a+(b+c)); // 0
}