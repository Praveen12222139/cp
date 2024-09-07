#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool canReachWithMaxValue(const vector<int>& A, const vector<int>& B, int maxVal) {
    int N = A.size();
    vector<vector<bool>> visited(2, vector<bool>(N, false));
    
    queue<pair<int, int>> q; 
    q.push({0, 0});        
    visited[0][0] = true;
    
    int directions[2][2] = {{0, 1}, {1, 0}};
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        
        if (row == 1 && col == N - 1) {
            return true; 
        }
        
        for (int i = 0; i < 2; ++i) {
            int newRow = row + directions[i][0];
            int newCol = col + directions[i][1];
            
            if (newRow >= 0 && newRow < 2 && newCol >= 0 && newCol < N && !visited[newRow][newCol]) {
                int currentValue = (newRow == 0) ? A[newCol] : B[newCol];
                if (currentValue <= maxVal) {
                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
        }
    }
    
    return false; 
}


int minMaxPathValue(const vector<int>& A, const vector<int>& B) {
    int left = max(A[0], B.back());
    int right = max(*max_element(A.begin(), A.end()), *max_element(B.begin(), B.end()));
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canReachWithMaxValue(A, B, mid)) {
            right = mid;
        } else {
            left = mid + 1; 
        }
    }
    
    return left;
}

int main() {
    int n;
    cin>>n;
   vector<int>a(n);
   vector<int>b(n);
   for(int i=0;i<n;i++){
    cin>>a[i];
   }
   for(int i=0;i<n;i++){
    cin>>b[i];
   }
    
    cout  << minMaxPathValue(a,b) << endl;
    
    return 0;
}



// int solution(vector<int> &A, vector<int> &B) {
//     int N = A.size();
//     vector<int> a2(N, 0);
//     int t2 = -(1e9+7);
    
//     for(int i = N-1; i >= 0; i--) {
//         t2 = max(t2, B[i]);
//         a2[i] = t2;
//     }
    
//     int ans = A[0];
//     if(A[0]>a2[0]) return a2[0];
//     for(int i = 0; i < N-1; i++) {
//         if(A[i+1] > a2[i]) {
//             return max(ans, a2[i]);
//         } else {
//             ans = max(ans, A[i]);
//         }
//     }
//     ans = max(ans,B[N-1]);
//     return ans;
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int>v(n);
//     vector<int>v2(n);
//     for(int i=0;i<n;i++){
//         cin>>v[i];
//     }
//     for(int i=0;i<n;i++){
//         cin>>v2[i];
//     }
//     cout<<solution(v,v2);
//     return 0;
// }