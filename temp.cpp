#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;
#define vi vector
#define pb push_back
#define mod 1000000007
#define srt(v) sort(v.begin(), v.end())
#define mxe(v) *max_element(v.begin(), v.end())
#define mne(v) *min_element(v.begin(), v.end())
#define all(v) v.begin(), v.end()
// int ind = max_element(all(a)) - a.begin();
#define dis(v) distance(v.begin(), max_element(all(v)))
#define unq(v) v.resize(distance(v.begin(), unique(v.begin(), v.end()))); // Apply after Sorting
// else only consecutive duplicates would be removed
// s.erase(unique(s.begin(), s.end()), s.end());
ll inv(ll i)
{
    if (i == 1)
        return 1;
    return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}
ll mod_mul(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a * b) % mod) + mod) % mod;
}
ll mod_add(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a + b) % mod) + mod) % mod;
}
ll mod_sub(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a - b + mod) % mod) + mod) % mod;
}
ll ceil_div(ll a, ll b) { return a % b == 0 ? a / b : a / b + 1; }

int NO_ways(vector<vector<int>> &v, int n, int m, int i, int j, vector<vector<int>> &vis)
{
    if (i < 0 || j < 0 || i >= n || j >= m || v[i][j] == 1 || vis[i][j] == 1) 
        return 0;
    if (i == n - 1 && j == m - 1) 
        return 1;

    vis[i][j] = 1;
    int res = 0;
 
    res += NO_ways(v, n, m, i + 1, j, vis);

    res += NO_ways(v, n, m, i - 1, j, vis);

    res += NO_ways(v, n, m, i, j + 1, vis);
 
    res += NO_ways(v, n, m, i, j - 1, vis);
  
    vis[i][j] = 0;



    return res;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
  
    vector<vector<int>> vis(n, vector<int>(m, 0));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    if (v[0][0] == 1 || v[n-1][m-1] == 1) {
        cout << 0;
    } else {
        cout << NO_ways(v, n, m, 0, 0, vis);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
