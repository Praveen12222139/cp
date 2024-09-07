#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> findNextSmallerElement(const vector<int>& arr) {
    vector<int> result(arr.size(), -1); 

    stack<int> st;

    for (int i = arr.size() - 1; i >= 0; --i) { 
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            result[i] = st.top();
        }

        st.push(arr[i]);
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = findNextSmallerElement(arr);

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
