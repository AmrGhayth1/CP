#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
typedef unsigned __int128 bll;

int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll a[n];
        fi(0,n)cin >> a[i] ; 
        sort(a , a + n );
        ll m = n - k;
        ll lp = (m - 1) / 2;
        ll rp = m / 2;
        
        ll mn = LONG_MAX;
        ll mx = 0 ;
        for (ll i = 0; i + m <= n; ++i) {
            ll l = a[i + lp];
            ll r = a[i + rp];
            if (l < mn) {
                mn = l;
            }
            if (r > mx) {
                mx = r;
            }
        }
        
        cout << mx - mn + 1 << endl;
    }
    
    return 0;
}
