#include <bits/stdc++.h>
using namespace std;
long long  houseRobber2(int n,vector<int>a,vector<int>&dp){
        if(n<0) return 0;

        if(n==0) dp[n]= a[0];
        if(dp[n]!=-1) return dp[n];

        int take=houseRobber2(n-2,a,dp)+a[n];
        int nottake=houseRobber2(n-1,a,dp);
        return dp[n]=max(take,nottake);
}
int main(){
    int n;
    cin>>n;
    
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    if(n==1){
        cout<<v[0];
        return 0;
       
    }
    vector<int>temp,temp2;
    for(int i=0;i<n;i++){
        if(i!=0) temp.push_back(v[i]);
        if(i!=n-1) temp2.push_back(v[i]);
    }

        int m=temp.size();
    vector<int>dp1(m+1,-1);
    vector<int>dp2(m+1,-1);
    cout<<max(houseRobber2(m-1,temp,dp1),houseRobber2(m-1,temp2,dp2));


    return 0;
}