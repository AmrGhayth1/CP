#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    ll v[2];
    int c[2];
    Node() { v[0]=v[1]=0; c[0]=c[1]=0; }
    void clear() { v[0]=v[1]=0; c[0]=c[1]=0; }
    void setSingle(ll val) { clear(); v[0]=val; c[0]=1; }
};

Node mergeNode(const Node &L, const Node &R) {
    // gather pairs from L and R
    vector<pair<ll,int>> items;
    if (L.c[0]>0) items.emplace_back(L.v[0], L.c[0]);
    if (L.c[1]>0) items.emplace_back(L.v[1], L.c[1]);
    if (R.c[0]>0) items.emplace_back(R.v[0], R.c[0]);
    if (R.c[1]>0) items.emplace_back(R.v[1], R.c[1]);

    Node res;
    for (auto pr : items) {
        ll val = pr.first;
        int cnt = pr.second;
        while (cnt > 0) {
            // match existing
            if (res.c[0] > 0 && res.v[0] == val) { res.c[0] += cnt; cnt = 0; break; }
            if (res.c[1] > 0 && res.v[1] == val) { res.c[1] += cnt; cnt = 0; break; }
            // empty slot
            if (res.c[0] == 0) { res.v[0] = val; res.c[0] = cnt; cnt = 0; break; }
            if (res.c[1] == 0) { res.v[1] = val; res.c[1] = cnt; cnt = 0; break; }
            // reduce both
            int t = min(cnt, min(res.c[0], res.c[1]));
            res.c[0] -= t;
            res.c[1] -= t;
            cnt -= t;
            if (res.c[0] == 0) res.v[0] = 0;
            if (res.c[1] == 0) res.v[1] = 0;
            // loop continues if cnt > 0
        }
    }
    return res;
}

struct SegTree {
    int n;
    vector<Node> st;
    vector<ll> *arr;
    SegTree(int _n = 0) { init(_n); }
    void init(int _n) {
        n = _n;
        st.assign(4*n + 5, Node());
    }
    void build(int p, int l, int r, vector<ll> &a) {
        if (l == r) {
            st[p].setSingle(a[l]);
            return;
        }
        int m = (l+r)>>1;
        build(p<<1, l, m, a);
        build(p<<1|1, m+1, r, a);
        st[p] = mergeNode(st[p<<1], st[p<<1|1]);
    }
    Node query(int p, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return Node();
        if (ql <= l && r <= qr) return st[p];
        int m = (l+r)>>1;
        Node L = query(p<<1, l, m, ql, qr);
        Node R = query(p<<1|1, m+1, r, ql, qr);
        return mergeNode(L, R);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<ll> a(n+1);
        for (int i = 1; i <= n; ++i) cin >> a[i];

        // positions map for verification
        unordered_map<ll, vector<int>> pos;
        pos.reserve(n * 2);
        for (int i = 1; i <= n; ++i) pos[a[i]].push_back(i);

        SegTree st(n);
        st.build(1, 1, n, a);

        while (q--) {
            int l, r;
            cin >> l >> r;
            int len = r - l + 1;
            int thr = len / 3; // want strictly more than floor(len/3) => count > thr

            Node cand = st.query(1, 1, n, l, r);
            vector<ll> candidates;
            if (cand.c[0] > 0) candidates.push_back(cand.v[0]);
            if (cand.c[1] > 0) candidates.push_back(cand.v[1]);
            sort(candidates.begin(), candidates.end());
            candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

            vector<ll> ans;
            for (ll v : candidates) {
                auto it = pos.find(v);
                if (it == pos.end()) continue;
                auto &vec = it->second;
                int cnt = int(upper_bound(vec.begin(), vec.end(), r) - lower_bound(vec.begin(), vec.end(), l));
                if (cnt > thr) ans.push_back(v);
            }
            if (ans.empty()) {
                cout << -1 << '\n';
            } else {
                sort(ans.begin(), ans.end());
                for (size_t i = 0; i < ans.size(); ++i) {
                    if (i) cout << ' ';
                    cout << ans[i];
                }
                cout << '\n';
            }
        }
    }
    return 0;
}
