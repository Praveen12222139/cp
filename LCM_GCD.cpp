#include <bits/stdc++.h>
using namespace std;


int euclidGCD (long a, long b) {
    if (b == 0) return a;
    return euclidGCD(b, a%b);
}

long long lcm(long long a, long long b) {
    return (a * b)/euclidGCD(a, b);
    // as we know that GCD(a,b)*LCM(a,b)=a*b;
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << lcm(a, b) << std::endl;
    return 0;
}