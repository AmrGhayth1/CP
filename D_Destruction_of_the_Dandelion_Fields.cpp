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
        vector<ll> v ;
        ll ans = 0 ;  
        for(ll i = 0 ; i < n ; i ++){
            ll x ; 
            cin >> x ; 
            if(x% 2 == 0){
                ans += x ; 
            }else{
                v.push_back(x) ; 
            }
        }
        if(v.empty()){
            cout << 0 << endl; 
            continue;
        }
        sort(all(v) , greater<ll>());
        ll x = (v.size()+1)/2 ; 
        for(ll i = 0 ; i < x ; i ++){
            ans += v[i] ; 
        } 
        cout << ans << endl ; 
    }
    return 0;
}
