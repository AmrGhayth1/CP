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

ll value(ll a, ll b)
{
    ll a1 = 0;
    while (a > 1)
    {
        a = (a + 1) / 2;
        a1++;
    }
    ll b1 = 0;
    while (b > 1)
    {
        b = (b + 1) / 2;
        b1++;
    }
    return a1 + b1;
}
int main()
{
    AMR
        ll t = 1;
    cin >> t;
    while (t--)
    {
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
        ll v1 = value(x, b);
        ll v2 = value(x, y - b + 1);
        ll v3 = value(a, y);
        ll v4 = value(x - a + 1, y);
        ll ans = min(v1, min(v2, min(v3, v4)));
        cout << ans +1 << endl;
    }
    return 0;
}
