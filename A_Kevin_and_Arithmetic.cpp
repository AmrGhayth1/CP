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
int main()
{
    AMR int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll e = 0, d = 0;
        fi(0, n)
        {
            ll x;
            cin >> x;
            if (x % 2 == 0)
            {
                e++;
            }
            else
            {
                d++;
            }
        }
        ll ans = 0;
        if (e > 0)
        {
            ans++;
            ans += d;
        }
        else
        {
            ans += d - 2;
            ans ++ ;
        }
        if (ans < 0)
            ans = 0;
        cout << ans << endl;
    }

    return 0;
}
