#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    float arr[10000] = {0};

    for(int n = 0; n < 10000; ++n) {
        arr[n] = 10000 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 10000));
    }
    
    int n = sizeof(arr) / sizeof(arr[0]);
    float max = *max_element(arr, arr + n);
    int maxrounded = round(max);

    cout << "Max Element = " << max;

    float total = 0;

    for (int k = 0; k < 10000; k++) {
        total += arr[k];
    }

    cout << "\n1'den max degere kadar olan toplam = " << (maxrounded * (maxrounded + 1)) / 2;

    cout << "\nToplam: " << total << "\n";

    return 0;
}
