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
vector<ll> adj[200006];

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
        for (ll i = 1; i <= n; i++)
        {
            adj[i].clear();
        }
        for (ll i = 0; i < n - 1; i++)
        {
            ll x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        ll ans = 0;
        ll mx = 0;
        for (ll i = 1; i <= n; i++)
        {
            if (adj[i].size() == 1)
            {
                ans++;
            }

            ll m = 0;
            for (ll ch : adj[i])
            {
                if (adj[ch].size() == 1)
                    m++;
            }
            mx = max(m, mx);
        }
        if (n == 2)
        {
            cout << 0;
        }
        else
        {
            cout << ans - mx ;
        }
        cout << endl;
    }
    return 0;
}
