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
    cin >> t;
    while (t--)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        ll sm = x + y + z;
        ll t = sm / 3;
        bool ans = 1;
        if (t * 3 != sm)
            ans = 0;
        ll a = z - t;
        ll b = (t - x);
        ll c = (t - y);
        if (c < 0)
            c = 0;
        if (b < 0)
            b = 0;
        if (a != (b + c))
            ans = 0;
        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
