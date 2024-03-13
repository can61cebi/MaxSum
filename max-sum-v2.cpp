#include <iostream>
#include <random>
#include <algorithm>
#include <numeric>

using namespace std;



int main() {

    random_device rd; // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    uniform_real_distribution<> distr(1000000, 10000000); // define the range

    float arr[1000000];

    for(int n=0; n<1000000; ++n) {
        arr[n] = distr(gen);
        }
    
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // Print the array
    /*cout << "Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";*/

    float sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    
    float avg = sum / n;
    cout << "\nortalama (bolme islemiyle): " << avg;

    float sumfunc = accumulate(arr, arr + n, 0.0f);
    float avgfunc = sumfunc/n;

    cout << "\nortalama (fonksiyonla): " << avgfunc;

    cout << "\narray'in boyutu: " << n << "\n";

    float onetoavg;

    for (int i = 0; i < avgfunc; i++)
    {
        onetoavg += 1;
    }
    
    cout << "1'den ortalamaya kadar olan sayıların toplamı (1 eklemeli): " << onetoavg << "\n";

}