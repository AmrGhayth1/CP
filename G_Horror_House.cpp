#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
#define endl "\n"
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
 typedef unsigned __int128 bl;
int main()
{
    AMR
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, q;
        cin >> n >> q;
        ll a[n];
        fi(0, n) cin >> a[i];
        ll x;
        cin >> x;
        bl k = 1;
        ll r = 0;
        ll ans = 0;
        map<ll,ll> m ; 
        fi(0, n)
        {
            if (i > 0 && m[a[i-1]] == 1 )
                k /= a[i - 1];
                r = max(r , i) ; 
            while (r < n && a[r] <= x && k <= x && (bl)(k * a[r]) <= x)
            {
                k *= a[r];
                ans = max(ans, r - i + 1);
               // cout << i << ' '<< r << ' ' << (ll)(k) << endl ;
                m[a[r]] = 1 ;
                r++;
            }
        }
        cout << ans;
    }
    return 0;
}
