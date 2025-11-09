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
        ll a[n] , b[n] ; 
        for(ll &x : a)cin >> x ;
        for(ll &x : b)cin >> x ;
        map<ll , bool > m ;
        ll ans = 0 ;  
        for(ll i = n-1 ; i >= 0  ; i --){
            if(b[i] == a[i] || (i != n-1 && ( (a[i+1] == b[i+1] ) || (a[i] == a[i+1]) || b[i] == b[i+1]  ) )  ){
                ans = i+1 ; 
                break ; 
            }
            if(i < n-2 &&(m[a[i]] == 1 || m[b[i]] == 1) ){
                ans = i+1 ; 
                break ; 
            }
            if(i != n-1 ){
            m[b[i+1]] = 1 ; 
            m[a[i+1]] = 1 ; 
            }
    }
    cout << ans << endl ;
    }
    return 0;
}