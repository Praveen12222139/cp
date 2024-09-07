#include <bits/stdc++.h>
using namespace std;

string ans(const string& d) {
    int n = 0, s = 0, e = 0, w = 0;
    for (char dir : d) {
        switch (dir) {
            case 'N': n++; break;
            case 'S': s++; break;
            case 'E': e++; break;
            case 'W': w++; break;
        }
    }
    int v= n - s;
    int h = e - w;
    if (v== 0 && h == 0) {
        return "sad Alice";
    }
    string result;

    if (v > 0) {
        result += string(v, 'N');
    } else {
        result += string(-v, 'S');
    }
    
    if (h > 0) {
        result += string(h, 'E');
    } else {
        result += string(-h, 'W');
    }

  
    sort(result.begin(), result.end());
    
    return result;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string d;
        cin >> d;
        cout << ans(d) << endl;
    }

    return 0;
}
