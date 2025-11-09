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
        ll n , x ; 
        cin >> n >> x ; 
        ll a[n] ; 
        map<ll,ll> exist ; 
        for(ll& element : a){
            cin >> element  ; 
            exist[element] = 1 ; 
        } 
        ll ans = 0 ;
        while(true){
            if(exist[ans +1 ] == 1 ){  // he take this rank once in the array 
                ans ++ ; 
            }else{     // he not take this rank before so we will assume in future he will take it and x --
                if(x == 0)break; // no more days in future available 
            x -- ; 
            ans ++ ; 
        }
    }
      
        cout << ans  << endl ; 
    }
    return 0;
}
