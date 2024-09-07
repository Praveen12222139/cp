#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;  // Adjusting the size based on constraints
vector<int> Graph[MAXN];
int arr[MAXN];
long long ans, colorRed, colorBlue;
int n;

pair<long long, long long> dfs(int src, int parent = -1) {
    long long r = (arr[src] == 1) ? 1 : 0;
    long long b = (arr[src] == 2) ? 1 : 0;
    for (auto neighbour : Graph[src]) {
        if (neighbour != parent) {
            pair<long long, long long> result = dfs(neighbour, src);
            ans += (result.first == colorRed && result.second == 0);
            ans += (result.first == 0 && result.second == colorBlue);
            r += result.first;
            b += result.second;
        }
    }
    return {r, b};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    long long countRed = 0, countBlue = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 1) {
            countRed++;
        }
        if (arr[i] == 2) {
            countBlue++;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        Graph[u - 1].push_back(v - 1);
        Graph[v - 1].push_back(u - 1);
    }

    colorRed = countRed;
    colorBlue = countBlue;
    ans = 0;
    dfs(0);
    cout << ans << endl;

    return 0;
}
