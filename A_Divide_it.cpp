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
        ll ans = 0;
        ll n;
        cin >> n;
        while (1)
        {
            if (n % 2 == 0)
            {
                n = n / 2;
                ans++;
            }
            else if (n % 3 == 0)
            {
                n = n * 2 / 3;
                ans++;
            }
            else if (n % 5 == 0)
            {
                n = n * 4 / 5;
                ans++;
            }
            else
            {
                break;
            }
        }
        if (n == 1)
        {
            cout << ans << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
