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
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;
const ll MOD = 1e9 +7 ; 
ll f(ll n) {
    static vector<ll> a;
    static vector<int> b;
    if (a.empty()) {
        ll p[4] = {2, 3, 5, 7};
        int m = 1 << 4;
        a.resize(m);
        b.resize(m);
        for (int i = 0; i < m; ++i) {
            ll x = 1;
            int y = 0;
            for (int j = 0; j < 4; ++j) {
                if (i & (1 << j)) {
                    x *= p[j];
                    y++;
                }
            }
            a[i] = x;
            b[i] = (y % 2 == 0 ? 1 : -1);
        }
    }
    ll r = 0;
    int m = a.size();
    for (int i = 0; i < m; ++i) r += b[i] * (n / a[i]);
    return r;
}
int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
         ll l, r;
        cin >> l >> r;
        cout << f(r) - f(l - 1);
        if (t) cout << '\n';
    }
    return 0;
}
