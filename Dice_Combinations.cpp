#include <bits/stdc++.h>
using namespace std;
int dp[100];
int mod=1000000007;
int solve(int sum, int n)
{

        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <=n; i++)
        {
                for (int j = 1; j <= 6; j++)
                {
                        if(i-j>=0){
                                dp[i]=dp[i]%mod+dp[i-j]%mod;
                        }
                        
                }
        }
        // if(sum==n) return 1;
        // if(sum>n) return 0;
        // int cnt = 0;
        // for (int i = 1; i <= 6; i++)
        // {
        //         cnt += solve(sum + i, n);
        // }
        // return cnt;

        return dp[n]%mod;
}

int main()
{
        int a;
        cin >> a;

        cout << solve(0, a);
        return 0;
}