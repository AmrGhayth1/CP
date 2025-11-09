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
map<pair<ll, ll>, ll> m;
vector<vector<ll>> adj(200001);
vector<ll> day(200006, 0);
void dfs(ll u, ll v, vector<vector<ll>> &ans, ll last)
{
    ll color = 0;
    for (ll ch : adj[v])
    {
        if (ch != u)
        {
            if (color == last)
                color++;
            ans[color].push_back(m[{min(ch, v), max(v, ch)}]);
            dfs(v, ch, ans, color);
            color++;
        }
    }
}

int main()
{
    AMR
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        ll mx = 0;
        for (ll i = 1; i < n; i++)
        {
            ll x, y;
            cin >> x >> y;
            m[{min(x, y), max(x, y)}] = i;
            adj[x].push_back(y);
            adj[y].push_back(x);
            ll z = max(adj[x].size() , adj[y].size() ) ; 
            mx = max(mx, z ) ;
        }
        vector<vector<ll>> ans(mx);
        dfs(-1 , 1 , ans , -1 ) ;
        cout << ans.size() << endl;
        for (vector<ll> vc : ans)
        {
            cout << vc.size() << ' ';
            for (ll y : vc)
            {
                cout << y << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}