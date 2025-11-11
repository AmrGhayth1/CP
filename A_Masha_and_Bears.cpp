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
    ll v3, v2, v1, vm;
    cin >> v1 >> v2 >> v3 >> vm;
    if (((vm < v3) && v3 > (vm * 2)) ||( (vm > v3 ) && vm > (v3 * 2 ) ) || (vm >= v2 ))
    {
        cout << -1;
        return 0;
    }
    cout << v1 * 2 << endl;
    cout << max(v2, (2 * vm)+1) << endl;
    cout << max(v3 , vm) << endl;

    return 0;
}
