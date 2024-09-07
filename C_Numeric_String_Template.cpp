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
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int a;
    cin>>a;
    while(a--){
        string s;
        cin>>s;
        if(s.size()!=n){
            cout<<"NO"<<endl;
        
        }
        else{
              bool isValid = true;
            int i=0,j=n-1;
                while (i <= j) {
            if ((s[i] == s[j] && v[i] != v[j]) || (s[i] != s[j] && v[i] == v[j])) {
                isValid = false;
                break;
            }
            i++;
            j--;
        }
         if (isValid) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        }
    }
   

        // int n;
        // cin >> n;

        // vector<int> a(n);
        // unordered_map<int, char>hm;
        // unordered_map<char, int>hm2;

        // for (int i = 0; i < n; ++i) {
        //     cin >> a[i];
        // }

        // int m;
        // cin >> m;
        // vector<string> results;

        // while (m--) {
        //     string s;
        //     cin >> s;

        //     if (s.size() != n) {
        //         results.push_back("NO");
        //         continue;
        //     }

        //     hm.clear();
        //     hm2.clear();
        //     bool valid = true;

        //     for (int i = 0; i < n; ++i) {
        //         char c = s[i];
        //         int num = a[i];

        //         if (hm.find(num) != hm.end()) {
        //             if (hm[num] != c) {
        //                 valid = false;
        //                 break;
        //             }
        //         } else {
        //             hm[num] = c;
        //         }

        //         if (hm2.find(c) !=hm2.end()) {
        //             if (hm2[c] != num) {
        //                 valid = false;
        //                 break;
        //             }
        //         } else {
        //             hm2[c] = num;
        //         }
        //     }

        //     if (valid) {
        //         results.push_back("YES");
        //     } else {
        //         results.push_back("NO");
        //     }
        // }

        // for (const string &result : results) {
        //     cout << result << "\n";
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