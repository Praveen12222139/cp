#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    vector<vector<int>> dp(n, vector<int>(x + 1, 0));

    
    for (int target = 0; target <= x; ++target) {
        if (target % coins[0] == 0) dp[0][target] = 1;
    }

    for (int i = 1; i < n; ++i) {
        for (int target = 0; target <= x; ++target) {
            int nottake = dp[i-1][target];
            int take = 0;
            if (coins[i] <= target) {
                take = dp[i][target - coins[i]];
            }
            dp[i][target] = (take + nottake) % MOD;
        }
    }

    cout << dp[n-1][x] << endl;

    return 0;
}
