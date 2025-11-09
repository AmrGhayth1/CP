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

void dfs(vector<ll> adj[], ll u, ll v, map<ll, bool> &m, map<ll, bool> &my)
{
    for (ll ch : adj[v])
    {
        if (ch != u)
        {
            dfs(adj, v, ch, m, my);
            if (my[ch])
            {
                my[v] = 1;
            }
            else if (m[ch])
            {
                m[v] = 1;
            }
        }
    }
}
int main()
{
    AMR
        ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll x, y;
        cin >> x >> y;
        map<ll, bool> m;
        map<ll, bool> my;

        for (ll i = 0; i < k; i++)
        {
            ll kk;
            cin >> kk;
            m[kk] = 1;
        }
        my[y] = 1;
        vector<ll> adj[n + 1];

        for (ll i = 0; i < n - 1; i++)
        {
            ll r, l;
            cin >> r >> l;
            adj[r].push_back(l);
            adj[l].push_back(r);
        }
        ll ans = 0;
        dfs(adj, -1, x, m, my);
        for (ll i = 1; i <= n; i++)
        {
            if(i != x){
            if (my[i])
            {
                ans += 1;
            }
            else if (m[i])
            {
                ans += 2 ;
            }
        }
    }
        cout << ans << endl;
    }
    return 0;
}
