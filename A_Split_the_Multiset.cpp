#include <iostream>
using namespace std;

void solve() {
    
        int n, k;
        cin >> n >> k;

        int cnt=0;
        if(n==1){
            cout<<0<<endl;
            return;
        } 
      
        int rem=n;
        while (1) {
            rem-=(k-1);
            cnt++;
            if(rem<=1) {
                break;
            }
        }

        cout <<cnt<< endl;
    }


int main() {
    int t;
    cin>>t;
    while(t--){

    solve();
    }
    return 0;
}
