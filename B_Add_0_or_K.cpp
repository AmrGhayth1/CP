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
        ll n , k ; 
        cin >> n >> k ; 
        ll a[n] ; 
        for(ll & y : a)cin >> y ;

        ll tg = k == 1 ? 2 : k-1 ;
        if(k  == 2 ){
            k = 2 ; 
            tg = 3 ; 
        }
        for(ll i = 0 ; i < n ; i ++){
            ll x = a[i] % tg ; 
            if(x){
                if(k == 2){
                    while(a[i] %3 != 0 )a[i] += 2 ;
                }else{
                a[i] += (tg-x)*k ; 
                }
            }

        }
        ll g = 0 ; 
        for(ll y : a){
            g = gcd(y , g) ; 
            cout << y << ' ' ;
        }
        cout << endl ; 
       // cout << g << endl  ; 
    }
    return 0;
}
