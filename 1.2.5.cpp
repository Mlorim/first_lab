#include <iostream>

int main() {
    float s = 0;
    for(int k = 1; k <= 2097152+100; k++) {
        s += (1.f/(float)k);
    }
    std::cout << s << '\n'; // 15.4037

    float s_1 = 0;
    for(int k = 2097152+100; k >= 1; k--) {
        s_1 += (1.f/(float)k);
    }
    std::cout << s_1; // 15.1329
}

