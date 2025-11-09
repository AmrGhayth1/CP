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
        cin >> n ; 
        ll tg = (n+1)/2 ;
        ll x  ;
        cin >> x ;
        x = abs(x) ;  
        ll cnt = 0 ; 
        fi(0,n-1){
            ll y ; 
            cin >> y ; 
            if( abs(y) < x)cnt ++ ; 
        }
        ll cnt2 = n - cnt ;  
        if(cnt < tg  || cnt2 ==  tg){
            cout << "YES" << endl ; 
        }else {
            cout << "NO" << endl ;
        }
    }
    return 0;
}
