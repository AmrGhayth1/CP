#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
typedef unsigned __int128 bll;
void play(set<ll> s){
    for(ll x :s){
        cout << x << ' ' ; 
    }
}
int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
        ll n ; 
        cin >>n ; 
        set<ll> s1 , s2 ;
        ll ans = 1 ; 
        ll y ; cin >> y ; 
        s1.insert(y) ;  
        for(ll i = 0 ; i < n-1 ; i ++){
            
            ll x ; cin >> x ; 
            s2.insert(x) ; 
            s1.insert(x) ;
            if(s1 == s2){
                ans ++  ; 
                s1.clear() ; 
                s1 = s2 ; 
                s2.clear() ;
            }
          
        }
        cout << ans << endl ;
    }
    return 0;
}
