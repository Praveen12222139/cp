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
    int n;
    cin >> n;
    vector<int> v(n + 1); 
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector<int> ans(n + 1, -1); 
    ans[v[1]] = 0; 
    bool flag = true;

    for(int i = 2; i <= n; i++) {
        int curr = v[i];

      
        bool left_filled = (curr > 1 && ans[curr - 1] != -1);
        bool right_filled = (curr < n && ans[curr + 1] != -1);

        if(left_filled || right_filled) {
            ans[curr] = 0; 
        } else {
            flag = false;
            break;
        }
    }

    if(flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }


    
    // vector<string> results;
    
 
    //     int n;
    //     cin >> n;
        
    //     vector<int> seats(n);
    //     unordered_set<int> occupied;
    //     bool valid = true;
        
    //     for (int i = 0; i < n; ++i) {
    //         cin >> seats[i];
    //     }
        
    //     for (int i = 0; i < n; ++i) {
    //         int seat = seats[i];
    //         if (i == 0) {
       
    //             occupied.insert(seat);
    //         } else {
               
    //             if (occupied.find(seat - 1) != occupied.end() || occupied.find(seat + 1) != occupied.end()) {
    //                 occupied.insert(seat);
    //             } else {
    //                 valid = false;
    //                 break;
    //             }
    //         }
    //     }
        
    //     results.push_back(valid ? "YES" : "NO");
    
    
    // for (const auto& result : results) {
    //     cout << result << endl;
    // }
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