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
        ll n ; 
        cin >> n ;
        ll a[n]  ;
        for(ll i = 0  ; i< n ; i++)cin >> a[i] ;
        bool lst = 0 ;
        ll ans = 1 ;  
        for(ll i = 0 ; i < n ; i ++ ){
            if(a[i] == 0)lst = 1 ;
            if(i > 0 && a[i] == 0 && a[i-1] == 0 )ans = 0 ; 
        } 
        if(ans && lst){
            cout << "NO" << endl ; 
        }else{
            cout << "YES" << endl ;
        }
    }
    return 0;
}
