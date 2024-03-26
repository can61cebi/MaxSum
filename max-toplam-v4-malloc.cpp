#include <iostream>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <numeric>

using namespace std;

void func1() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int* arr = (int*)malloc(100000000 * sizeof(int));

    for(int n = 0; n < 10000000; ++n) {
        arr[n] = 1000000 + static_cast<int>(rand()) / (static_cast<int>(RAND_MAX / 9000000));
    }

    int n = 10000000;
    int max = *max_element(arr, arr + n);
    int maxrounded = round(max);

    //cout << "\nv1\nMax Element = " << max;

    int total = 0;

    for (int k = 0; k < n; k++) {
        total += arr[k];
    }

    //cout << "\n1'den Max degere kadar olan toplam = " << (maxrounded * (maxrounded + 1)) / 2;

    //cout << "\nToplam: " << total << "\n";

    free(arr);
}

void func2() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int* arr = (int*)malloc(10000000 * sizeof(int));

    for(int n = 0; n < 10000000; ++n) {
        arr[n] = 1000000 + static_cast<int>(rand()) / (static_cast<int>(RAND_MAX / 9000000));
    }

    int n = 10000000;

    long long sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int avg = sum / n;
    //cout << "\nv2\nOrtalama (bolme islemiyle): " << avg;

    long long sumfunc = accumulate(arr, arr + n, 0LL);
    int avgfunc = sumfunc / n;

    //cout << "\nOrtalama (fonksiyonla): " << avgfunc;

    long long onetoavg = 0;

    for (int i = 1; i <= avgfunc; i++) {
        onetoavg += i;
    }

    //cout << "\n1'den Ortalamaya kadar olan sayıların toplamı: " << onetoavg << "\n";

    free(arr);
}

int main() {
    for (int i = 0; i < 100; i++) {
        func1();
        func2();
    }
}
