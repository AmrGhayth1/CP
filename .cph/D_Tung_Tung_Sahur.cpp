#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
#define endl "\n"
int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
        string s , p ; 
        cin >> p >> s ;
        bool ans = 1 ;  
        int m = p.size();
        int n = s.size();
        ll i = 0 , j = 0 ; 
        while(i < m){
         ll cnt1 = 0 ; 
         char x = p[i] ; 
         while( i < m &&  p[i] == x ){
            cnt1 ++ ; 
            i ++ ;
         } 
         if(s[j] != x)ans = 0 ;
         ll cnt2 = 0 ; 
         while( j < n &&  s[j] == x ){
            cnt2 ++ ; 
            j ++ ;
         }
         if( cnt2 < cnt1 || cnt1*2 < cnt2)ans = 0 ; 
        if(p[i] != s[j])ans = 0 ;
        }
        if(ans){
            cout << "YES" << endl ;
        }else{
            cout << "NO" << endl ;
        }
    }
    return 0;
}
