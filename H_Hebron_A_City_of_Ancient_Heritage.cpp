#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;
int main()
{
    AMR
        ll t = 1;
    //cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n , -1 ) ;
        ll j = 1 ; 
        for(ll i = 0 ; i < n ; i ++){
            if(v[i] == -1 ){
            v[i] = j ; 
            j ++ ; 
            }
            if( i+k < n ){ 
                ll ii = i ; 
                while( (ii + k) < n && v[(ii + k)] == -1 ){
                v[ii+k] = j ;
                j ++ ; 
                ii += k ;  
                }
            }
        }
        for(ll y : v)cout << y << ' ';
    }
    return 0;
}
