#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int countPrimes(int n, int b) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        int num = factorial(i) + b;
        if (isPrime(num)) {
            count++;
        }
    }
    return count;
}

int main() {
    int n, b;
    cin >> n >> b;
    int result = countPrimes(n, b);
    cout << result << endl;
    return 0;
}
