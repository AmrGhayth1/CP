
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
        ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a1(n), b1(n);
        vector<ll> a, b;
        for (ll &y : a1)
            cin >> y;
        for (ll &y : b1)
            cin >> y;
        for (ll i = 0 ; i < n ; i++)
        {
            if (a1[i] > b1[i])
            {
                a.push_back(a1[i]);
                b.push_back(b1[i]);
            }
        }
        sort(all(a));
        sort(all(b));
        n = a.size();
        ll ans = 0;
        vector<ll> add(n + 1 , 1);
        for(ll i = 0 ; i < n ; i ++){
         ll x = (ll)( lower_bound(all(b) , a[i]) - b.begin()) ;
      //   if(a[i] != b[x] )x ++ ; 
      cout << x << ' ';
         add[x] = (add[x]%MOD*2)%MOD ;
         }
         ll sm = 0 ; 
         for(ll i = 0 ; i <= n ; i ++ ){
            sm = add[i]-1 ;
            ans =  (ans%MOD + sm%MOD)%MOD ;
         }
 
        cout << ans << "\n";
    }
    return 0;
}