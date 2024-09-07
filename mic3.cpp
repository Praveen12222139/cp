#include <bits/stdc++.h>
using namespace std;
 int main(){
    int n;
    cin>>n;
    string a;
    cin>>a;
    string b;
    cin>>b;
    string newa=a;
    string newb=b;
    swap(newa[0],newb[0]);
     long long int a_num = stoll(newa); 
        long long int b_num = stoll(newb);
        long long int diff2= abs(a_num - b_num);
    int k=0;
    if(a[0]-'0'>b[0]-'0'){
        for(int i=1;i<n;i++){
            if(a[i]-'0'>b[i]-'0'){
                swap(a[i],b[i]);
                k++;
            }
        }
    }
    else{
        for(int i=1;i<n;i++){
            if(b[i]-'0'>a[i]-'0'){
                swap(a[i],b[i]);
                k++;
            }
        }


    }
 long long int a_num1 = stoll(a);
        long long int b_num1 = stoll(b);
 
        long long int diff = abs(a_num1 - b_num1);

       
        if(diff2<=diff){
            cout<<1<<endl;
        }
        else
        {
            cout<<k<<endl;
        }

      
    return 0;

 }