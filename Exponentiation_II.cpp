#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
#define mod 1000000007



ll mod_exp(ll a, ll b, ll m) {
    if (m == 1) return 0;
    ll result = 1;
    a = a % m;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }
    return result;
}

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    
    
    ll exp = mod_exp(b, c, mod -1);
    
   
       ll result = mod_exp(a, exp, mod);
    
    cout << result << endl;
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
