#include <iostream>
#include <algorithm>
#include <numeric>
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    float arr[1000000] = {0};

    for(int n = 0; n < 1000000; ++n) {
        arr[n] = 1000000 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 9000000));
    }
    
    int n = sizeof(arr) / sizeof(arr[0]);

    float sum = 0;

    for (int i = 0; i < n; i++) {
        sum = sum + arr[i];
    }
    
    float avg = sum / n;
    cout << "Ortalama (bolme islemiyle): " << avg;

    float sumfunc = accumulate(arr, arr + n, 0.0f);
    float avgfunc = sumfunc / n;

    cout << "\nOrtalama (fonksiyonla): " << avgfunc;

    cout << "\nArray'in boyutu: " << n << "\n";

    float onetoavg = 0;

    for (int i = 1; i <= avgfunc; i++) {
        onetoavg += i;
    }
    
    cout << "1'den ortalamaya kadar olan sayıların toplamı (1 eklemeli): " << onetoavg << "\n";

    return 0;
}
