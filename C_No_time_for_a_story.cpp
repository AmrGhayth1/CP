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
int main()
{
    // بسم الله
    freopen("pop.in", "r", stdin);
    AMR
        ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        for (ll &y : a)
        {
            cin >> y;
        }
        vector<ll> m(n + 2, 0);
        vector<ll> v;
        ll tg = -1;
        for (ll i = 0; i < n; i++)
        {
            if (a[i] == tg)
            {
                m[v.size() - 1]++;
            }
            else
            {
                v.push_back(a[i]);
                tg = a[i];
                m[v.size() - 1]++;
            }
        }

        ll ans = 0;
        ll mx = 0;
        ll ind = 0;
        for (ll i = 0; i < v.size() ; i++)
        {
            if (mx < m[i])
            {
                mx = m[i];
                ind = i;
            }
        }
        ans += mx;
        mx = 0;
        for (ll i = 0; i < v.size() ; i++)
        {
            if (i != ind)
            {
                if (mx < m[i])
                {
                    mx = m[i];
                }
            }
        }
        ans += mx;
        if (v.size() == 1)
        {
            ans = m[0];
        }
        else
        {
            for (ll i = 0; i < v.size() - 1; i++)
            {
                ll x = m[i] + m[i + 1];
                if (i + 2 < v.size())
                {
                    if (v[i + 2] == v[i] || v[i + 2] == v[i + 1])
                    {
                        ans = max(ans, x + m[i + 2]);
                    }
                }
                if (i - 1 >= 0)
                {
                    if (v[i - 1] == v[i] || v[i - 1] == v[i + 1])
                    {
                        ans = max(ans, x + m[i - 1]);
                    }
                }
                ans = max(ans, x);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
