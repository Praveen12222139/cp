#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> prefixSum(n);
    prefixSum[0] = arr[0];  // Initialize the first element of the prefix sum array

    // Calculate the prefix sums
    for(int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }

    // Find the maximum value in the prefix sum array
    int mx = *max_element(prefixSum.begin(), prefixSum.end());

    cout << mx << endl;
    return 0;
}
