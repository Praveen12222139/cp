#include <iostream>
#include <algorithm> // for std::max
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    
    // Calculate the minimum and maximum positions Petr can occupy
    int min_pos = a + 1;
    int max_pos = n - b;
    cout<<n- max(min_pos,max_pos)+1;
}

int main() {
    solve();
    return 0;
}
