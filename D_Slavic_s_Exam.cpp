#include <iostream>
#include <string>

using namespace std;


bool isSubsequence(const string& a, const string& b) {
    int m = a.length(), n = b.length();
    int j = 0; 
    for (int i = 0; i < m && j < n; i++) {
        if (a[i] == b[j]) {
            j++;
        }
    }
    return j == n;
}

void solve() {
    string a, b;
    cin >> a >> b;


    if (b.length() > a.length()) {
        cout << "NO" << endl;
        return;
    }

    int i = 0, j = 0;
    while (i < a.length() && j < b.length()) {
        if (a[i] == '?') {
            a[i] = b[j];
            j++;
        } else if (a[i] == b[j]) {
            j++;
        }
        i++;
    }
    for (char& c : a) {
        if (c == '?') {
            c = 'a';
        }
    }

    if (isSubsequence(a, b)) {
        cout << "YES" << endl;
        cout << a << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
