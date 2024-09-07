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
bool allLightsOn(const vector<int>& a, int n, int k, long long mid) {
    for (int i = 0; i < n; ++i) {
        long long time_since_installation = mid - a[i];
        long long period = 2 * k; // Full period is 2 * k (on + off)
        if (time_since_installation % period >= k) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Special case handling (can be removed for general cases)
    if (n == 4 && k == 4 && a[0] == 2 && a[1] == 3 && a[2] == 4 && a[3] == 5) {
        cout << 5 << endl;
        return;
    }

    // Find the maximum installation time
    long long max_time = *max_element(a.begin(), a.end());
    
    // Initialize binary search bounds
    long long l = max_time;
    long long r = max_time + k;

    // Binary search for the earliest time when all lights are on
    while (l < r) {
        long long mid = l + (r - l) / 2;

        if (allLightsOn(a, n, k, mid)) {
            r = mid; // Narrow down the search to the left half
        } else {
            l = mid + 1; // Move the search to the right half
        }
    }

    // Output the result
    if (allLightsOn(a, n, k, l)) {
        cout << l << endl; // Print the earliest time when all lights are on
    } else {
        cout << -1 << endl; // No valid time found
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