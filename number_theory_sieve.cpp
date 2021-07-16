#include <bits/stdc++.h>
using namespace std;

void sieve(int n) {
    vector <bool> isPrime(n + 1, true);

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            cout << i << endl;

            for (int j = i * i; j <= n; j += i) {

                isPrime[j] = false;
            }
        }
    }
}

void NumberOfDivisorSieve(int n) {
    vector <int> number_of_divisors(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            number_of_divisors[j]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << i << ": " << number_of_divisors[i] << endl;
    }
}

void SumOfDivisorSieve(int n) {
    vector <int> sum_of_divisors(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            sum_of_divisors[j] += i;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << i << ": " << sum_of_divisors[i] << endl;
    }
}

void ProductOfDivisorSieve(int n) {
    vector <long long int> product_of_divisors(n + 1, 1);

    for (long long int i = 1; i <= n; i++) {
        for (long long int j = i; j <= n; j += i) {
            product_of_divisors[j] *= i;
        }
    }

    for (long long int i = 1; i <= n; i++) {
        cout << i << ": " << product_of_divisors[i] << endl;
    }
}


int main() {
    int n = 100;

    cout << "Prime numbers within " << n <<": " << endl;
    sieve(n);
    cout << endl;

    cout << "Number of Divisors of numbers within " << n <<": " << endl;
    NumberOfDivisorSieve(n);
    cout << endl;

    cout << "Sum of Divisors of each number within " << n <<": " << endl;
    SumOfDivisorSieve(n);
    cout << endl;

    cout << "Product of Divisors of each number within " << n <<": " << endl;
    ProductOfDivisorSieve(n);
    cout << endl;

    return 0;
}
