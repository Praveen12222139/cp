#include <iostream>
#include <vector>

using namespace std;
bool check(vector<vector<int>>& a, vector<vector<int>>& b, int n, int m){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m ; ++j) {
            if(a[i][j]!=b[i][j]){
                return false;
            }
        }
    }
    return true;
}
bool can_transform_all_2x2(vector<vector<int>>& a, vector<vector<int>>& b, int n, int m) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
          int rem=(b[i][j]-a[i][j]+3)%3;
                if(rem!=0){
            a[i][j] = (a[i][j] + rem) % 3;
             a[i + 1][j] = (a[i + 1][j] + rem) % 3;
            a[i][j + 1] = (a[i][j + 1] + rem) % 3;
            a[i + 1][j + 1] = (a[i + 1][j + 1] + rem) % 3;
                }
          
          
        
        }
    }
    return check(a,b,n,m);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));
        vector<vector<int>> b(n, vector<int>(m));

        // Input grid a
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }

        // Input grid b
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> b[i][j];
            }
        }

        // Check if all 2x2 submatrices in a can be transformed to match b
        if (can_transform_all_2x2(a, b, n, m)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
