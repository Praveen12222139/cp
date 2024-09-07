#include <bits/stdc++.h>
using namespace std;


 bool solve(string &s,int st,int e,vector<vector<int>>&dp){
        if(st>=e){
            return 1;
        }
        if(dp[st][e]!=-1) return dp[st][e];

        if(s[st]==s[e]){
            return dp[st][e]=solve(s,st+1,e-1,dp);
        }
        return dp[st][e]=0;
    }
int palindromicSubstrings(string& s)
{
     int maxilen=INT_MIN;
        int n=s.length();
        int cnt=0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j,dp)){
                cnt++;// for counting all the palindromic substrings 
                  
                }
            }
        }
        return cnt;

}
int main(){
    string s;
    cin>>s;
   cout<< palindromicSubstrings(s);
}