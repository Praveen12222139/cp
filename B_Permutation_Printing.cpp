#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    
        int n;
        cin >> n;
        vector<int> p(n);
        // Fill the vector with numbers from 1 to n
        for (int i = 0; i < n; ++i) {
            p[i] = n - i; // reverse order
        }
        for (int i = 0; i < n; ++i) {
            cout << p[i] << " ";
        }
        cout << endl;
    }


int main() {
    int t;
    while (t--)
    {
        solve();
    }
    
    
    return 0;
}
