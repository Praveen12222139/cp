
//Jai Bajrang Bali
#include <bits/stdc++.h>
using namespace std;

bool check(int mid,vector<int>&a){
    int f = mid;
    for(auto &x:a){
        
        f += x;
        if(f <= 0)return false;
    }
    return true;
}
void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    int l = 0,r = INT_MAX,res = INT_MAX;

    while(l <= r){
        int mid = (l+r)/2;
        if(check(mid,a)){
            res = min(res,mid);
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << res << endl;
}
int main() {
    solve();
    return 0;
}