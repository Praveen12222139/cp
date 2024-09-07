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

long long  cnt_max(vi<vi<char>> a){
    int n = a.size();
    int m = a[0].size();
    ll res = 0;
    for(int row = n -1;row >= 0;row--){
        for(int col = 0;col < m;col++){
            if(a[row][col] == '#')break;
            int nrow = row;
            while(nrow < n && a[nrow][col] == '.'){
                a[nrow][col] = '#';
                nrow++;
                res++;
            }
        }
    }
    return res;
}

ll cnt_min(vi<vi<char>> a){
    int n = a.size();
    int m = a[0].size();
    ll res = 0;
    for(int row = 0;row < n;row++){
        for(int col = 0;col < m;col++){
            if(a[row][col] == '#')break;
            int nrow = row;
            while(nrow < n && a[nrow][col] == '.'){
                a[nrow][col] = '#';
                nrow++;
                res++;
              
            }
        }
       
    }
    return res;
}

int main(){
    int n,m;
    cin >> n >> m;
    vi<vi<char>> a(n, vi<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    ll mn = cnt_min(a);
    ll mx = cnt_max(a);
    cout << mn << endl;
    cout <<mx<<endl;
}