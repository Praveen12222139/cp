//Jai Bajrang Bali
#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define vi vector
#define pb push_back
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

vector<int>ans(int n) {
    vector<int>res(n);
    for (int i = 1; i <= n; ++i) {
        res[i - 1] = i * (i + 1);
    }
    return res;
}

void solve() {
    int t;
    cin>>t;

    vector<vector<int>> results(t);

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        results[i] =ans(n);
    }

    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < results[i].size(); ++j) {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
   
        solve();
    
    return 0;
}