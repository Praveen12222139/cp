//Jai Bajrang Bali
#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define vi vector
#define pb push_back
#define take(i,a) for(int i=0;i<a;i++)
#define mod 1000000007
#define srt(v) sort(v.begin(),v.end())
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())
#define all(v)  v.begin(),v.end()
//int ind = max_element(all(a)) - a.begin();
#define dis(v)  distance(v.begin(),max_element(all(v)))
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));// Apply after Sorting
// else only consecutive duplicates would be removed 
//s.erase(unique(s.begin(), s.end()), s.end());
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}
ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
ll mod_sub(ll a, ll b) {a = a % mod; b = b % mod; return (((a - b + mod) % mod) + mod) % mod;}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}



int dp[2000010]; 

int compute_h(int r, int g) {
    int h = 0;
    while (h * (h + 1) / 2 <= r + g) h++;
    return h - 1;  
}

void solve() {
    int r, g;
    cin >> r >> g;
    int h = compute_h(r, g);
    int sum = h * (h + 1) / 2;  
    dp[0] = 1;  

  
    for (int i = 1; i <= h; i++) {
        for (int j = r; j >= i; j--) {
            dp[j] = (dp[j] + dp[j - i]) %mod;
        }
    }

    int ans = 0;
    for (int i = 0; i <= r; i++) {
        if (sum - i <= g) {
            ans = (ans + dp[i]) %mod;
        }
    }

    cout << ans << endl;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}