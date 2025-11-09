#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
typedef unsigned __int128 bll;

ll op(ll m , ll cnt , ll j , ll b[] , ll i ){
    if(i %2 == 0 ){
        if( j %2 == 0 ){
            return ( b[m-1- cnt] ) ; 
        }else{
            return ( b[cnt] ) ; 
        }
    }else{
        if( j %2 == 0 ){
            return ( b[cnt] ) ; 
        }else{
            return ( b[m-1- cnt] ) ; 
        }
    }
}
int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
        ll n , m ; 
        cin >> n >> m ; 
        ll b[m] ; 
        for(ll &x : b)cin >> x; 
        sort(b,b+m) ; 
        ll a[n][6] ;
        if(m  n  ){
        ll cnt = -1 ;  
        for(ll i = 0 ; i < n ; i ++){
            for(ll  j = 0 ; j < 6 ; j ++ ){
                            cnt = i/2 ; 
                cout <<  op( m , (cnt + (j/2) )% ((m+1)/2)  , j , b , i ) << ' ' ; 

            }
            cout << endl ;
        }
    }else{
        ll cnt = 0 ; 
          for(ll i = 0 ; i < n ; i ++){

            for(ll  j = 0 ; j < 6 ; j ++ ){
                cout <<  op( m , ((i/2) )% ((m+1)/2)  , j , b , i ) << ' ' ; 

            }
            cout << endl ;
        }
    }
        
    }
    return 0;
}
