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
        ll n;
        cin >> n;
        fi(0, n)
        {
            ll x ;
            cin >> x ;
            double md = (n+1) / 2.0 ;
            if(x < md){
                cout << md + (md-x) <<' ';
            }else if( x > md){
                cout << md - (x-md) <<' ';
            }else{
                cout << x <<' ';
            }
        }
        cout << endl ;
        
    }
    return 0;
}
