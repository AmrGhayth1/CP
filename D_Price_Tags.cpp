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
        ll n, y;
        cin >> n >> y;
        vector<ll> freq(500000, 0);
        ll mx = -1;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            freq[x]++;
            mx = max(x, mx);
        }
        ll sm = 0;
        for (ll &y : freq)
        {
            sm += y;
            y = sm;
        }
        ll ans = -y * n + n;
        for (ll x = 2; x < 200001; x++)
        {
            ll res = -y * n;
            ll lst = 0;
            for (ll p = 1; p <= (mx / x)+1 ; p++)
            {
                ll nxl = ((p - 1) * x) + 1;
                ll r = p * x;
                ll cnt = (freq[r] - freq[0]);
                if (cnt != lst)
                {
                    ll f = freq[p] -  freq[p - 1];
                    ll i = cnt - lst;
                    res += min(i, f) * y;
                    res += i * p;
                    if (cnt == n)
                    {
                        ans = max(res, ans);
                    }
                }
                lst = cnt;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
