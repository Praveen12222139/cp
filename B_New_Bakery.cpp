#include <iostream>
using namespace std;

void solve() {
    long long n, a, b;
    cin >> n >> a >> b;
    long long sum = 0;
   

    if (b <= a) {
        sum = n * a;
    } 
   
    
    else {
    long long  diff=b-a;

    if(diff>=n){
        sum= b*n -n*(n+1)/2 +n;
    }
    else{
         sum=(b*(b+1))/2 -((b-diff)*(b-diff+1)/2) +a*(n-diff);

    }
      

    }

    cout << sum << endl;
}

int main() {
    long long   t;
    cin>>t;
    while(t--){
solve();
    }
    
    return 0;
}
