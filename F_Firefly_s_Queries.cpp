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
        ll n, q;
        cin >> n >> q;
        ll pf[n+1];
        ll sm = 0;
        pf[0] = 0;
        for (ll i = 1; i <= n ; i++)
        {
            ll x;
            cin >> x;
            sm += x;
            pf[i] = sm;
        }
        while (q--)
        {
            ll l, r;
            cin >> l >> r;
            l--;
            
            ll ans = 0;
            ll shf = (l / n) % n;
            ll rm = (l % n);
            ll ind = (shf + rm) % n;
            if ((rm + shf) < n)
            {
                ans += pf[n] - pf[rm + shf ];
                ind = 0 ;
            }
            ans += pf[shf] - pf[ind];
            l += (n - rm) ; 

             shf = (r / n) % n ; 
             rm = (r % n) ; 
             ind = (shf + rm) % n ; 
            if ((rm + shf) < n)
            {
                ans -= pf[n] - pf[rm + shf];
                ind = 0;
            }
            ans -= pf[shf] - pf[ind];
            r += (n- rm) ; 
            
            ans += pf[n] * ((r-l) / n ) ; 
            cout << ans << endl ; 
        }
    }
    return 0;
}