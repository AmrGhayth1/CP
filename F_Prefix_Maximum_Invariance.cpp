#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;
const ll MOD = 1e9 + 7;

struct SegTree
{
    int n;
    vector<ll> t;
    SegTree(int _n = 0) { init(_n); }
    void init(int _n)
    {
        n = 1;
        while (n < _n)
            n <<= 1;
        t.assign(2 * n, 0);
    }
    void update(int i, ll v)
    {
        i += n;
        t[i] = max(t[i], v);
        i >>= 1;
        while (i)
        {
            t[i] = max(t[i << 1], t[(i << 1) | 1]);
            i >>= 1;
        }
    }
    ll query(int l, int r)
    {
        if (l > r)
            return 0;
        l += n;
        r += n;
        ll res = 0;
        while (l <= r)
        {
            if (l & 1)
                res = max(res, t[l++]);
            if (!(r & 1))
                res = max(res, t[r--]);
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
};

int main()
{
    AMR
        ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n + 1), b(n + 1);
        for (ll i = 1; i <= n; i++)
            cin >> a[i];
        for (ll i = 1; i <= n; i++)
            cin >> b[i];

        ll m = 2 * n + 5;
        SegTree st(m);
        ll ans = 0;
        for (ll i = 1; i <= n; i++)
        {
            ll la = st.query(a[i], m - 1);
            ll lb = st.query(b[i], m - 1);
            ll c = 0;
            if (a[i] == b[i])
                c += i - la;
            c += min(la, lb);
            ans += c * (n - i + 1);
            st.update(a[i], i);
        }
        cout << ans << endl;
    }
    return 0;
}
