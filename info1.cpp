#include <iostream>
#include <vector>

using namespace std;

const int dix[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int x, int y) {
    int n = matrix.size();
    visited[x][y] = true;
    for (const auto& d : dix) {
        int newX = x + d[0];
        int newY = y + d[1];
        if (newX >= 0 && newX < n && newY >= 0 && newY < n && 
            matrix[newX][newY] == 0 && !visited[newX][newY]) {
            dfs(matrix, visited, newX, newY);
        }
    }
}

int countPlaneFields(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int planeFieldsCount = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0 && !visited[i][j]) {
                vector<pair<int, int>> cells;
                dfs(matrix, visited, i, j);
                planeFieldsCount++;
            }
        }
    }
    return planeFieldsCount;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    
    int result = countPlaneFields(matrix);
    cout << result << endl;
    return 0;
}
