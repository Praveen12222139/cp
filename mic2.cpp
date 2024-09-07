#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int k = 0;

 
    int start = 0;
    while (start < n && a[start] == b[start]) {
        start++;
    }

    if (start < n) {
   
        if (a[start] > b[start]) {
       
            for (int i = start + 1; i < n; i++) {
                if (a[i] > b[i]) {
                    swap(a[i], b[i]);
                    k++;
                }
            }
        } else {
      
            for (int i = start + 1; i < n; i++) {
                if (b[i] > a[i]) {
                    swap(a[i], b[i]);
                    k++;
                }
            }
        }
    }

  
    cout << min(k, (n - start - k)) << endl;
    return 0;
}
