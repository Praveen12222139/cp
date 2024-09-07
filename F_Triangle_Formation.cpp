#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isNonDegenerate(int a, int b, int c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        --l; --r; // converting to 0-based index

        vector<int> sticks(a.begin() + l, a.begin() + r + 1);
        sort(sticks.begin(), sticks.end());

        bool found = false;
        for (int i = 0; i <= (r - l + 1) - 6 && !found; ++i) {
            for (int j = i + 3; j <= (r - l + 1) - 3 && !found; ++j) {
                if (isNonDegenerate(sticks[i], sticks[i+1], sticks[i+2]) &&
                    isNonDegenerate(sticks[j], sticks[j+1], sticks[j+2])) {
                    found = true;
                }
            }
        }

        cout << (found ? "YES" : "NO") << endl;
    }
}

int main() {
    solve();
    return 0;
}
