#include <iostream>
#include <string>

using namespace std;

// Function to check if a character is a vowel
bool isVowel(char ch) {
    return ch == 'a' || ch == 'e';
}

// Function to check if a character is a consonant
bool isConsonant(char ch) {
    return ch == 'b' || ch == 'c' || ch == 'd';
}

void processWord(const string& s) {
    int n = s.size();
    string result;
    int i = 0;

    while (i < n) {
        if (i + 1 < n && isConsonant(s[i]) && isVowel(s[i + 1])) {
            // Check for CV syllable
            result += s.substr(i, 2); // Add the CV syllable
            i += 2; // Move to the next character after the syllable
        } else if (i + 2 < n && isConsonant(s[i]) && isVowel(s[i + 1]) && isConsonant(s[i + 2])) {
            // Check for CVC syllable
            result += s.substr(i, 3); // Add the CVC syllable
            i += 3; // Move to the next character after the syllable
        } else {
            // If an invalid syllable sequence is found, add remaining characters
            result += s.substr(i);
            i = n;
        }

        // Add a dot after each syllable except the last one
        if (i < n) {
            result += ".";
        }
    }

    // Remove trailing dot if exists
    if (!result.empty() && result.back() == '.') {
        result.pop_back();
    }

    cout << result << endl;
}

void solve() {
    int t;
    cin >> t; // Read number of test cases
    while (t--) {
        int n;
        cin >> n; // Read the length of the string (though it's not used)
        string s;
        cin >> s; // Read the input string
        processWord(s); // Process and print the result for each word
    }
}

int main() {
    solve();
    return 0;
}
