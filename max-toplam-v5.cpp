#include <iostream>
#include <vector>
#include <thread>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <random>
#include <mutex>

using namespace std;

const int DATA_SIZE = 10000000;
const int NUM_THREADS = 11;
std::mutex mtx;

void islem(int thread_id, long long& yuvarlanmis_sayi, long long& toplam, long long& total_onetoavg) {
    std::mt19937 generator(static_cast<unsigned int>(time(nullptr)) + thread_id);
    std::uniform_int_distribution<int> distribution(1000000, 10000000 - 1);

    vector<int> data(DATA_SIZE / NUM_THREADS);
    long long local_sum = 0;
    int local_max = 0;

    for (int& val : data) {
        val = distribution(generator);
        local_sum += val;
        local_max = max(local_max, val);
    }

    std::lock_guard<std::mutex> guard(mtx);
    yuvarlanmis_sayi = max(yuvarlanmis_sayi, static_cast<long long>(round(local_max)));
    toplam += local_sum;

    long long avg = toplam / DATA_SIZE;
    total_onetoavg = (avg * (avg + 1)) / 2;
}

int main() {
    long long yuvarlanmis_sayi = 0, toplam = 0, ilkden_orta_toplam = 0;

    for (int i = 0; i < 100; ++i) {
        vector<thread> threads;

        for (int t = 0; t < NUM_THREADS; ++t) {
            threads.emplace_back(islem, t, ref(yuvarlanmis_sayi), ref(toplam), ref(ilkden_orta_toplam));
        }

        for (auto& th : threads) {
            th.join();
        }

        cout << i + 1 << ". islem"
             << ": En buyuk (Yuvarlanmis) = " << yuvarlanmis_sayi
             << ", Toplam = " << toplam
             << ", 1'den ortalamaya kadar toplam = " << ilkden_orta_toplam << endl;

        yuvarlanmis_sayi = 0;
        toplam = 0;
        ilkden_orta_toplam = 0;
    }

    return 0;
}