#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;

vector<ll> sgtree, lazy;
vector<bool> marked;

void push(ll nd, ll l, ll r) {
    if (marked[nd]) {
        sgtree[nd] = lazy[nd];
        if (l != r) { 
            lazy[2 * nd] = lazy[nd];
            lazy[2 * nd + 1] = lazy[nd];
            marked[2 * nd] = marked[2 * nd + 1] = true;
        }
        marked[nd] = false;
    }
}

ll query(ll nd, ll l, ll r, ll ql, ll qr) {
    push(nd, l, r);
    if (ql > r || qr < l) return 0;
    if (l == r) return sgtree[nd];
    ll md = (l + r) / 2;
    if (qr <= md)
        return query(2 * nd, l, md, ql, qr);
    else if (ql > md)
        return query(2 * nd + 1, md + 1, r, ql, qr);
    else
        return query(2 * nd, l, md, ql, md); 
}

void range_update(ll nd, ll l, ll r, ll ql, ll qr, ll val) {
    push(nd, l, r);
    if (qr < l || ql > r) return;
    if (ql <= l && r <= qr) {
        lazy[nd] = val;
        marked[nd] = true;
        push(nd, l, r);
        return;
    }
    ll md = (l + r) / 2;
    range_update(2 * nd, l, md, ql, qr, val);
    range_update(2 * nd + 1, md + 1, r, ql, qr, val);
}

void build(vector<ll> &a, ll &n) {
    ll pw = 1;
    while (pw < n) pw <<= 1;
    n = pw;
    a.resize(n, 0);
    sgtree.assign(4 * n, 0); 
    lazy.assign(4 * n, 0);
    marked.assign(4 * n, false);
    for (ll i = 0; i < n; i++) {
        sgtree[n + i] = a[i];
    }
}

int main() {
    AMR
    ll t = 1;
    while (t--) {
        ll n, q;
        cin >> n >> q;
        vector<ll> a(n, 0);
        build(a, n);
        while (q--) {
            ll c;
            cin >> c;
            if (c == 1) {
                ll l, r, v;
                cin >> l >> r >> v;
                range_update(1, 0, n - 1, l, r - 1, v);
            } else {
                ll i;
                cin >> i;
                cout << query(1, 0, n - 1, i, i) << endl;
            }
        }
    }
    return 0;
}
