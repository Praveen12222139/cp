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

ll sum(vector<ll>v,ll mid,ll n){
    ll  cnt=0;
        for(int i=0;i<n;i++){
            if(mid>v[i]){
                cnt+=mid-v[i];
            }
        }
        return cnt;
}

int ans(vector<ll>v,ll n,ll x){
        ll s=1;
        ll  e=1e11;
    
    ll ans=0;
    while(s<=e){
        ll mid=s+(e-s)/2;
       ll  cnt=sum(v,mid,n);
        if(cnt>x){
            e=mid-1;
        }
        else {
            s=mid+1;
        }
       
    }
    return s-1;
}
void solve() {
    int n,x;
    cin >>n>>x;
    vi<ll>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<ans(v,n,x)<<endl;
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