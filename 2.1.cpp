#include <iostream>
#include <chrono>
#include <cmath>
using namespace std;
using namespace chrono;

int to_log(int n) {
    int power = 1;
    while (pow(2, power) < n) {
        power += 1;
    } 
    return pow(2, power);
}


void shiftUp(int i, int n, int *array) {
    int first = 2 * i + 1;
    int second = 2 * i + 2;
    int parent = i;
    int term;
    if ((first < n) && (array[first] > array[parent])) {
        parent = first;
    }
    if ((second < n) && (array[second] > array[parent])) {
        parent = second;
    }
    if (parent != i) {
        term = array[i];
        array[i] = array[parent];
        array[parent] = term;
        shiftUp(parent, n, array);
    }
}

void array_to_heap(int n, int *array) {
    for (int i = (to_log(n)/2)-(i%2); i >= 0; i--) {
        shiftUp(i, n, array);
    }
}

void my_sort(int n, int * array) {
    array_to_heap(n, array);
    int temp;
    for (int i = n-1; i >= 0; i--) {
        temp = array[i];
        array[i] = array[0];
        array[0] = temp;
        shiftUp(0, i, array);
    }
}

int main() {
    //optimization check
    for (int n = 10; n < 1000000; n += 10000) {
        int *array = new int[n]; 
        for (int i = n; i > 0; i--) {
            array[n-i] = rand() % 100;
        }
        
        auto start = high_resolution_clock::now();
        my_sort(n, array);
        auto stop = high_resolution_clock::now();
        delete[]array;
        auto duration = duration_cast<microseconds>(stop - start);
        cout << duration.count() << '\n';
    }

    //functionality check
    // int *array = new int[10]; 
    // int n = 10;

    // for (int i = n; i > 0; i--) {
    //     array[n-i] = rand() % 20;
    // }
    // array[1] = -100;
    // array[n-1] = 100;

    // for (int i = 0; i < n; i++) {
    //     cout << array[i] << ' ';
    // }
    // cout << '\n';

    // my_sort(n, array);

    // for (int i = 0; i < n; i++) {
    //     cout << array[i] << ' ';
    // }
    // cout << '\n';

}