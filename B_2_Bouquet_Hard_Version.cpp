#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Flower {
    long long petals;
    long long quantity;
};

void solve() {
    long long n, m;
    cin >> n >> m;
    
    vector<Flower> flowers(n);
    for (int i = 0; i < n; ++i) {
        cin >> flowers[i].petals;
    }
    for (int i = 0; i < n; ++i) {
        cin >> flowers[i].quantity;
    }
    
    // Sort flowers based on petals
    sort(flowers.begin(), flowers.end(), [](const Flower& a, const Flower& b) {
        return a.petals < b.petals;
    });
    
    long long maxPetals = 0;
    long long currentPetals = 0, currentCost = 0;
    int left = 0;

    // Sliding window approach
    for (int right = 0; right < n; ++right) {
        // Add current flower type to the window
        long long petals = flowers[right].petals;
        long long quantity = flowers[right].quantity;
        long long cost = petals * quantity;
        long long totalPetals = petals * quantity;
        
        currentCost += cost;
        currentPetals += totalPetals;
        
        // Shrink window from left if cost exceeds the budget
        while (currentCost > m) {
            long long leftPetals = flowers[left].petals;
            long long leftQuantity = flowers[left].quantity;
            long long leftCost = leftPetals * leftQuantity;
            long long leftTotalPetals = leftPetals * leftQuantity;
            
            currentCost -= leftCost;
            currentPetals -= leftTotalPetals;
            left++;
        }
        
        // Update the maximum petals
        maxPetals = max(maxPetals, currentPetals);
    }
    
    cout << maxPetals << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
