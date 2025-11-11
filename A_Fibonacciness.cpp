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
        ll a[5];
        fi(0, 5)
        {
            if (i != 2)
            {
                cin >> a[i];
            }
            else
            {
                a[2] = a[1] + a[0];
            }
        }
        ll ans = 0;
        fi(0, 4)
        {
            if (a[i + 2] == a[i] + a[i + 1])
            {
                ans++;
            }
        }
        ll ans1 = 0;
        a[2] = a[4] - a[2];
        fi(0, 4)
        {
            if (a[i + 2] == a[i] + a[i + 1])
            {
                ans1++;
            }
        }
        ll ans2 = 0;
        a[2] = a[4] - a[3];
        fi(0, 4)
        {
            if (a[i + 2] == a[i] + a[i + 1])
            {
                ans2++;
            }
        }
        cout << max(ans, max(ans1, ans2)) << endl;
    }
    return 0;
}
