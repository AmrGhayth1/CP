#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
#define endl "\n"
int main()
{
    AMR
        ll t = 1;
   // cin >> t;
    while (t--)
    {
        ll n;
        cin >> n ; 
        ll a[n];
        fi(0, n) cin >> a[i];
        ll x;
        ll y;
        fi(0, n)
        {
            ll mx = max( (a[n - 1] - a[i]) , (a[i] - a[0]) );
            if (i != 0)
            {
                x = a[i - 1];
            }
            else
            {
                x = 1e10;
            }
            if (i != n - 1)
            {
                y = a[i + 1];
            }
            else
            {
                y = 1e10;
            }
            ll mn = min(abs(x - a[i]), abs(y - a[i]));
            cout << mn << ' ' << mx << endl;
        }
    }
    return 0;
}
