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
        ll n ,m ; 
        cin >> n >> m ;
        vector<vector<ll>> s(n) ;
        vector<ll> freq(m+1 , 0 ) ; 
        for(ll i = 0 ; i < n ; i ++){
            ll l ; 
            cin >> l ; 
            while(l--){
                ll x ; cin >> x ; 
                s[i].push_back(x) ;
                freq[x] ++ ;  
            }
        }
        for(ll i = 1 ; i <= m ; i ++ ){
            if(!freq[i]){
                cout << "NO\n" ; 
                goto next ;
            }
        }
         int ans = 0 ; 
        for(ll i = 0 ; i < n ; i ++){
           bool T = 0 ; 
            for(ll x : s[i]){
                if(freq[x] == 1 ){
                    T = true ; 
                    break; 
                }
            }
            if(!T)ans ++ ; 
        }
        if(ans >=2 ){
            cout << "YES\n" ; 
        }else{
            cout << "NO\n" ; 
        }
    }
    return 0;
}
