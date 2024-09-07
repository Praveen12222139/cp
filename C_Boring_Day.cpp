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

void solve()
{  
    ll n,l,r;
    cin >> n >> l >> r;

    vi<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans = 0;
    ll sum = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i] > r)
        {
            sum = 0;
            continue;
        }
        if(sum >= r)
        {
            sum = 0;
        }
        if(a[i] >= l && a[i] <= r)
        {
            sum = 0;
            ans++;
            continue;
        }
        sum += a[i];
        if(sum <= r && sum >= l)
        {
            sum = 0;
            ans++;
        }
    }
    if(sum <= r && sum >= l)
    {
        ans++;
    }
    cout << ans << endl;
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