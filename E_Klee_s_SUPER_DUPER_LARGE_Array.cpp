#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
ll largest_prime_less_than(ll n) {
    if (n <= 2) return 1;

    // Start checking from n-1 downwards
    for (ll i = n - 1; i >= 2; --i) {
        bool isPrime = true;
        for (ll j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) return i;
    }
    return -1; // Edge case
}

ll minimum_x(ll n, ll k) {
    ll p = largest_prime_less_than(n);

    if (p == -1) return -1; 


    ll anth = k + (p - 1) * 1;
    ll sum_till_p = p * (k + anth) / 2;
    ll total_sum = n * (k + (k + n - 1)) / 2;

   

    ll ans = abs(total_sum - 2 * sum_till_p);
    return ans%mod;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    cout << minimum_x(n, k) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
