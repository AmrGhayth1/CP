#include <bits/stdc++.h> 
using namespace std;
#define ll long long
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
   //cin >> t;
    while (t--)
    {
        while(1){
        ll r = 1e9 ;  
        ll l = 0 ; 
        ll md = r+l/2 ;
        char x ; 
        cout << md  ; 
        cin >> x ; 
        if(x == '='){
            break ; 
        } else if(x == '<'){
            r = md -1 ; 
        }else{
            l = md + 1 ; 
        }
        }
    }
    return 0;
}
