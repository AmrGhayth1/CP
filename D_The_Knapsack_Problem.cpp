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
    //cin >> t;
    while (t--)
    {
        ll s , n ; 
        cin >> s >> n ; 
        vector<ll> dp(s+1 , 0 ) ; 
        pair<ll,ll> a[n] ; 
        for(auto& p : a)cin >> p.first >> p.second ;
        for(ll i = 0 ; i < n ; i ++){
            for(ll j = s ; j >= 0  ; j --){
                if(j - a[i].first >= 0 ){
                    dp[j] = max(dp[j] , dp[j-a[i].first] + a[i].second ) ; 
                }
            }
        }
        cout << dp[s] ;
    }
    return 0;
}
