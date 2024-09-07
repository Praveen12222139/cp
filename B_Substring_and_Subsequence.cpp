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

int ans(string s1,string s2,int size1,int size2){
    int t[size1+1][size2+1];
    int mx=0;
    for(int i=0;i<size1+1;i++){
        for(int j=0;j<size2+1;j++){
            
            if(i==0 || j==0){
                t[i][j]=0;
            }
        }
    }
     for(int i=1;i<size1+1;i++){
        for(int j=1;j<size2+1;j++){
            if(s1[i-1]==s2[j-1]){
                t[i][j]=1+t[i-1][j-1];
                mx=max(mx,t[i][j]);

            }
            else{
                t[i][j]=(t[i-1][j]);
            }
        }
     }
     return  mx;
    
}


void solve() {
    string a,b;
    cin>>a>>b;
    int n1=a.size();
    int n2=b.size();
    
    int res=ans(a,b,n1,n2);
    int res2=n2-res;
    int res3=n1+res2;
    cout<<res3<<endl;

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