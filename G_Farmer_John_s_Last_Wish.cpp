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
    ll N;
    vector<ll> t;
    SegTree(ll n = 0) { init(n); }
    void init(ll n)
    {
        N = 1;
        while (N < n)
            N <<= 1;
        t.assign(2 * N, 0);
    }
    void build(const vector<ll> &a)
    {
        ll n = (ll)a.size();
        for (ll i = 0; i < n; ++i)
            t[N + i] = a[i];
        for (ll i = N - 1; i >= 1; --i)
            t[i] = t[i << 1] + t[i << 1 | 1];
    }
    void add(ll pos, ll delta)
    {
        ll p = N + pos;
        t[p] += delta;
        p >>= 1;
        while (p)
        {
            t[p] = t[p << 1] + t[p << 1 | 1];
            p >>= 1;
        }
    }
    ll sumRange(ll l, ll r)
    {
        if (l > r)
            return 0;
        l += N;
        r += N;
        ll res = 0;
        while (l <= r)
        {
            if (l & 1)
                res += t[l++];
            if (!(r & 1))
                res += t[r--];
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
    ll solve(ll ql, ll qr)
    {
        if (sumRange(ql, qr) == 0)
            return 0;
        ll node = 1, l = 0, r = N - 1;
        while (l != r)
        {
            ll mid = (l + r) >> 1;
            ll left = node << 1;
            ll right = left | 1;
            ll Rl = mid + 1, Rr = r;
            if (Rr < ql || Rl > qr)
            {
                node = left;
                r = mid;
            }
            else
            {
                if (sumRange(max(ql, Rl), min(qr, Rr)) > 0)
                {
                    node = right;
                    l = mid + 1;
                }
                else
                {
                    node = left;
                    r = mid;
                }
            }
        }
        return l <= qr && l >= ql ? l : 0 ;
    }
};

int main()
{
    // بسم الله
    AMR
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        for(ll & y : a)cin >> y ; 

        vector<ll> cnt(n + 1, 0);
        vector<ll> fq(n + 1, 0);
        fq[0] = n;

        SegTree seg(n + 1);
        seg.build(fq);

        vector<ll> ans(n);
        for (ll i = 0; i < n; ++i)
        {
            ll x = a[i];
            for (ll j = 1; j*j <= x; j ++ )
            {
                if (x % j == 0)
                {
                    ll c = cnt[j];
                    seg.add(c, -1);
                    cnt[j] = c + 1;
                    seg.add(c + 1, +1);

                    ll d = x / j;
                    if (d != j)
                    {
                        c = cnt[d];
                        seg.add(c, -1);
                        cnt[d] = c + 1;
                        seg.add(c + 1, +1);
                    }
                }
            }
            ans[i] = seg.solve(0, i);
        }

        for (ll i = 0; i < n; i ++ )
        {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
