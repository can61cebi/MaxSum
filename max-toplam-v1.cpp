#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

int main() {

    random_device rd; // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    uniform_real_distribution<> distr(10000, 20000); // define the range

    float arr[10000];

    for(int n=0; n<10000; ++n) {
        arr[n] = distr(gen);
        }
    
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // Print the array
    /*cout << "Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";*/
 
    // Find the maximum element
    //int max = round(*max_element(arr, arr + n));
    float max = *max_element(arr, arr + n);
    int maxrounded = round(max);

    cout << "Max Element = " << max;

    float total = 0;

    for (int k = 0; k < 10000; k++)
    {
        total+=arr[k];
    }

    cout << "\n1'den max degere kadar olan toplam = " << (maxrounded*maxrounded+1)/2;

    cout << "\nToplam: " << total << "\n";
    
}