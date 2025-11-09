#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
template <typename T>
using ordered_set =  __gnu_pbds::tree<T,   __gnu_pbds::null_type, less<T>,   __gnu_pbds::rb_tree_tag,   __gnu_pbds::tree_order_statistics_node_update>;
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
vector<ll> tree;

ll query(ll nd, ll l, ll r, ll ql, ll qr)
{
    if (ql <= l && r <= qr)
        return tree[nd];
    if (l > qr || r < ql)
        return 0;
    ll md = (l + r) / 2;
    return query(2 * nd, l, md, ql, qr) + query(2 * nd + 1, md + 1, r, ql, qr);
}

void update(ll i, ll v, ll n)
{
    tree[i + n] += v;
    for (ll j = (n + i) / 2; j >= 1; j /= 2)
        tree[j] = tree[j * 2] + tree[j * 2 + 1];
}

void build(vector<ll> &a, ll &n)
{
    ll pw = 1;
    while (pw < n)
        pw <<= 1;
    n = pw;
    a.resize(n, 0);
    tree.resize(2 * n);
    for (ll i = 0; i < n; i++)
        tree[n + i] = a[i];

    for (ll i = n - 1; i >= 1; i--)
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
}

int main()
{
    AMR
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n, 0);
        ll ss = n ; 
        build(a, n);
        while (m--)
        {
            ll c;
            cin >> c;
            if (c == 1)
            {
                ll x, i, j;
                cin >> i >> j >> x;

                update(i, x, n);
                if(j < ss)
                update(j, -x, n);
            }
            else
            {
                ll i;
                cin >> i;
                cout << query(1, 0, n - 1, 0, i) << endl;
            }
        }
    }
    return 0;
}
