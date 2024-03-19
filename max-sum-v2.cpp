#include <iostream>
#include <random>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {

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
    cout << "Ortalama (bolme islemiyle): " << avg;

    float sumfunc = accumulate(arr, arr + n, 0.0f);
    float avgfunc = sumfunc/n;

    cout << "\nOrtalama (fonksiyonla): " << avgfunc;

    cout << "\nArray'in boyutu: " << n << "\n";

    float onetoavg;

    for (int i = 0; i < avgfunc; i++)
    {
        onetoavg += 1;
    }
    
    cout << "1'den ortalamaya kadar olan sayıların toplamı (1 eklemeli): " << onetoavg << "\n";

    return 0;
}