#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
typedef unsigned __int128 bl;

int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
        ll n ; 
        cin >> n ; 
        string s ;
        cin >> s ;
        char x = '0' ;
        ll ans = 0 ;   
        fi(0,n){
            if(s[i] != x )ans ++ ; 
            x = s[i] ; 
        }
        if(ans > 2)ans -= 2 ; 
        else if(ans  == 2 )ans -= 1 ; 
        cout << ans+n << endl ;
    }
    return 0;
}
