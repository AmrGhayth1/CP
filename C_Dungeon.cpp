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
next:
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll a[n] ; 
        for (ll &i:a)cin >> i ; 
        sort(a , a+n) ; 
        vector<pair<ll,ll>> v(m) ; 
        for (auto &[x,y] : v)cin >> x ;
        for (auto &[x,y] : v)cin >> y ;
        sort(all(v)) ; 
        ll ans = 0 ;
        ll ind = 0 ;  
        for (ll i = 0 ; i < m && ind < n ; i ++){
            while(ind < n  && a[ind] < v[i].first ) ind ++ ;
            if(ind == n)break; 
            ll sw = a[ind] ; 
            bool T = 0 ; 
            while(i < m && sw >= v[i].first ){
                if(v[i].second <= 0 )break;
                sw = max(sw , v[i].second) ; 
                ans ++ ; 
                i ++ ; 
                T = 1 ; 
            }
            if(T)
            i -- ; 
        }
        cout << ans << endl;
    }
    return 0;
}
