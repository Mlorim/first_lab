#include <iostream>

void float_to_bin(unsigned int x) {
    for (int i = 31; i >= 0; i--) {
        std::cout << ((x & (1 << i)) ? '1' : '0');
        if (i == 31 || i == 23) {
            std::cout << ' ';
        }
    }
    std::cout << std::endl;
}

int main() {
    float f = 0.75f;
    unsigned int ui;
    
    std::memcpy(&ui, &f, sizeof(f));

    float_to_bin(ui);

    return 0;
}