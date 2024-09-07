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
const int letters = 26;
void solve() {
   int n, q;
        cin >> n >> q;
        string a, b;
        cin >> a >> b;
        vector<vector<int>> prefix_ofA(n + 1, vector<int>(letters, 0));
        vector<vector<int>> prefix_ofB(n + 1, vector<int>(letters, 0));
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                for (int j = 0; j <letters; j++) {
                    prefix_ofA[i + 1][j] = prefix_ofA[i][j];
                    prefix_ofB[i + 1][j] = prefix_ofB[i][j];
                }
            }
            prefix_ofA[i + 1][a[i] - 'a']++;
            prefix_ofB[i + 1][b[i] - 'a']++;
        }

        while (q--) {
            int A, B;
            cin >> A >> B;
            A--;B--;  
            vector<int> freq_a(letters, 0);
            vector<int> freq_b(letters, 0);

            for (int j = 0; j < letters; j++) {
                freq_a[j] = prefix_ofA[B + 1][j] - prefix_ofA[A][j];
                freq_b[j] = prefix_ofB[B + 1][j] - prefix_ofB[A][j];
            }

            int CNT = 0;
            for (int j = 0; j <letters; j++) {
                CNT += abs(freq_a[j] - freq_b[j]);
            }
            cout << CNT / 2 << endl;
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