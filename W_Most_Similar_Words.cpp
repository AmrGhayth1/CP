#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
        ll n , m ; 
        cin >> n >> m ; 
        string grid[n] ;
        for(ll i = 0 ; i < n ; i ++ ){
            cin >> grid[i] ; 
        }
        ll ans =  1e9 ; 
        for(ll ai = 0 ; ai < n ; ai ++){
                for( ll bi = ai+1 ; bi < n  ; bi ++ ){
                    ll dff = 0 ; 
                    if(bi != ai){
                        for(ll j = 0 ; j < m ; j ++){
                            dff += abs( grid[ai][j] - grid[bi][j] ) ;    
                        }
                        ans = min(ans , dff );
                 }
            }
        }
        cout << ans  << endl ;
    }
    return 0;
}
