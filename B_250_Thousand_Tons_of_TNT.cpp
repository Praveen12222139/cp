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
ll expo(ll a, ll b, ll m) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}



void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    vector<ll> prx;
    ll maxi = 0;
    ll sum = 0;


    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
        prx.push_back(sum);
    }
   
    for (ll i = 1; i <= n; i++) {
        vector<ll> res;
        if (n % i == 0) {
            for (ll j = i; j <= n; j += i) {
                sum = prx[j - 1] - (j - i - 1 >= 0 ? prx[j - i - 1] : 0);
                res.push_back(sum);
            }
            sort(res.begin(), res.end()); 
      
            maxi = max(maxi, res[(ll)res.size() - 1] - res[0]); 
        }
    }
    
    cout << maxi << endl;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}