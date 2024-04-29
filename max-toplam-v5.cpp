#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <thread>
#include <numeric>

using namespace std;

const int DIZI_BOYUT = 10000000;
const int THREAD_SAYI = 8;
const int FONKSIYON_TEKRAR = 100;

void func1() {
    mt19937 gen(random_device{}());
    uniform_int_distribution<> dis(1000000, 9999999);

    vector<int> arr(DIZI_BOYUT);
    for (int& n : arr) {
        n = dis(gen);
    }

    int max = *max_element(arr.begin(), arr.end());
    int maxrounded = round(max);

    long long total = accumulate(arr.begin(), arr.end(), 0LL);
}

void func2() {
    mt19937 gen(random_device{}());
    uniform_int_distribution<> dis(1000000, 9999999);

    vector<int> arr(DIZI_BOYUT);
    for (int& n : arr) {
        n = dis(gen);
    }

    long long sum = accumulate(arr.begin(), arr.end(), 0LL);
    int avg = sum / DIZI_BOYUT;

    long long onetoavg = 0;
    for (int i = 1; i <= avg; i++) {
        onetoavg += i;
    }
}

void thread_islem(int numCalls, void (*func)()) {
    for (int i = 0; i < numCalls; i++) {
        func();
    }
}

int main() {
    vector<thread> threads;

    for (int i = 0; i < THREAD_SAYI; i++) {
        threads.emplace_back(thread_islem, FONKSIYON_TEKRAR / THREAD_SAYI, func1);
        threads.emplace_back(thread_islem, FONKSIYON_TEKRAR / THREAD_SAYI, func2);
    }

    for (auto& th : threads) {
        th.join();
    }

    return 0;
}
