#include <iostream>

int abs(int n) {
    if (n > 0) {
        return n;
    } else {
        return (-1)*n;
    }
    return n;
}

int bin_log(int n) {
    int power = 0;
    if (n == 0) {
        return 1;
    }
    while (n > 0) {
        n /= 2;
        power++;
    }
    return power;
}

int *dec_to_bin(int n) {
    int p = 8; //how many (last) characters of bin number user will see
    int temp = abs(n);
    int len = bin_log(temp);
    int res[32] = {};
    for (int i = 1; i <= len; i++) {
        res[p-i] = temp % 2;
        temp /= 2;
    }    
    if (n >= 0) {
        for (int i = 0; i < p; i++) {
            std::cout << res[i];
        }
    } else {
        for(int i = 0; i < p; i++) {
            int curr = res[i];
            res[i] = not(curr);
        }
        for (int i = 1; i <= p; i++) {
            if (res[p-i] == 0) {
                res[p-i] = 1;
                break;
            }
            else {
                res[p-i] = 0;
            }
        }
        for (int i = 0; i < p; i++) {
            std::cout << res[i];
        }
    }
}


int main() {
    dec_to_bin(5);
    std::cout << '\n';
    int i = INT_MAX;
    std::cout << i << ' ' << (i+1) << '\n';
    unsigned int ui = 0;
    std::cout << UINT_MAX << ' ' << (ui-1);
}