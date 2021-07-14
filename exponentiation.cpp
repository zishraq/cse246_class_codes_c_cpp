#include <iostream>
using namespace std;

// O(n)
int exponentiation(int value, int power) {
    int answer = 1;

    for (int i = 0; i < power; i++) {
        answer = answer * value;
    }

    return answer;
}

// O (log2 n)
int fastExponentiation(int value, int power) {
    if (power == 0) {
        return 1;
    }

    if (power == 1) {
        return power;
    }

    int result = fastExponentiation(value, power/2);

    if (power % 2 == 1) {
        return value * result * result;
    }

    return result * result;
}

int main() {

    // sum = 1
    // [1, 2, 3, 4, 5]
    // sum = sum * i (loop)

    cout << "Hello, World!" << endl;
    return 0;
}
