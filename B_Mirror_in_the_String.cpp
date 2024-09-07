//Jai Bajrang Bali
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void solve() {
    long long n;
    cin >> n;
    string a;
    cin>>a;
    string ans="";
    for(auto i:a){
        ans+=i;
        break;
    }
    for(int i=1;i<n;i++){
        if(a[i-1]<a[i]){
         break;
        }
        else ans+=a[i];
    }
 string  temp=ans;
reverse(temp.begin(),temp.end());
cout<<ans+temp<<endl;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}