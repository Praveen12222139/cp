#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void processTestCases(int t, vector<pair<int, vector<int>>>& testCases) {
    for (int i = 0; i < t; ++i) {
        int n = testCases[i].first;
        vector<int>& a = testCases[i].second;

        if (n == 2) {
            cout << "YES\n";
            for (int num : a) {
                cout << num << " ";
            }
            cout << "\n";
            continue;
        }

        
        swap(a[0], a[n-1]);

       
              cout << "YES\n";
        for (int num : a) {
            cout << num << " ";
        }
        cout << "\n";
    }
}

int main() {
    int t;
    cin >> t;

    vector<pair<int, vector<int>>> testCases(t);

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }
        testCases[i] = {n, a};
    }

    processTestCases(t, testCases);

    return 0;
}
