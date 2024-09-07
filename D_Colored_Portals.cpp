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
    int n, m;
    cin >> n >> m;
    vector<string> v(n+1);
    
    for(int i = 1; i <=n; i++) {
        cin >> v[i];
    }
    
    while (m--) {
        int a, b;
        cin >> a >> b;
  

        if (v[a][0] == v[b][0] || v[a][1] == v[b][1] || v[a][1] == v[b][0] || v[a][0] == v[b][1]) {
            cout << abs(a - b) << endl;
        } else {
        
                int pos = -1;
                int pos2 = -1;
                int ans = INT_MAX, ans2 = INT_MAX;
                
              
                int maxi=max(a,b);
                int mini=min(a,b);
                for(int i = 1; i< maxi; i++) {
                    if(v[i][0] == v[maxi][0] || v[i][1] == v[maxi][1] || v[i][1] == v[maxi][0] || v[i][0] == v[maxi][1]) {
                        pos = i;
                    }
                }
   
                for(int i = maxi + 1; i <=n; i++) {
                    if(v[i][0] == v[mini][0] || v[i][1] == v[mini][1] || v[i][1] == v[mini][0] || v[i][0] == v[mini][1]) {
                        pos2 = i;
                        break;
                    }
                }

       
                if(pos != -1) {
                    ans = abs(maxi - pos)+abs(pos-mini);
                }
                if(pos2 != -1) {
                    ans2 = abs(mini - pos2)+abs(pos2-maxi);
                }
         
                int final_ans = min(ans, ans2);
                if(final_ans != INT_MAX) {
                    cout << final_ans << endl;
                } else {
                    cout << -1 << endl;
                }
            
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