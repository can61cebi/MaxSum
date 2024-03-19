#include <iostream>
#include <random>
#include <algorithm>

using namespace std;


void func1() {

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> distr(10000, 20000);

    float arr[10000];

    for(int n=0; n<10000; ++n) {
        arr[n] = distr(gen);
        }
    
    int n = sizeof(arr) / sizeof(arr[0]);
    float max = *max_element(arr, arr + n);
    int maxrounded = round(max);

    cout << "v1\nMax Element = " << max;

    float total = 0;

    for (int k = 0; k < 10000; k++)
    {
        total+=arr[k];
    }

    cout << "\n1'den max degere kadar olan toplam = " << (maxrounded*maxrounded+1)/2;

    cout << "\nToplam: " << total << "\n\n";
    
}

void func2() {

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> distr(1000000, 10000000);

    float arr[1000000];

    for(int n=0; n<1000000; ++n) {
        arr[n] = distr(gen);
        }
    
    int n = sizeof(arr) / sizeof(arr[0]);

    float sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    
    float avg = sum / n;
    cout << "v2\nOrtalama (bolme islemiyle): " << avg;

    float sumfunc = accumulate(arr, arr + n, 0.0f);
    float avgfunc = sumfunc/n;

    cout << "\nOrtalama (fonksiyonla): " << avgfunc;

    cout << "\nArray'in boyutu: " << n << "\n";

    float onetoavg;

    for (int i = 0; i < avgfunc; i++)
    {
        onetoavg += 1;
    }
    
    cout << "1'den ortalamaya kadar olan sayıların toplamı (1 eklemeli): " << onetoavg << "\n\n";

}

int main() {

    for (int i = 0; i < 100; i++)
    {
        func1();
        func2();
    }
    
}
