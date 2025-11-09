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

long long C(ll n) {
    if (n < 2) return 0; 
    return (ll)n * (n - 1) / 2;
} 

int main()
{
    // بسم الله
    AMR
        ll t = 1;
    //cin >> t;
    next :
    while (t--)
    {
        ll n ; 
        cin >> n ; 
        vector<ll> a(n) ,m(n+1 , 0 ) ;
        set<ll> s ;  
        for(ll i = 0 ; i < n ; i ++){
            cin >> a[i] ; 
            m[a[i]] ++ ;
            s.insert(a[i]) ; 
        } 
        ll ans = 0 ; 
        for(ll x : s){
           if(m[x] >= 2){
            ans += C(m[x]) * (n- m[x]) ;
            //cout << x << ' '<< C(m[x]) << ' '<< (n-m[x]) << endl; 
           }
        }
        cout << ans << endl; 
    }
    return 0;
}
