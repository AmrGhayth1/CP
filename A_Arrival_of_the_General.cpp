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
        ll n;
    cin >> n;
    ll a[n];
    fi(0, n)
    {
        cin >> a[i];
    }
    ll mx = *max_element(a, a + n);
    ll mn = *min_element(a, a + n);
    ll fs;
    fi(0, n)
    {
        if (a[i] == mx)
        {
            fs = i;
            break;
        }
    }
    ll ls;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (a[i] == mn)
        {
            ls = i;
            break;
        }
    }
    ll ans =( fs + (n -ls)) - 1  ;
    if(fs >= ls)ans -- ;
    cout << ans ; 
    return 0;
}
