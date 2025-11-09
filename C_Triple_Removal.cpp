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
        ll n, q;
        cin >> n >> q;
        ll pf1[n + 1];
        ll pf0[n + 1];
        pf1[0] = 0;
        pf0[0] = 0;
        ll sm1 = 0, sm0 = 0;
        bool a[n];
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            a[i] = x;
            if (x)
                sm1++;
            else
                sm0++;
            pf1[i + 1] = sm1;
            pf0[i + 1] = sm0;
        }
        ll r = 0;
        vector<pair<ll, ll>> segs;
        for (ll l = 0; l < n; l++)
        {
            r = max(l, r);
            while (r < n - 1 && a[r + 1] == !a[r])
                r++;
            segs.push_back({l + 1, r + 1});
            l = r;
        }
        sort(segs.begin(), segs.end());
        n = segs.size();
        vector<ll> L(n), pfmax(n);
        for (int i = 0; i < n; i++)
        {
            L[i] = segs[i].first;
            pfmax[i] = segs[i].second;
            if (i)
                pfmax[i] = max(pfmax[i], pfmax[i - 1]);
        }
        while (q--)
        {
            ll l, r;
            cin >> l >> r;
            ll x = pf1[r] - pf1[l - 1];
            ll y = pf0[r] - pf0[l - 1];
            if (x % 3 != 0 || y % 3 != 0)
            {
                cout << -1 << endl;
                continue;
            }
            x /= 3;
            y /= 3;
            ll ans = x + y;
            ll idx = upper_bound(L.begin(), L.end(), l) - L.begin() - 1LL;
            if (idx >= 0 && pfmax[idx] >= r)
                ans++;
            cout << ans << endl;
        }
    }
    return 0;
}
