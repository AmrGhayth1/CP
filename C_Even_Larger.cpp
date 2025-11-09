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
        ll n;
        cin >> n;
        ll a[n];
        ll ans = 0;
        for (ll &y : a)
            cin >> y;
        for (ll i = 0; i < n; i++)
        {
            if (i % 2 == 1)
            {
                ll prev = a[i - 1];
                ll next = i == n - 1 ? 0 : a[i + 1];
                if ((next + prev) > a[i])
                {
                    ll deff = (next + prev) - a[i];
                    ans += deff;
                    if (i != n - 1)
                        a[i + 1] -= deff;
                    a[i + 1] = max(a[i + 1], 0LL);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
