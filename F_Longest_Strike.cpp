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
        ll n, k;
        cin >> n >> k;
        ll a[n];
        map<ll, ll> m;
        bool No = true;
        for (ll &y : a)
        {
            cin >> y;
            m[y]++;
            if (m[y] >= k)
                No = false;
        }
        if (No)
        {
            cout << -1 << endl;
            goto next;
        }
        vector<ll> can;
        for (ll &element : a)
        {
            if (m[element] >= k)
            {
                m[element] = 0;
                can.push_back(element);
            }
        }
            sort(all(can));
            ll R = 0;
            ll max_range = 0 ;
            ll ans = can[0] ;  
            for (ll L = 0; L < can.size(); L++)
            {
                R = max(L , R ) ; 
                while (R < can.size()-1  && can[R + 1] == can[R] + 1)
                {
                    R++;
                }
                if(can[R] - can[L] > max_range ){
                    max_range = can[R] - can[L] ; 
                    ans = can[L]  ;
                }
            }
            cout << ans << ' ' <<  ans + max_range << endl;  
    }
    return 0;
}
