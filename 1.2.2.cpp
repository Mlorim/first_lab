#include <iostream>

int main() {
    // min a: min(r(a, b) = 1) for all b > a
    float a = pow(2, 23);
    std::cout << (a == a + 0.1f) << '\n'; // 1
    std::cout << (a + 1 == a + 0.6f) << '\n'; // 1

    // min b: x == x + 1 for all x > b
    float b = pow(2, 24);
    std::cout << (b == b + 1.0f); // 1
}