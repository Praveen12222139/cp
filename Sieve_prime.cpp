#include <bits/stdc++.h>
using namespace std;
void compute_prime(int n){
    vector<bool>isPrime(n,true);
    for(long long  i=2;i*i<=n;i++){

        if(isPrime[i]==true){
            for(int j=i*i;j<=n;j+=i){
                isPrime[j]=false;
            }
        }
    }
    for(long long i=2;i<=n;i++){
        if(isPrime[i]==true){
            cout<<i<<" ";
        }
    }
}
int main()
{
    int n;
    cin>>n;
    compute_prime(n);
    return 0;
}