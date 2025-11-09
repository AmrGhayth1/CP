#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define el '\n'
#define all(v) v.begin(), v.end()
#define pb push_back
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const ll mod = 1e9 + 7;

string s;
ll n;

map<pair<int, vector<int>>, ll> dp;

ll rec(int idx, vector<int> cur) {
    if (idx == n) {
        // Base case: check if current partition is palindrome
        vector<int> rev = cur;
        reverse(all(rev));
        return (rev == cur) ? 1 : 0;
    }

    // If already computed, return memoized result
    if (dp.count({idx, cur})) return dp[{idx, cur}];

    ll res = 0;
    int digit = s[idx] - '0';

    // Option 1: Start a new part
    vector<int> new_part = cur;
    new_part.pb(digit);
    res = (res + rec(idx + 1, new_part)) % mod;

    // Option 2: Extend the current part (only if cur is not empty)
    if (!cur.empty()) {
        vector<int> extended = cur;
        extended.back() += digit;
        res = (res + rec(idx + 1, extended)) % mod;
    }

    return dp[{idx, cur}] = res;
}

// Solve function for each test case
void solve() {
    dp.clear();
    cin >> s;
    n = s.size();
    vector<int> cur;
    cout << rec(0, cur) << el;
}

int main() {
    FIO
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
