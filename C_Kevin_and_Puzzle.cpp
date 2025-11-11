#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int valid_configurations = 0;

        // Try each possible number of liars (from 0 to n)
        for (int x = 0; x <= n; ++x) {
            int liar_count = 0;

            // Count how many liars can be placed such that the number of liars to the left of each honest person matches a[i]
            bool valid = true;
            for (int i = 0; i < n; ++i) {
                if (a[i] == liar_count) {
                    liar_count++;
                } else if (a[i] > liar_count) {
                    valid = false;
                    break;
                }
            }

            if (valid && liar_count == x) {
                valid_configurations++;
            }
        }

        cout << valid_configurations % MOD << "\n";
    }

    return 0;
}
