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

void solve() {
    int n;
    cin >> n;
    
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << endl;
        return;
    }
    if(n==4){
        cout<<"2 4 1 3"<<endl;
        return ;
    }

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i + 1;
    }

    vector<int> v2(n);
    int i = 0;
    int j = n - 1;
    int k = 0;

    while (i <= j) {
        if (i == j) {
            v2[k++] = v[i];
        } else {
            v2[k++] = v[i];
            v2[k++] = v[j];
        }
        i++;
        j--;
    }

    swap(v2[0], v2[n-1]);

    bool flag = true;
    for (int i = 1; i < n; ++i) {
        if (abs(v2[i] - v2[i - 1]) == 1) {
            flag = false;
            break;
        }
    }

    if (flag) {
        for (auto i : v2) {
            cout << i << " ";
        }
        cout << endl;
    } else {
        cout << "NO SOLUTION" << endl;
    }
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