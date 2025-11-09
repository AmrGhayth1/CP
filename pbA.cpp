#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define AMR ios::sync_with_stdio(0); cin.tie(0);
const ll MOD = 1e9 + 7;
const int BITS = 20;  // for values up to 1e6

struct BitFenwick {
    ll n;
    vector<vector<ll>> bit;

    BitFenwick(ll size) {
        n = size;
        bit.assign(BITS, vector<ll>(n + 1, 0));
    }

    void update_bit(int b, int i, int delta) {
        while (i <= n) {
            bit[b][i] += delta;
            i += i & -i;
        }
    }

    void insert(ll i, ll val) {
        for (int b = 0; b < BITS; ++b) {
            if ((val >> b) & 1)
                update_bit(b, i, 1);
        }
    }

    void remove(ll i, ll val) {
        for (int b = 0; b < BITS; ++b) {
            if ((val >> b) & 1)
                update_bit(b, i, -1);
        }
    }

    ll query_bit(ll i, ll b) {
        ll res = 0;
        while (i > 0) {
            res += bit[b][i];
            i -= i & -i;
        }
        return res;
    }

    ll query_bit(ll l, ll r, ll b) {
        return query_bit(r, b) - query_bit(l - 1, b);
    }
};

const ll N = 2e5 + 5;
ll fct[N], invfct[N];

ll modPow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void factorials() {
    fct[0] = 1;
    for (ll i = 1; i < N; i++)
        fct[i] = fct[i - 1] * i % MOD;

    invfct[N - 1] = modPow(fct[N - 1], MOD - 2, MOD);
    for (ll i = N - 2; i >= 0; i--)
        invfct[i] = invfct[i + 1] * (i + 1) % MOD;
}

ll C(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return fct[n] * invfct[r] % MOD * invfct[n - r] % MOD;
}

int main() {
    // بسم الله
    AMR
    factorials();
    ll n;
    cin >> n;
    BitFenwick bfw(n);
    vector<ll> a(n + 1);

    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        bfw.insert(i, a[i]);  
    }

    ll q;
    cin >> q;
    while (q--) {
        ll c;
        cin >> c;
        if (c == 1) {
            ll l, r, k;
            cin >> l >> r >> k;
            ll ans = 0;
            ll total = C(r - l + 1, k);
            for (int bit = 0; bit < BITS; bit++) {
                ll x = bfw.query_bit(l, r, bit);  
                ll without = C(r - l + 1 - x, k);  
                ll withBit = (total - without + MOD) % MOD;
                ll contrib = withBit * (1LL << bit) % MOD;
                ans = (ans + contrib) % MOD;
            }
            cout << ans << "\n";
        } else {
            ll p, v;
            cin >> p >> v;
            bfw.remove(p, a[p]);  
            bfw.insert(p, v);     
            a[p] = v;
        }
    }
    return 0;
}
