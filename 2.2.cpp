#include <iostream>
#include <chrono>
#include <cmath>
using namespace std;
using namespace chrono;

void merge(int * array, int left, int mid, int right) {
    int delt1 = 0;
    int delt2 = 0;
    int *res = new int[right-left];
    while ((left + delt1 < mid) && (mid + delt2 < right)) {
        if (array[left + delt1] < array[mid + delt2]) {
            res[delt1 + delt2] = array[left + delt1];
            delt1++;
        } else {
            res[delt1 + delt2] = array[mid + delt2];
            delt2++;            
        }
    }
    while (left + delt1 < mid) {
        res[delt1 + delt2] = array[left + delt1];
        delt1++;        
    }
    while (mid + delt2 < right) {
        res[delt1 + delt2] = array[mid + delt2];
        delt2++;        
    }
    for (int i = 0; i < delt1+delt2; i++) {
        array[left+i] = res[i];
    }
}

void mergeSort(int *array, int left, int right) {
    if (left + 1 >= right) {
        return;
    }
    int mid = ((left + right) / 2);
    mergeSort(array, left, mid);
    mergeSort(array, mid, right);
    merge(array, left, mid, right);
}

void my_sort(int n, int* array) {
    mergeSort(array, 0, n-1);
}

int main() {
    //optimization check
    for (int n = 10; n < 500000; n += 1000) {
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

    // functionality check
    // int n = 10;
    // int *array = new int[n]; 

    // for (int i = n; i > 0; i--) {
    //     array[n-i] = rand() % 10;
    // }

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