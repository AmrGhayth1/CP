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
        ll h, d;
        cin >> h >> d;

        auto is = [&] (bll t){
            if (t < d) return false;

            bll R = t - d;
            bll x = d;

            bll p = x;
            bll y = R + 1;
            if (y < p) p = y;

            bll q = x / p;
            bll rem = x % p;

            auto Ar_S = [](bll x) { return(bll)( x * (x + 1) / 2 ) ; };

            bll tt = 0;
            tt += rem * Ar_S(q + 1);
            tt += (p - rem) * Ar_S(q);

            bll can = h + R - 1; 
            return (tt <= can) ;
        };

        ll l = d, r = 2 * d;
        ll ans = r;
        while (l <= r) {
            ll mid = (r+l) / 2;
            if (is(mid)) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        cout << ans << endl;
    }
    return 0;
}
