#include <bits/stdc++.h>
using namespace std;
#define HONDA ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
#define vll vector<ll>
const ll MOD = 1e9 + 9;
const ll N = 1e5 + 5;

ll pow2[N], inv2[N];

void precompute_powers(ll n) {
    pow2[0] = inv2[0] = 1;
    for (ll i = 1; i <= n; i++) {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
        inv2[i] = (inv2[i - 1] * ((MOD + 1) / 2)) % MOD; // inv(2^i)
    }
}

struct Node {
    ll bit;
    ll num;
    bool ok;
    ll idx; // index from the right

    Node() {
        bit = num = idx = 0;
        ok = true;
    }

    Node(ll x, ll ind) {
        idx = ind;
        if (x == 0 || x == 1) {
            bit = x;
            ok = true;
        } else {
            bit = 0;
            ok = false;
        }
        num = (bit * pow2[idx]) % MOD;
    }

    void update(ll x) {
        bit = bit ^ (x & 1);
        num = (bit * pow2[idx]) % MOD;
        ok = true;
    }
};

struct segtree {
    ll n;
    vector<Node> tree;

    Node merge(Node a, Node b) {
        Node res;
        res.ok = a.ok && b.ok;
        res.num = (a.num + b.num) % MOD;
        return res;
    }

    segtree(vll &a) {
        n = a.size();
        tree.resize(4 * n);
        build(a, 0, 0, n);
    }

    void build(vll &a, ll node, ll l, ll r) {
        if (r - l == 1) {
            tree[node] = Node(a[l], n - l - 1);
            return;
        }
        ll mid = (l + r) / 2;
        build(a, 2 * node + 1, l, mid);
        build(a, 2 * node + 2, mid, r);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void update(ll idx, ll x, ll node, ll l, ll r) {
        if (r - l == 1) {
            tree[node].update(x);
            return;
        }
        ll mid = (l + r) / 2;
        if (idx < mid)
            update(idx, x, 2 * node + 1, l, mid);
        else
            update(idx, x, 2 * node + 2, mid, r);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    Node query(ll ql, ll qr, ll node, ll l, ll r) {
        if (qr <= l || ql >= r) return Node(); // neutral
        if (ql <= l && r <= qr) return tree[node];
        ll mid = (l + r) / 2;
        Node left = query(ql, qr, 2 * node + 1, l, mid);
        Node right = query(ql, qr, 2 * node + 2, mid, r);
        return merge(left, right);
    }
};

int main() {
    HONDA
    ll n;
    cin >> n;
    vll a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    precompute_powers(n);

    segtree sg(a);

    ll q;
    cin >> q;
    while (q--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll i, x;
            cin >> i >> x;
            sg.update(i - 1, x, 0, 0, sg.n);
        } else {
            ll l, r;
            cin >> l >> r;
            auto ans = sg.query(l - 1, r, 0, 0, sg.n);
            if (!ans.ok) {
                cout << "Impossible\n";
            } else {
                // Normalize answer
                ll shift = pow2[n - r];
                cout << (ans.num * modinv(shift)) % MOD << "\n";
            }
        }
    }
    return 0;
}
