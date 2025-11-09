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
vector<ll> tree;

ll query(ll nd, ll l, ll r, ll x)
{
    //cout << nd << endl ;
    if (l == r)
    {
        if (tree[nd] >= x)
            return l;

        return -1;
    }
    ll md = (l + r) / 2;
    if (tree[2 * nd] < x)
    {
        return query(2 * nd + 1, md + 1, r, x);
    }
    else
    {
        return query(2 * nd, l , md , x);
    }
}

void update(ll i, ll v, ll n)
{
    tree[i + n] = v;
    for (ll j = (n + i) / 2; j >= 1; j /= 2)
    {
        tree[j] = max(tree[j * 2], tree[j * 2 + 1]);
    }
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
    {
        tree[n + i] = a[i];
    }
    for (ll i = n - 1; i >= 1; i--)
    {
        tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
    }
}

int main()
{
    AMR
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, q;
        cin >> n >> q;
        vector<ll> a(n);
        for (ll& y : a)
            cin >> y;
        build(a, n);
        while (q--)
        {
            ll c;
            cin >> c;
            if (c == 1)
            {
                ll j, v;
                cin >> j >> v;
                update(j, v, n);
            }
            else
            {
                ll x;
                cin >> x;
                cout << query(1, 0, n - 1, x) << endl;
            }
        }
    }
    return 0;
}
