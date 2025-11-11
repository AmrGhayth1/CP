#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define fk(kk, n) for (ll k = kk; k < n; k++)
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
    //cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        fi(0, n) cin >> a[i];
        ll ans = 0;
        ll mx = *max_element(a,a+n) ;
        ll mn = *min_element(a,a+n) ; 
        cout << mx - mn << endl;
        cout << gcd( 33 , 36 ) ;
    }
    return 0;
}
