#include <bits/stdc++.h>
using namespace std;

int getNum(string str, unordered_map<char, int> &hm) {
    int num = 0;
    for (char ch : str) {
        num = num * 10 + hm[ch];
    }
    return num;
}

void printPermutation(string str, unordered_map<char, int> &hm) {
    for (char ch : str) {
        cout << hm[ch] << " ";
    }
    cout << endl;
}

int fun(string s1, string s2, string s3, string unqStr, int idx, bool vis[], unordered_map<char, int> &hm) {
    int ans = 0;
    if (idx == unqStr.length()) {
        int n1 = getNum(s1, hm), n2 = getNum(s2, hm), n3 = getNum(s3, hm);
        if ((n1 + n2) == n3) {
            printPermutation(unqStr, hm);
            return 1;
        } else {
            return 0;
        }
    }
    for (int i = 0; i <= 9; i++) {
        if (vis[i] == false) {
            vis[i] = true;  // Fixed the assignment operator
            hm[unqStr[idx]] = i;
            ans += fun(s1, s2, s3, unqStr, idx + 1, vis, hm);
            hm[unqStr[idx]] = -1;
            vis[i] = false;  // Fixed the assignment operator
        }
    }
    return ans;
}

string cryptArithmetic(string s1, string s2, string s3) {
    string str;
    unordered_map<char, int> hm;
    for (char ch : s1) {
        if (hm.find(ch) == hm.end()) {
            hm[ch] = -1;
            str += ch;
        }
    }
    for (char ch : s2) {
        if (hm.find(ch) == hm.end()) {
            hm[ch] = -1;
            str += ch;
        }
    }
    for (char ch : s3) {
        if (hm.find(ch) == hm.end()) {
            hm[ch] = -1;
            str += ch;
        }
    }
    return str;
}

int main() {
    string arr[] = {"SEND", "MORE", "MONEY"};
    string s1 = arr[0];
    string s2 = arr[1];
    string s3 = arr[2];
    string unq = cryptArithmetic(s1, s2, s3);
    unordered_map<char, int> hm;
    bool vis[10] = {false};  // Initialize vis array with false
    int result = fun(s1, s2, s3, unq, 0, vis, hm);
    cout << "Total solutions: " << result << endl;
    return 0;
}