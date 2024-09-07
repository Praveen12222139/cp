//Jai Bajrang Bali
#include <iostream>
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int maxCnt = 0;  // To keep track of the maximum count of consecutive characters
    int currentCnt = 1;  // To keep track of the current count of consecutive characters

    for (int i = 1; i < n; i++) {  // Start from the second character
        if (s[i] == s[i - 1] &&s[i]!=s[i+1]) {
            currentCnt++;
        } else {
            if (currentCnt > maxCnt) {
                maxCnt = currentCnt;  // Update maximum if the current streak is greater
            }
            currentCnt = 1;  // Reset current count for the new character
        }
    }

    // Check last streak
    if (currentCnt > maxCnt) {
        maxCnt = currentCnt;
    }

    cout << maxCnt << endl;
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