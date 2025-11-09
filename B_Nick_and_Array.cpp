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
    ll mx = 0 ;
    ll ind = 0 ;
    fi(0, n)
    {
        cin >> a[i];
        if(a[i] >= 0){
            a[i] = -a[i] - 1;
        }
        if(abs(a[i]) > mx){
            mx = abs(a[i]) ;
            ind  = i ;
        }
    }
    if(n%2 == 1){
    a[ind] = -a[ind] -1 ;
    }
    
    fi(0,n){
        cout << a[i] <<' ';
    }
    return 0;
}
