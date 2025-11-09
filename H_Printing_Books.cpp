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
         string s ; 
         ll n ;  
        cin >> n >> s ;
        ll x = pow(10,s.size()) ;
        ll y = stoll(s) ;
        ll ans = 0 ; 
        ll a = 0 ; 
            for(ll i = s.size() ; i < 1e7 ; i ++  ){
                //cout << x << ' '<< y << ' '<< a << ' '<< ans << endl ; 
                ll b = (x-y)* i  ;
                if(a+b >= n  ){
                    if( (n-a)%i == 0   ){
                        ans +=  (n-a)/i ; 
                    }else{
                        ans = -1 ; 
                    }
                    break ; 
                }else{
                    a += b ; 
                }
                ans += (x-y) ;
                y = pow(10 , i ) ; 
                x = pow(10 , i+1 ); 
            }
            if(s.size() > n )ans = -1 ; 

        cout << ans << endl ;
    }
    return 0;
}
