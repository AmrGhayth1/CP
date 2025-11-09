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
        ll x, y;
        cin >> x >> y;
        ll m = 6 - max(x, y) +1 ;
        ll d = 6;
        while (m != 1)
        {
            if (m % 2 == 0 && d % 2 == 0)
            {
                m /= 2;
                d /= 2;
            }
            else if (m % 3 == 0 && d % 3 == 0)
            {
                m /= 3;
                d /= 3;
            }
            else
            {
                break;
            }
        }
        cout << m << '/' << d;
    }
    return 0;
}
