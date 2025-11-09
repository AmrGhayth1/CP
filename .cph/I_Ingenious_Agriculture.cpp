#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;

vector<int> spf; // Smallest Prime Factor
vector<int> primes;

void sieve() {
    spf.resize(MAX);
    for (int i = 2; i < MAX; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && primes[j] <= spf[i] && i * primes[j] < MAX; ++j) {
            spf[i * primes[j]] = primes[j];
        }
    }
}

map<int, int> factorize(int x) {
    map<int, int> factors;
    while (x > 1) {
        int p = spf[x];
        while (x % p == 0) {
            factors[p]++;
            x /= p;
        }
    }
    return factors;
}

vector<int> compute_factorial_exponents(int n) {
    vector<int> exp(MAX, 0);
    for (int p : primes) {
        if (p > n) break;
        int cnt = 0;
        int current = n;
        while (current > 0) {
            current /= p;
            cnt += current;
        }
        exp[p] = cnt;
    }
    return exp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int n, q;
    cin >> n >> q;

    vector<int> fact_exp = compute_factorial_exponents(n);
    map<int, int> v_factors;

    while (q--) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            map<int, int> x_factors = factorize(x);
            for (auto &[p, cnt] : x_factors) {
                v_factors[p] += cnt;
            }
        } else {
            map<int, int> x_factors = factorize(x);
            int r = INT_MAX;
            for (auto &[p, cnt_x] : x_factors) {
                int cnt_total = fact_exp[p] + v_factors[p];
                int possible_r = cnt_total / cnt_x;
                r = min(r, possible_r);
            }
            cout << r << '\n';
        }
    }

    return 0;
}