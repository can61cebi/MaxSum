#include <iostream>
#include <random>
#include <algorithm>
#include <cstdlib>

using namespace std;


void func1() {

    srand(static_cast<unsigned int>(time(nullptr)));

    int* arr = {0};

    for(int n = 0; n < 1000000; ++n) {
        arr[n] = 1000000 + static_cast<int>(rand()) / (static_cast<int>(RAND_MAX / 90000000));
    }
    
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = *max_element(arr, arr + n);
    int maxrounded = round(max);

    //cout << "\nv1\nMax Element = " << max;

    int total = 0;

    for (int k = 0; k < 10000; k++) {
        total += arr[k];
    }

    //cout << "\n1'den Max degere kadar olan toplam = " << (maxrounded * (maxrounded + 1)) / 2;

    //cout << "\nToplam: " << total << "\n";
    
}

void func2() {

    srand(static_cast<unsigned int>(time(nullptr)));

    int arr[10000000] = {0};

    for(int n = 0; n < 1000000; ++n) {
        arr[n] = 1000000 + static_cast<int>(rand()) / (static_cast<int>(RAND_MAX / 90000000));
    }
    
    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum = sum + arr[i];
    }
    
    int avg = sum / n;
    //cout << "\nv2\nOrtalama (bolme islemiyle): " << avg;

    int sumfunc = accumulate(arr, arr + n, 0.0f);
    int avgfunc = sumfunc / n;

    //cout << "\nOrtalama (fonksiyonla): " << avgfunc;

    int onetoavg = 0;

    for (int i = 1; i <= avgfunc; i++) {
        onetoavg += i;
    }
    
    //cout << "1'den Ortalamaya kadar olan sayıların toplamı (1 eklemeli): " << onetoavg << "\n";

}

int main() {

    for (int i = 0; i < 100; i++)
    {
        func1();
        func2();
    }
    
}
