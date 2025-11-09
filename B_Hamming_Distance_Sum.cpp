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
   //cin >> t;
    while (t--)
    {
        string a , b ; 
        cin >> a >> b ; 
        ll n = a.size() ; 
        ll n2 = b.size() ; 
        ll ans = 0 ; 
        ll cnt1 = 0 ; 
        ll cnt0 = 0 ; 
        for(ll i = 0 ; i < n; i ++){
            if(a[i] == '0')cnt0 ++ ; 
            else cnt1 ++ ; 

            if(b[i] == '0'){
                ans += cnt1 ; 
            }else{
                ans += cnt0 ; 
            }
        }
        //cout << ans << endl ;
        for(ll i = n ; i < (n2-n+1)  ; i ++ ){
              if(b[i] == '0'){
                ans += cnt1 ; 
            }else{
                ans += cnt0 ; 
            }
        }
        cout << ans ; 
    }
    return 0;
}
