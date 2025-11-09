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
        ll n;
        cin >> n;
        vector<ll> a(n), c(n);
        for (ll &y : a)
            cin >> y;
        for (ll &y : c)
            cin >> y;
        vector<ll> dp1(n + 1 , 1e18 ) , dp2(n+1 , 0 );
        for (ll i = n - 1; i >= 0; i--)
        {
            for (ll lst = 0; lst <= n; lst++)
            {
                ll mn = lst == n ? -1e18 : a[lst];
                if (a[i] >= mn)
                {
                    dp1[lst] = min(dp1[lst], dp2[i]);
                }
                dp1[lst] = min(dp1[lst], dp2[lst] + c[i]);
            }
            dp2 = dp1 ; 
            if(i)
            fill(all(dp1) , 1e18) ;
        }
        ll ans = *min_element(all(dp1));
        cout << ans << endl;
    }
    return 0;
}
