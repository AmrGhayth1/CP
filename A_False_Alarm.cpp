#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
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
        ll n , x ; 
        cin >> n  >> x ;
        ll l = n-1 , r = 0 ;  
        for(ll i = 0 ; i < n ; i ++){
            bool b ; 
            cin >> b ; 
            if(b == 1){
                l = min (l , i ) ; 
                r = max(r , i) ; 
            }
        }
        if((r-l+1) <= x){
            cout << "YES" << endl ;
        }else{
            cout << "NO" << endl ;
        }
    }
    return 0;
}
