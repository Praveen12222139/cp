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


const int N = 1e5 + 10;
const int MAX_A = 70;
const int TOTAL_PRIMES = 19;
const int MOD = 1e9 + 7;
 
int n;
int poss[MAX_A + 1][2];
const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
int mask[MAX_A + 1];
int dp[MAX_A + 1][1 << TOTAL_PRIMES];
 
void solve(){
	cin >> n;
 
	for (int i = 1; i <= MAX_A; i++) poss[i][0] = 1;
 
	for (int i = 1; i <= n; i++) {
		int a;
    cin>>a;
 
		int tmp = poss[a][0];
		poss[a][0] = (poss[a][0] + poss[a][1]) % MOD;
		poss[a][1] = (poss[a][1] + tmp) % MOD;
	}
 
	for (int i = 1; i <= MAX_A; i++) {
		for (int p = 0; p < TOTAL_PRIMES; p++) {
			int cnt = 0;
			int at = i;
 
			while (at % primes[p] == 0) {
				at /= primes[p];
				cnt++;
			}
 
			if (cnt & 1) mask[i] |= (1 << p);
		}
	}
 
	int max_mask = 1 << TOTAL_PRIMES;
	dp[0][0] = 1;
	
	for (int at = 1; at <= MAX_A; at++)
		for (int msk = 0; msk < max_mask; msk++) {
			dp[at][msk] = dp[at - 1][msk] * 1LL * poss[at][0] % MOD;
 
			dp[at][msk] += dp[at - 1][msk ^ mask[at]] * 1LL * poss[at][1] % MOD;
			dp[at][msk] %= MOD;
		}
 
	cout << (dp[MAX_A][0] + MOD - 1) % MOD << endl;
 
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}