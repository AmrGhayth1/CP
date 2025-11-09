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
    while (t--)
    {
        ld x, y;
        cin >> x >> y;
        ld fy = (y / ((y / x) + (x / y)) ) * (y/x) ;
        ld r = fy - (y - x);
        ld pi = acos(-1);
        ld area_cr = r * r * pi;
        ld adj = (r * x) / y;
        ld area_tr = (adj * r) / (2.0) ;
        ld ang = pi - (atan(y / x) + (pi / 2));
        ld area_sc = (ang / (2 * pi)) * area_cr;
        ld ans = area_tr - area_sc;
        cout << fixed << setprecision(12) << ans << endl;
    }
    return 0;
}
