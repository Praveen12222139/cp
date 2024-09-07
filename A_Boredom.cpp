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
void solve() {
    ll x;
    cin >> x;
    vector<int> v(x);
    for (int i = 0; i < x; ++i) {
        cin >> v[i];
    }

    int maxn = 100000 + 16;
    vector<ll> sum(maxn + 1, 0);


    for (int num : v) {
        sum[num] += num; // taking frequency of each elements (how many times they are occuring )
    }

    vector<ll> dp(maxn + 1, 0); // maximum size of dp array 

    dp[0] = sum[0];
    dp[1] = max(sum[0], sum[1]);

    for (int i = 2; i <= maxn; ++i) {
        // there are 2 choices 
        //1 is that we dont take the i then we will move to i-1 element
        // 2 if select the ith element then we cannot select the i-1 element so we landed to the i-2 element and
        // we will take that element along with its all occurences
        // now will take maimum among both 
        dp[i] = max(dp[i - 1], dp[i - 2] + sum[i]);
    }
    cout << dp[maxn] << endl;
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