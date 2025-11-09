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
vector<vector<ll>> vs(1000 , vector<ll>(1000)) ; 
set<pair<ll, pair<ll, ll>>> s;
void dfs(vector<string> &a, ll x, ll y , ll cnt)
{
    vs[x][y] = cnt;
    bool T = 1;
    for (ll i = 0; i < 4; i++)
    {
        ll nx = x + dx[i];
        ll ny = y + dy[i];
        if (nx >= 0 && nx < a.size() && ny >= 0 && ny < a[0].size())
        {
            if (a[nx][ny] == '*')
            {
                s.insert({i, {nx, ny}});
            }
            if (vs[nx][ny] == 0 && a[nx][ny] == '.')
            {
                dfs(a, nx, ny, cnt);
                T = 0;
            }
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
        ll n, m, k;
        cin >> n >> m >> k;
        vector<string> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        map<ll, ll> ans;
        ll cnt = 1;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                if (a[i][j] == '.' && vs[i][j] == 0)
                {
                s.clear() ;
                    dfs(a, i, j, cnt);
                    ans[cnt] = s.size();
                    cnt++;
                }
            }
        }
        while (k--)
        {
            ll x, y;
            cin >> x >> y;
            x--;
            y--;
            cout << ans[vs[x][y]] << endl;
        }
    }
    return 0;
}
