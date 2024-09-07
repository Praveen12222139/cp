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

int cal_gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void solve() {
    int n;
    cin >> n;
    vi<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];

    }
    vi<int>v2;
    for(int i=0;i<n-1;i++){
        v2.push_back(cal_gcd(v[i],v[i+1]));
    }
    int cnt=0;
    // for(auto i:v2){
    //     cout<<i<<" ";
    // }
    // cout<<endl;

     for(int i=0;i<v2.size()-1;i++){
    if(v[i]>v[i+1]){
        cnt++;
    }
   }
   if(v2.size()==2){
     if(cnt>2){
    cout<<"NO"<<endl;
   }
   else{
    cout<<"YES"<<endl;
   }
   }
   if(v2.size()>3){
  if(cnt>2){
    cout<<"NO"<<endl;
   }
   else{
    cout<<"YES"<<endl;
   }
   }
 
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