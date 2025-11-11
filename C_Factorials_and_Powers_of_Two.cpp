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
ll ans;
void fc(ll n, ll count, ll y)
{
    if (n < 0)
        return;
    ans = min(ans, count + __builtin_popcountll(n));
    if (count >= ans)
        return;
    ll x = 1;
    for (ll i = 2; i <= y; ++i)
    {
        x *= i;
        if (x > n)
            break;

        fc(n - x, count + 1, i - 1);
    }
}
int main()
{
    AMR
        ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ans = __builtin_popcountll(n);
        fc(n, 0, 15);
        cout << ans << endl;
    }
    return 0;
}
