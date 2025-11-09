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
        ll m = 2 * n;
        ll a[m];
        ll ev[m + 1];
        ll od[m + 1];
        ll pf[m+1];
        ev[0] = 0 ; 
        od[0] = 0 ; 
        pf[0] = 0 ; 
        ll sm_od = 0;
        ll sm_ev = 0;
        for (ll i = 0; i < m; i++)
        {
            cin >> a[i];
            sm_ev += i % 2 == 0 ? 0 : a[i];
            sm_od += i % 2 == 1 ? 0 : a[i];
            ev[i+1] = sm_ev;
            od[i+1] = sm_od;
            pf[i+1] = sm_od + sm_ev ; 
        }
        vector<ll> ans;
        for(ll i = 0 ; i < n ; i ++){
            ll x = abs((ev[m-i ] - ev[i] )-( od[m-i] - od[i])) ;
            ll y = (pf[m] - pf[m-i]) - (pf[i] ); 
            ans.push_back(x+y); 
        }
        for (ll &y : ans)
            cout << y << ' ';
        cout << endl;
    }
    return 0;
}
