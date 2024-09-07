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
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    vi<int> v(n);
    int evn = 0;
    bool flag = true;
    
    // Input the array and count even numbers
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] % 2 == 0) evn++;
        if (v[i] % k == 0) {
            flag = false;
        }
    }
    
    // If any element is divisible by k, return 0
    if (!flag) {
        cout << 0 << endl;
        return;
    }

    // Special case for k == 4
    if (k == 4) {
        int t=max(0, 2 - evn);
        ans=min(t,1);
    } else {
        // Find maximum and minimum elements in the array
        int max_ele = *max_element(v.begin(), v.end());
        int min_ele = *min_element(v.begin(), v.end());
        
        if (max_ele == min_ele) {
            

        }
        else if(max_ele!= min_ele){
               int  ans1 = abs((k * 2) - max_ele);
               int   ans2 = abs(k - min_ele);
                 min(ans1,ans2);
        }
        // else {
            
        //     ans = abs(k - min_ele);
        // }
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