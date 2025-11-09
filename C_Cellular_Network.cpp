#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define endl "\n"
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
typedef unsigned __int128 bll;

int main()
{
    AMR
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n);
        fi(0, n) cin >> a[i];
        vector<ll> b(m);
        fi(0, m) cin >> b[i];
        sort(all(b));
        ll ans = -1;
        ll l = 0 ; 
        fi(0, n)
        {
            while(l+1 < m && b[l+1] < a[i] )l ++ ;
            ll ax = abs(a[i] - b[l] );
            auto lb = lower_bound(all(b), a[i]);
            ll bx = abs(*lb - a[i]);
            ans = max(ans, min(ax, bx));
        }
        cout << ans;
    }
    return 0;
}