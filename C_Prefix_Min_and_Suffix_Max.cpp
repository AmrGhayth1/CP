#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
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
        ll a[n] ; 
        for(ll& y : a)cin >> y ;
        ll mn[n] ; 
        string ans ;
        ll m = a[0] ;
        for(ll i = 0 ; i < n ; i ++){
            m = min(m , a[i] ) ;
            mn[i] = m ; 
        }
        m = a[n-1] ; 
        for(ll i = n-1 ; i >= 0 ; i --){
            m = max(m , a[i]) ; 
            if(a[i] >= m || a[i] <= mn[i] ){
                ans.push_back('1')  ;
            }else{
                ans.push_back('0') ;
            }
        }
        reverse(all(ans)) ; 
        cout << ans << endl ; 
    }
    return 0;
}
