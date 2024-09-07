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

int ans(int n, int W, const vector<int>& values, const vector<int>& weight, vector<vector<int>>& dp) {
    
    if (n < 0 || W <= 0) {
        return 0;
    }

    
    if (dp[n][W] != -1) return dp[n][W];

    // Option 1: Not take the current item
    int nottake = ans(n - 1, W, values, weight, dp);

    // Option 2: Take the current item (if possible)
    int take = INT_MIN;
    if (weight[n] <= W) {
        take = values[n] + ans(n - 1, W - weight[n], values, weight, dp);
    }

    // Store and return the maximum of taking or not taking the current item
    return dp[n][W] = max(take, nottake);
}

void solve() {
    int n, W;
    cin >> n >> W;

    vector<int> weight(n);
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    // Initialize the dp array with -1
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));

    cout << ans(n - 1, W, values, weight, dp) << endl;
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