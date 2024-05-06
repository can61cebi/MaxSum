#include <iostream>
#include <random>
#include <vector>
#include <thread>
#include <numeric>
#include <mutex>

using namespace std;

const int DIZI_BOYUT = 100000000;
const int THREAD_SAYI = 8;
const int FONKSIYON_TEKRAR = 100;

std::mutex mtx;

void func() {
    mt19937 gen(random_device{}());
    uniform_int_distribution<> dis(1000000, 9999999);

    vector<int> arr(DIZI_BOYUT);
    for (int& n : arr) {
        n = dis(gen);
    }

    long long total = accumulate(arr.begin(), arr.end(), 0LL);
    {
        lock_guard<mutex> lock(mtx);
    }
}

void thread_islem(int adet, void (*func)()) {
    for (int i = 0; i < adet; i++) {
        func();
    }
}

int main() {
    vector<thread> threads;

    for (int i = 0; i < THREAD_SAYI; i++) {
        threads.emplace_back(thread_islem, FONKSIYON_TEKRAR / THREAD_SAYI, func);
    }

    for (auto& th : threads) {
        th.join();
    }

    return 0;
}
