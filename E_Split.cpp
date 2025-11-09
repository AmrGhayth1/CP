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
        ll n , k  ;  
        cin >> n >> k ; 
        vector<ll> fq(n+2 , 0 ) ; 
        ll a[n] ;  
        for(ll & y : a){
            cin >> y ; 
            fq[y] ++ ; 
        }
        for(ll & y : a){
            if(fq[y] % k != 0){
                cout << 0 << endl; 
                goto next  ;
            }
        }
        vector<ll> freq(n+2 , 0 ) ; 
        ll r = 0 ;
        ll ans = 0 ;  
        for(ll l = 0 ;  l < n ;  l ++){
            while(r < n && freq[a[r]] < fq[a[r]] / k  ){
                freq[a[r]] ++ ; 
                r ++ ; 
            }
            ans += (r-l) ;
            freq[a[l]] -- ;  
        }
        cout << ans << endl; 
    }
    return 0;
}
