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
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;
const ll MOD = 1e9 + 7;

int main()
{
    // بسم الله
    AMR
        ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n ; 
        cin >> n ; 
        ll a[n] ; 
        for(ll& y : a)cin >> y ;
        bool T = 1  ; 
        for(ll i = 0 ; i < n -2 && T ; i ++){
            vector<ll> v = {a[i] , a[i+1] , a[i+2]} ; 
            sort(all(v)) ; 
            ll mex ; 
            for(mex = 0 ; mex < 3 ; mex ++)if(mex != v[i])break;
            ll cnt = count(all(v) , -1 ) ; 
            if(cnt >= 2 )continue; 
            if(cnt == 0 && v[2] - v[0] == mex )continue; 
            if(cnt == 1){
                
            }
        }
    }
    return 0;
}
