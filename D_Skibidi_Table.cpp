#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
typedef unsigned __int128 bll;
void fn( ll &v , ll i , ll j , vector<vector<ll>> &a ){
    a[i][j] = v ; 
    v ++ ; 
    a[i+1][j+1] = v ;  
    v ++ ; 
    a[i+1][j] = v ; 
    v ++ ; 
    a[i][j+1] = v ; 
    v ++ ; 
    j ++ ; 
    i ++ ; 
}
int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
        ll n , q ; 
        cin >> n >> q ; 
        ll sz = pow(2,n) ; 
        ll v = 1 ;  
        vector<vector<ll>> a(sz , vector<ll>(sz , -1 ) );
        ll i = 0 , j = 0 ; 
        while( v != (sz*sz +1) ){
            
        }        
        /*
        fi(0,sz){
            fj(0,sz){
                cout << a[i][j] << ' '; 
            }
            cout << endl ;
        } 
*/
    }
    return 0;
}
