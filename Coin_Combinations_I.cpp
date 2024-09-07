#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int ans(int target,vector<int> &coins, vector<int> &dp) {
    if (target == 0) return 1;
    if (dp[target] != -1) return dp[target];

    int ways = 0;
    for (int coin : coins) {
        if (target >= coin) {
            ways = (ways + ans(target - coin, coins, dp)) % MOD;
        }
    }
    dp[target] = ways;
    return dp[target];
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    vector<int>dp(x+1,-1);
    cout << ans(x, coins, dp) << endl;

    return 0;
}