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
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        ll mn = LLONG_MAX ;
        ll ind;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] < mn)
            {
                mn = a[i];
                ind = i;
            }
        }

        ll gc = 0;
        for (ll i = 0; i < n; ++i)
        {
            if (a[i] % mn == 0 && i != ind)
            {
                gc = __gcd(gc, a[i]);
            }
        }

        if (gc == mn)
        {
            cout << "Yes";
        }
        else
        {
            cout << "No";
        }
        cout <<  endl ; 
    }

    return 0;
}
