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
typedef unsigned __int128 bll;
const ll MOD = 1e9 + 7;

int main()
{
    AMR
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (ll i = 0; i < n; ++i)
            cin >> a[i];

        vector<vector<ll>> dis(n, vector<ll>(m, (ll)1e18));
        deque<pair<ll, ll>> dq;

        vector<pair<ll, ll>> ev = {{-1, 0}, {-1, -1}, {0, -1}, {0, 1}, {1, 0}, {1, -1}};
        vector<pair<ll, ll>> od = {{-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, 0}, {1, 1}};

        for (ll j = 0; j < m; j++)
        {
            ll w = (a[0][j] == '.') ? 1 : 0;
            dis[0][j] = w;
            if (w == 0)
                dq.push_front({0, j});
            else
                dq.push_back({0, j});
        }

        while (!dq.empty())
        {
            pair<ll, ll> p = dq.front();
            dq.pop_front();
            ll d = dis[p.first][p.second];

            vector<pair<ll, ll>> dirs;
            if (p.first % 2 == 0)
                dirs = ev;
            else
                dirs = od;

            for (auto [dx, dy] : dirs)
            {
                ll nx = p.first + dx;
                ll ny = p.second + dy;
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                    ll w = 0 ; 
                if(a[nx][ny] == '.'){
                    w = 1 ; 
                } 
                if (dis[nx][ny] > d + w)
                {
                    dis[nx][ny] = d + w;
                    if (w == 0)
                        dq.push_front({nx, ny});
                    else
                        dq.push_back({nx, ny});
                }
            }
        }

        ll ans = (ll)1e18;
        for (ll j = 0; j < m; ++j)
            ans = min(ans, dis[n - 1][j]);

        cout << ans;
    }
    return 0;
}
