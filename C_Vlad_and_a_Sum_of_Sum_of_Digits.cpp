
#include <iostream>
#include <vector>
using namespace std;

vector<int> calculate_digit_sums(int N) {
    vector<int> pref(N);
    for (int i = 1; i < N; i++) {
        pref[i] = pref[i - 1];
        int x = i;
        while (x > 0) {
            pref[i] += x % 10;
            x /= 10;
        }
    }
    return pref;
}

void solve(const vector<int>& pref) {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        cout << pref[n] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    const int N = int(2e5) + 10;
    vector<int> pref = calculate_digit_sums(N);
    solve(pref);
    return 0;
}


