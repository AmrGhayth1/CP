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
    next :
    while (t--)
    {
        ll n ; 
        cin >> n ; 
        vector<ll> a ; 
        bool st  = 0 ; 
        ll limit = log2(n) ; 
        ll cnt = 0 ; 
        for(ll i = 0 ; i <= limit ; i ++ ){
            ll bt = 0 ; 
            if( (1LL << i) & n ){
                st = 1 ;  
                bt = 1  ;
                cnt ++ ;  
            }
            if(st){
                a.push_back(bt) ; 
            }
        }
        bool ans = 1 ; 
        for(ll i = 0 ; i < a.size() ; i ++){
            ll ptr = a.size() - i -1; 
            if(a[ptr] != a[i] )ans = 0 ; 
           // cout << a[i] << ' '<< a[ptr] << endl ;
           // cout << a[i] <<  ' ';
        }
        if( ! ans || cnt %2 == 1  ){
            cout << "NO" << endl ; 
        }else{
            cout << "YES" << endl ;
        }
    }
    return 0;
}
