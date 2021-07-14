#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n == 0 || n == 1) {
        return false;
    }

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

void printPrimeNumbers(int range) {
    for (int i = 1; i <= range; i++) {
        if (isPrime(i)) {
            cout << i << ", ";
        }
    }
}

int main() {
    int range = 100;

    printPrimeNumbers(range);

    return 0;
}