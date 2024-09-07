#include <iostream>
using namespace std;

const int mod = 1000000007;

long long modpower(long long base, long long exponent) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}

void solve() {
    int l, r, k; 
    cin >> l >> r >> k; 

    if (k >= 10) { 
        cout << 0 << endl; 
        return; 
    } 

    long long av = 10LL / k;  
    if (10 % k) { 
        av++; 
    } 

    long long rght = modpower(av, r); 
    long long lft = modpower(av, l); 

    long long ans = (rght - lft + mod) % mod; 
    cout << ans << endl; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
