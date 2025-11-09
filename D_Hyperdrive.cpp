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

int main()
{
    AMR
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<vector<ll>> a(n, vector<ll>(3));

        for (ll i = 0; i < n; ++i)
        {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
        }

        vector<ld> d(n);
        for (ll i = 1; i < n; ++i)
        {
            d[i] = sqrt((a[i][0] - a[0][0]) * (a[i][0] - a[0][0]) + (a[i][1] - a[0][1]) * (a[i][1] - a[0][1]) + (a[i][2] - a[0][2]) * (a[i][2] - a[0][2]));
        }

        ld ans = 1e18;
        for (ll i = 1; i < n; ++i)
        {
            for (ll j = i + 1; j < n; ++j)
            {
                ld dij = sqrt((a[i][0] - a[j][0]) * (a[i][0] - a[j][0]) + (a[i][1] - a[j][1]) * (a[i][1] - a[j][1]) + (a[i][2] - a[j][2]) * (a[i][2] - a[j][2]));
                ld t = (d[i] + d[j] + dij) / 2.0;
                ans = min(ans, t);
            }
        }
        cout << fixed << setprecision(10) << ans << endl;
    }
    return 0;
}
