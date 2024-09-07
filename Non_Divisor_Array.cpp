#include <bits/stdc++.h>
using namespace std;

int main() {
    int m;
    cin >> m;
    while(m--){
        int a;
        cin>>a;
        if(a==1) {
            cout<<1<<endl;
            cout<<1<<endl;
        }
        else{
        cout<<a-1<<endl;
        vector<int>v(a,1);
        v[0]=a-1;
        long  long  k=2;
        for(int i=1;i<a;i++){
            for(int j=i+1;j<a;j++){
                if(j%i==0){
                    v[j]=k;
                    k++;
                }
            }
        }
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
        
    }
    }
	// your code goes here

}
