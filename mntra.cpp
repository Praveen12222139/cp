#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int ind,k;
    cin >> s;
    cin >> ind;
    cin >> k;
    s = '$' + s;
    char ans = s[ind];
    for(int i = 1;i < ind;i++){
        int req = ind - i;
        if(req > k) break;
        else {
            if(ans > s[i]){
                ans = s[i];
            }
        }
    }
    for(int i = ind + 1;i < s.size();i++){
        int req = i - ind;
        if(req > k) break;
        else {
            if(ans > s[i]){
                ans = s[i];
            }
        }
    }
    cout<<ans<<endl;
}
