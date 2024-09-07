#include <bits/stdc++.h>
using namespace std;
bool is_up(string s){
    for(auto i:s){
        if(!isupper(i)){
            return false;
            break;
        }
    }
    return true;
}
bool is_lo(string s){
    for(auto i:s){
        if(!islower(i)){
            return false;
            break;
        }
    }
    return true;
}
int main(){
    int a;
    cin>>a;
    while(a--){
        int x;
        cin>>x;
        string s;
        cin>>s;
        if(is_up(s) || is_lo(s)){
            cout<<0<<endl;
            continue;
        }
        for(auto &i:s){
            i=tolower(i);
        }
        unordered_map<char,int>hm;
        for(auto i:s){
            hm[i]++;
        }
        int cnt=0;
        for(auto i:hm){
            if(i.second==1){
                cnt++;
            }
        }
        cout<<cnt*x<<endl;
    }
    return 0;

}