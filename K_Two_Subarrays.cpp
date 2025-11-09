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
        ll a1[n] ;
        ll a2[n] ; 
   
        for(ll i = 0 ; i < n ; i++ ){
          ll x ; 
          cin >> x ;
          if(i%2== 0 ){
            a1[i] = x ;
            a2[i] = -x;  
          }else{
            a1[i] = -x ;
            a2[i] = x ;  
          }
        }
        ll p1 = 0 , p2 = 0 ; 
       ll l = 0  , r =  n-1 ; 
       ll mx1 = -1e18 ; 
        for(ll i = 0 ; i <n ; i ++){
            p1 += a1[i] ;
            if(p1 > mx){
                r = i ;
                mx = p1 ;  
            }
            if(p1 < 0 ){
                p1 = 0 ; 
                l = i ; 
            }
        }
       cout << "Max_Sum_Of_Subarray" << mx1 << "Its_Range " << l << ' '<< r << endl ; 
        
    }
    return 0;
}