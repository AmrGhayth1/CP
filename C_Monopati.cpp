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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (ll &i : a) cin >> i;
        for (ll &i : b) cin >> i;
        vector<ll> pref1(n, 1e18), pref2(n, -1e18), suff1(n + 1, 1e18), suff2(n + 1, -1e18);
        pref1[0] = a[0];
        pref2[0] = a[0];
        for (ll i = 1; i < n; i++) {
            pref1[i] = min(pref1[i - 1], a[i]);
            pref2[i] = max(pref2[i - 1], a[i]);
        }
        for (ll i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                suff1[i] = b[i];
                suff2[i] = b[i];
            } else {
                suff1[i] = min(suff1[i + 1], b[i]);
                suff2[i] = max(suff2[i + 1], b[i]);
            }
        }

        vector<ll> c(2*n + 1, 1e18);
        for (ll i = 0; i < n; i++) {
            ll L = min(pref1[i], suff1[i]);
            ll R = max(pref2[i], suff2[i]);
            c[L-1] = min(c[L-1], R);
        }

        vector<ll> d(2*n +1, 1e18);
        ll cur = 1e18;
        for (ll i = 2*n-1 ; i >= 0; i--) {
            cur = min(cur, c[i]);
            d[i] = cur;
        }

        ll ans = 0;
        for (ll i = 0; i < 2*n ; i++) {
            if (d[i] != 1e18) ans += (2*n - d[i] + 1);
        }
        cout << ans << endl;
    }
    return 0;
}
