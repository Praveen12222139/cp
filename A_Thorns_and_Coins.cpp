#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int max_coins_for_path(const string &path, int n) {
    vector<int> dp(n, -1);  
    dp[0] = 0;      
    for (int i = 0; i < n; ++i) {
        if (dp[i] == -1) continue;  
        
                if (i + 1 < n && path[i + 1] != '*') {
            dp[i + 1] = max(dp[i + 1], dp[i] + (path[i + 1] == '@' ? 1 : 0));
        }
        
      if (i + 2 < n && path[i + 2] != '*') {
            dp[i + 2] = max(dp[i + 2], dp[i] + (path[i + 2] == '@' ? 1 : 0));
        }
    }
    
    if (n == 1) {
        return dp[0];
    } else {
        return max(dp[n - 1], dp[n - 2]);
    }
}

int main() {
    int t;
    cin >> t;
    
    vector<int> results;
    for (int i = 0; i < t; ++i) {
        int n;
        string path;
        cin >> n >> path;
        results.push_back(max_coins_for_path(path, n));
    }
    
    for (int result : results) {
        cout << result << endl;
    }
    
    return 0;
}
