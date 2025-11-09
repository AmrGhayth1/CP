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
    //cin >> t;
next:
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        string s[n];
        for (auto &y : s)
            cin >> y;
        deque<pair<pair<ll, ll>, ll>> q;
        // 0 == U , 1 == D , 2 == L , 3 == R ; 
        vector<vector<vector<ll>>> dis(n + 1, vector<vector<ll>>(m + 1, vector<ll>(4,-1))) ;
        q.push_back({{n - 1, m - 1}, 2});
        dis[n - 1][m - 1][2] = 0;
        auto can = [&](ll i, ll j , ll k) -> bool
        {
           bool x =  (i >= 0 && j >= 0 && i < n && j < m && dis[i][j][k] == -1);
           return x ; 
        };
        ll ans = 1e18 ; 
        while (!q.empty())
        {
            ll i = q.front().first.first;
            ll j = q.front().first.second;
            ll c = q.front().second;
            if(i == 0 && c == 2 )ans = min(dis[i][j][2], ans) ; 
            q.pop_front();
            ll nxi = i, nxj = j;
            if (c == 2)
            {
                nxj--;
            }
            else if (c == 3)
            {
                nxj++;
            }
            else if (c == 0)
            {
                nxi--;
            }
            else
            {
                nxi++;
            }
            if (can(nxi, nxj , c ))
            {
                q.push_front({{nxi, nxj}, c});
                dis[nxi][nxj][c] = dis[i][j][c];
            }
            if (s[i][j] == '#')
            {
        // 0 == U , 1 == D , 2 == L , 3 == R ; 

                if (can(i - 1, j , 0))
                {
                    q.push_back({{i - 1, j},0 });
                    dis[i - 1][j][0] = dis[i][j][c] + 1;
                }
                 if (can(i + 1, j , 1))
                {
                    q.push_back({{i + 1, j}, 1});
                    dis[i + 1][j][1] = dis[i][j][c] + 1;
                }
                 if (can(i, j - 1 , 2 ))
                {
                    q.push_back({{i, j - 1}, 2});
                    dis[i] [j - 1][2] = dis[i][j][c] + 1;
                }
                 if (can(i, j + 1 , 3 ))
                {
                    q.push_back({{i, j + 1}, 3});
                    dis[i][j + 1][3] = dis[i][j][c] + 1;
                }
            }
        }
        for(ll i = 0 ; i < m  ; i ++){
            if(dis[1][i][0] != -1 && s[0][i] =='#' ){
                ans = min(ans ,dis[1][i][0]+1 ) ; 
            }
        }
      if(ans == 1e18)ans = -1 ; 
        cout << ans ; 
    }
    return 0;
}
