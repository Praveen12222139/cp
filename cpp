//Quick sort using recuesion
#include <iostream>

using namespace std;
int partiton(int arr[],int s,int e){
    int count=0;
   int pivot=arr[s];
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            count++;
        }
    }
     int pivotIndex=s+count;
    swap(arr[pivotIndex],arr[s]);
    int i=s;
    int j=e;
    while(s<pivotIndex&&j>pivotIndex){
        
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotIndex&& j>pivotIndex){
            swap(arr[i++],arr[j--]); 
        }
    }
    return pivotIndex;
}
void Quicksort(int arr[],int s,int e){
    if(s>=e){
        return ;
    }
    int p=partiton(arr,s,e);
    Quicksort(arr,s,p-1);
    Quicksort(arr,p+1,e);
}

int main()
{
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
       cin>>arr[i];
   }
   Quicksort(arr,0,n-1);
for(int i=0;i<n;i++){
    cout<<arr[i]<<" "; 
}
    return 0;
}