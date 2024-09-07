#include <bits/stdc++.h>
using namespace std;

int minXOR(vector<int>& A) {
    int n = A.size();
    int minXor = INT_MAX;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            minXor = min(minXor, A[i] ^ A[j]);
        }
    }

    return minXor;
}

int main() {
    int n;
   
    cin >> n;

    vector<int> A(n);
  
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int result = minXOR(A);
    cout << result << endl;

    return 0;
}

