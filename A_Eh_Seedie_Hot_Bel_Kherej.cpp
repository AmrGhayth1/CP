#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

map<int, int> factorize(int x) {
    map<int, int> factors;
    if (x == 1) {
        return factors;
    }
    while (x % 2 == 0) {
        factors[2]++;
        x /= 2;
    }
    for (int i = 3; i <= sqrt(x); i += 2) {
        while (x % i == 0) {
            factors[i]++;
            x /= i;
        }
    }
    if (x > 1) {
        factors[x]++;
    }
    return factors;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (x == 1) {
        cout << 0 << '\n';
        return 0;
    }

    map<int, int> x_factors = factorize(x);
    vector<int> primes;
    vector<int> required;
    for (const auto& p : x_factors) {
        primes.push_back(p.first);
        required.push_back(p.second);
    }
    int m = primes.size();

    map<vector<int>, int> dp;
    dp[vector<int>(m, 0)] = 0;

    for (long long num : a) {
        vector<int> current_num_factors(m, 0);
        long long temp = num;
        for (int i = 0; i < m; ++i) {
            int p = primes[i];
            int cnt = 0;
            while (temp % p == 0 && temp > 0) {
                cnt++;
                temp /= p;
            }
            current_num_factors[i] = cnt;
        }
        map<vector<int>, int> new_dp = dp;
        for (const auto& entry : dp) {
            vector<int> state = entry.first;
            int count = entry.second;
            vector<int> new_state(m);
            for (int i = 0; i < m; ++i) {
                new_state[i] = min(state[i] + current_num_factors[i], required[i]);
            }
            if (new_dp.find(new_state) == new_dp.end() || count + 1 < new_dp[new_state]) {
                new_dp[new_state] = count + 1;
            }
        }
        dp = new_dp;
    }

    vector<int> target = required;
    if (dp.find(target) != dp.end()) {
        cout << dp[target] << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}