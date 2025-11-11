#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define endl "\n"
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
typedef unsigned __int128 bl;

int main()
{
    AMR
        ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll a[n];
        ll b[n];
        ll mn[n];
        fi(0, n) cin >> a[i];
        fi(0, n) cin >> b[i];
        fi(0, n) mn[i] = min(a[i], b[i]);
        ll ans = 0;
        fi(0, n)
        {
            ans += max(a[i], b[i]);
        }
        sort(mn, mn + n);
        reverse(mn, mn + n);
        fi(0, k - 1) ans += mn[i];
        cout << ans + 1 << endl;
    }
    return 0;
}
