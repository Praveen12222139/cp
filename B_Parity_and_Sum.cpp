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

void solve(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(auto &it:v)cin>>it;
    int cnt1=0;
    for(auto it:v)if(it&1)cnt1++;
    if(cnt1==0 || cnt1==n){
        cout<<0<<endl;
        return;
    }
    vector<int>v1,v2;
    for(auto it:v){
        if(it&1)v1.push_back(it);
        else v2.push_back(it);
    }
    sort(all(v2));
    sort(all(v1));
    ll temp=v1.back();
    ll ans=0;
 
    for(auto it:v2){
        if(temp<it){
            ans+=2;
            temp=(it*2)+temp;
        }
        else{
            ans++;
            temp=it+temp;
        }
    }
    ll ans1=0;
    reverse(all(v2));
    temp=v1.back();
    for(auto it:v2){
        if(temp<it){
            ans1+=2;
            temp=(it*2)+temp;
        }
        else{
            ans1++;
            temp=it+temp;
        }
    }
    cout<<min(ans,ans1)<<endl;
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