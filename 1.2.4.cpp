#include <iostream>

int main() {
    float s_curr = 0;
    float s_last;
    int min_k = 0;
    for(int k = 1; k <= pow(2, 23) + 1; k++) {
        s_last = s_curr;
        s_curr += (1/(float)k);
        if (s_curr == s_last) {
            min_k = k;
            break;
        }
    }
    std::cout << min_k; // 2097152 = 2^21
}
