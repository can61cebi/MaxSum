#include <iostream>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <csignal>
#include <exception>
#include <unistd.h>

using namespace std;

class SignalException : public exception {
public:
    const char* what() const throw () {
        return "Signal received!";
    }
};

void signalHandler(int signum) {
    const char* message = "Critical error signal received. Program will terminate.\n";

    write(STDERR_FILENO, message, strlen(message));
    _exit(EXIT_FAILURE);
}

void func1() {

    srand(static_cast<unsigned int>(time(nullptr)));

    int arr[10000000] = {0};

    for(int n = 0; n < 1000000; ++n) {
        arr[n] = 1000000 + static_cast<int>(rand()) / (static_cast<int>(RAND_MAX / 90000000));
    }
    
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = *max_element(arr, arr + n);
    int maxrounded = round(max);

    int total = 0;

    for (int k = 0; k < 10000; k++) {
        total += arr[k];
    }
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

    int sumfunc = accumulate(arr, arr + n, 0.0f);
    int avgfunc = sumfunc / n;

    int onetoavg = 0;

    for (int i = 1; i <= avgfunc; i++) {
        onetoavg += i;
    }
//test
}

int main() {
    signal(SIGINT, signalHandler);
    signal(SIGSEGV, signalHandler);

    try {
        for (int i = 0; i < 100; i++) {
            func1();
            func2();
        }
    } catch (const SignalException& e) {
        cout << "SignalException caught: " << e.what() << endl;
        return EXIT_FAILURE;
    } catch (...) {
        cout << "An unexpected exception occurred." << endl;
    }

    return EXIT_SUCCESS;
}
