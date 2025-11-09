#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
typedef unsigned __int128 bll;
bool chek(ll a[] , ll b[] , ll n , ll m , ll x){
    ll r = 0 ;
    bool once = 1 ;  
    for(ll l = 0 ; l < n ; l ++){
        if(once && b[r] == x){
            once = 0 ; 
            r ++ ; 
        }
    //cout << a[l] << ' '<< b[r] << endl ;

        if(a[l] >= b[r] )r ++ ;
        
       

        if(r == m)return 1 ; 
    }
    return 0 ; 
}
int main()
{
    AMR
    ll t = 1 ;
    ll cnt = 0 ; 
   cin >> t;
    while (t--)
    {
        cnt ++ ; 
        ll n , k  ; cin >> n >> k  ;
        ll a[n] , b[k]  ; 
        for(ll x =0 ; x < n ; x++ )cin >> a[x] ; 
        for(ll y =0 ; y < k ;  y++  ){
            cin >> b[y]; 
        }

      
        if(chek( a , b , n , k ,  -1 ) ){
            cout << 0 << endl ;
            continue ; 
        }
        ll pf[n+1] , sf[n+1] ;
        ll r = 0 ;
        ll sm = 0 ;
        pf[0] = 0 ;  
        sf[n] = 0 ; 
        for(ll i =0 ; i  < n ; i ++ ){
            if(a[i] >= b[r]){
                sm ++ ; 
                r ++ ; 
            }
            pf[i+1] = sm ; 
        }
        r = k-1 ; 
        sm = 0 ;
       for(ll i = n-1 ; i >= 0  ; i -- ){
            if(a[i] >= b[r]){
                sm ++ ; 
                r -- ; 
            }
            sf[i] = sm ; 
        }
        ll ans = 1e18 ; 
        for(ll i = 0 ; i < n ; i ++){
            if( pf[i] + sf[i] + 1 == k  ){
                ans = min(ans , b[ pf[i] ]) ; 
            } 
        }
        if(ans == 1e18 )ans = -1 ; 
        if(cnt == 70 ){
 for(ll x =0 ; x < n ; x++ )cout << a[x] <<' ' ; 
 cout << endl << n << ' '<< k << endl ;
        for(ll y =0 ; y < k ;  y++  ){
            cout << b[y]<< ' ' ; 
        }
        }
        cout << ans << endl ;
    }
    return 0;
}
