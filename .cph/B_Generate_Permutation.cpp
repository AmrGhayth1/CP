#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
#define endl "\n"
int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
        ll n ; 
        cin >> n ; 
        if(n % 2 == 0)cout << -1 ; 
        else{ 
            ll md = (n / 2) ;
            ll a[n] ; 
            a[md] = 1 ;
            ll x = 2 ; 
            for( ll i = 1 ; i <= md  ; i ++){
            a[md+i] = x ; 
            x ++ ; 
            a[md - i ] = x ; 
            x ++ ; 
            } 
            fi(0,n)cout << a[i] <<' ';
        }
        cout << endl ;
    }
    return 0;
}
