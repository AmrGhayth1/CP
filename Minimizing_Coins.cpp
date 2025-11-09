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
    // cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll a[n];
        vector<ll> dp(k + 1, 1e17 );
        for (ll &y : a){
            cin >> y;
        }
        dp[0] = 0 ;
        for (ll j = 0; j < n; j++)
        {
            for (ll i = 0; i <= k; i++)
            {
                if (a[j] <= i)
                    dp[i] = min(dp[i] ,  dp[i-a[j]] +1 ) ;
            }
        }
        if(dp[k] >= 1e17 )dp[k] = -1 ; 
        cout << dp[k];
    }
    return 0;
}
