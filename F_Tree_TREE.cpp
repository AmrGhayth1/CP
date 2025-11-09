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
    AMR
        ll t = 1;
    cin >> t;
next:
    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        vector<vector<ll>> adj(n + 1);
        for (ll i = 0; i < n - 1; ++i)
        {
            ll x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<ll> childs(n + 1), up(n + 1);

        function<void(ll, ll)> dfs = [&](ll v, ll u)
        {
            up[v] = u;
            childs[v] = 1;
            for (ll ch : adj[v])
            {
                if (ch != u){
                dfs(ch, v);
                childs[v] += childs[ch];
                }
            }
        };

        dfs(1, 0);

        ll ans = n;

        for (ll v = 1; v <= n; ++v)
        {
            for (ll u : adj[v])
            {
                ll x = (u == up[v]) ? (n - childs[v]) : childs[u];
                if (x < n - k + 1)
                    ans += x;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
