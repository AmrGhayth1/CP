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
    AMR
        ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        map<ll, ll> m;
        ll x = 1;
        fi(0, n)
        {
            cin >> a[i];
            if (i > 0)
            {
                if (a[i] == a[i - 1])
                {
                    x++;
                }
                else if (a[i] != a[i - 1])
                {
                    if (m[a[i - 1]] < x)
                    {
                        m[a[i - 1]] = x;
                    }
                    x = 1;
                }
            }
            if (i == n - 1)
            {
                if (m[a[i]] < x)
                {
                    m[a[i]] = x;
                }
            }
        }
        ll b[n];
        map<ll, ll> mb;
        ll y = 1;
        fi(0, n)
        {
            cin >> b[i];
            if (i > 0)
            {
                if (b[i] == b[i - 1])
                {
                    y++;
                }
                else if (b[i] != b[i - 1])
                {
                    if (mb[b[i - 1]] < y)
                    {
                        mb[b[i - 1]] = y;
                    }
                    y = 1;
                }
            }
            if (i == n - 1)
            {
                if (mb[b[i]] < y)
                {
                    mb[b[i]] = y;
                }
            }
        }
        ll ans = 1;
        fi(0, n)
        {
            ll xx = m[a[i]] + mb[a[i]];
            ll yy = m[b[i]] + mb[b[i]];
            if (ans < xx)
                ans = xx;
            if (ans < yy)
                ans = yy;
        }

        cout << ans << endl;
    }
    return 0;
}
