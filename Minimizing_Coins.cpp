#include <bits/stdc++.h>
using namespace std;

int ans(int target, vector<int> &coins, vector<int> &dp) {
    if (target == 0) return 0;
    if (dp[target] != -1) return dp[target];

    int ways = INT_MAX;
    for (int coin : coins) {
        if (target >= coin) {
            int sub_res = ans(target - coin, coins, dp);
            if (sub_res != INT_MAX) {
                ways = min(ways, sub_res + 1);
            }
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
    vector<int> dp(x + 1, -1);
    int result = ans(x, coins, dp);
    if (result == INT_MAX) {
        cout << -1 << endl; 
    } else {
        cout << result << endl;
    }
    return 0;
}
