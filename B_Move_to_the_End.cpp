#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
typedef unsigned __int128 bll;

int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
        ll n ; 
        cin >>  n ; 
        ll a[n] ; 
        ll mx[n] ; 
        fi(0,n)cin >> a[i] ;
        ll m = 0 ;  
        fi(0,n){
            m = max( m , a[i]) ; 
            mx[i] = m ; 
        }
        ll sm = 0 ; 
        for(ll i = n-1 ; i>=0 ; i --){
            sm += a[i] ; 
            cout << sm -a[i] + mx[i] << ' ';  
        }
        cout << endl; 
    }
    return 0;
}
