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
    // cin >> t;
next:
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        string s[n];
        for (auto &y : s)
        {
            cin >> y;
        }

        auto bfs = [&](char tg)
        {
            deque<pair<ll, ll>> q;
            vector<vector<ll>> dis(n, vector<ll>(m, -1));
            for (ll i = 0; i < n; i++)
            {
                for (ll j = 0; j < m; j++)
                {
                    if (s[i][j] != '#' && s[i][j] != '.' && s[i][j] == tg )
                    {
                        q.push_front({i, j});
                        dis[i][j] = 0;
                    }
                }
            }
            auto can = [&](ll i, ll j) -> bool
            {
                return (i >= 0 && j >= 0 && i < n && j < m  && s[i][j] != '#' && dis[i][j] == -1);
            };
            while (!q.empty())
            {
                auto [i, j] = q.front();
                q.pop_front();
                for (ll k = 0; k < 4; k++)
                {
                    ll nx = i + dx[k];
                    ll ny = dy[k] + j;
                    if (can(nx, ny))
                    {
                        ll x = s[nx][ny] == '.' ? 1 : 0;
                        dis[nx][ny] = dis[i][j] + x;
                        if (x)
                        {
                            q.push_back({nx, ny});
                        }
                        else
                        {
                            q.push_front({nx, ny});
                        }
                    }
                }
            }
            return dis;
        };
        vector<vector<ll>> d1 = bfs('1');
        vector<vector<ll>> d2 = bfs('2');
        vector<vector<ll>> d3 = bfs('3');
        ll ans = 1e18 ; 
         for(ll i = 0 ; i < n ; i ++){
            for(ll j = 0 ; j < m ; j ++){
               if(s[i][j] != '#' && d1[i][j] != -1 && d2[i][j] != -1 && d3[i][j] != -1 ){
                ll x = 0 ; 
                if(s[i][j] == '.')x= 2 ; 
                ans = min(ans , d3[i][j] + d2[i][j] + d1[i][j] - x ) ;
               }
            }
         }
       if(ans == 1e18)ans = -1 ; 
         cout << ans << endl; 
    }
    return 0;
}
