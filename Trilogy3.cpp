#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    string ans = "";

    // Convert integer n to binary string representation
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1) {
            ans += "1";
        } else {
            ans += "0";
        }
    }

    // Swap characters in the string in pairs
    for (int i = 0; i < ans.size() - 1; i += 2) {
        swap(ans[i], ans[i + 1]);
    }

    long long res = 0;
    long long multi = 0;

    // Calculate result based on manipulated binary string
    for (int i = ans.size() - 1; i >= 0; i--) {
        if (ans[i] == '1') {
            res += (1LL << multi);
        }
        multi++;
    }

    cout << res << endl;

    return 0;
}
