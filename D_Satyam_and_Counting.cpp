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
        vector<bool> a0(200001 , false), a1(200001 , false);
        ll n;
        cin >> n;
        for (ll i = 0; i < n; i++)
        {
            ll c, x;
            cin >> x >> c ;
            if (c)
                a1[x] = true ;
            else
                a0[x] = true ;
        }
        ll ans = 0;
        for (ll x = 0 ; x <= n ; x ++ )
        {
            if (a1[x] && a0[x])
                ans += n - 2;
            if (a0[x] && a1[x + 1] && a0[x + 2])
                ans++;
            if (a1[x] && a0[x + 1] && a1[x + 2])
                ans++;
        }
        cout << ans << endl  ; 
    }
    return 0;
}
