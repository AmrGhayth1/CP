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
    while (t--) {
        ll n;
        cin >> n ;
        string s;
        cin >> s;
        
        ll a = 0, b = 0;
        for (char c : s) {
            if (c == 'a') ++a;
            else ++b;
        }
        
        if (a - b == 0) {
            cout << 0 << endl ;
            goto next ; 
        }
        
        map<ll,ll> m;
        map<ll,bool> vs ; 
        m[0] = 0; 
        
        ll pf = 0;
        ll ans = n + 1;
        for (ll i = 0; i < n; ++i) {
            pf += (s[i] == 'a' ? 1 : -1);
            if(vs[pf] == 0){
                
                 m[pf] = i + 1;
            }
            if (m[ pf - a - b] == 0) {
                ans = min(ans, (i + 1) - m[ pf - a - b]);
            }
        }
        
        if (ans == n) cout << -1 << endl ;
        else cout << ans << endl ;
    }
    return 0;
}
