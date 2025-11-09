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

ll floordiv(ll a, ll b) {
    if (a >= 0) return a / b;
    return -(( -a + b - 1) / b);
}

int main() {
    // بسم الله
    AMR
    ll t = 1;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll a[n];
        for (ll &y : a) cin >> y;

        ll mn = *min_element(a, a + n);
        ll total = accumulate(a, a + n, 0LL);  
        if (total <= k) {
            cout << 0 << endl;
            continue;
        }

        sort(a, a + n);
        vector<ll> suf(n + 1, 0);
        for (ll i = n - 1; i >= 0; i--) suf[i] = suf[i + 1] + a[i];

        ll ans = total - k; 

        for (ll i = 0; i < n; i++) {
            ll cnt = n - i - 1;
            ll sum_last = (cnt == 0 ? 0 : suf[n - cnt]);
            ll rhs = k - total + mn + sum_last;
            ll tg = floordiv(rhs, cnt + 1);

            ll dec = 0;
            if (tg < mn) dec = mn - tg;  
            ll ops = cnt + dec;   
            ans = min(ans, ops);
        }

        cout << ans << endl;
    }
    return 0;
}
