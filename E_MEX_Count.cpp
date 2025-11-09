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
const ll MOD = 1e9 +7 ; 
int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
        ll n ; 
        cin >> n ; 
        vector<ll> v ; 
        map<ll,ll> m ; 
        ll adds = 0 ; 
        for(ll i = 0 ; i < n ;i ++){
            ll x ; cin >> x ; 
            m[x] ++ ; 
            if(m[x] == 1){
                v.push_back(x) ;
            }else{
                adds ++ ; 
            }
        }
        sort(all(v) ) ; 
        ll mex = v.size() ; 
        
        vector<ll> v2(n+10 , 0) ; 
        for(ll i = 0 ; i < v.size() ; i ++){
            if(v[i] != i){
                mex  = i ; 
                break; 
            }
        }
        vector<ll> k(n+10 , 0) ;
        ll y = 0 ; 
        for(ll i = 0 ; i < mex ; i ++){
            k[m[i]] ++ ; 
             k[n-i+1] -- ;
          // cout << i << ' ' << m[i] << ' '<< n-i+1  << endl ;
            y += m[i] ;
        } 
        k[n - mex +1 ] -- ; 
        k[0] = 1 ;
        ll sm = 0 ;
          
        for(ll i  = 0 ; i < n ; i ++){
            sm += k[i] ; 
            cout << sm << ' ' ;
        }
        cout << 1  << endl ;

    }
    return 0;
}
