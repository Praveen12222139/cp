#include <bits/stdc++.h>

using namespace std;
const int  N=10000;

int fib(int n,vector<int>dp) {
    if (n == 0 || n == 1) {
        return 1;
    }
    if(dp[n]!=-1) return dp[n];
    return dp[n]= fib(n - 1,dp) + fib(n - 2,dp);
}

int no_clim_stairs(int n,vector<int>dp) {
    if (n == 0) {
        return 1; 
    }
    if (n == 1) {
        return 1; 
    }
    if(dp[n]!=-1) return dp[n];
    dp[n]=no_clim_stairs(n - 1,dp)+ no_clim_stairs(n - 2,dp);
    return dp[n];
}

int diif_clim(int n,int i){
    if(i==n){
        return  1;
    }
    if(i>n){
        return 0;
    }
    int ans1=diif_clim(n,i+1);
    int ans2=diif_clim(n,i+2);
    return ans1+ans2;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int>dp(n+1,-1);
    cout << "Fibonacci: " << fib(n,dp) << endl;
    cout << "Ways to climb stairs: " << no_clim_stairs(n,dp) << endl;
    cout<<diif_clim(n,0);
    return 0;
}
