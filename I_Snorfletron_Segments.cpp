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
vector<ll> sgtree;
ll sz ; 
void query(ll nd, ll l, ll r, ll k, ll &ans)
{
    if (sgtree[nd] == k && r < sz){
        ans++;
        cout << nd << ' '<< l << ' '<< r << endl ;
    }
    if (l == r)
        return;
    ll md = (l + r) / 2;
    query(2 * nd, l, md, k , ans ) ;
    query(2 * nd + 1, md + 1, r, k , ans );

}

void build(vector<ll> &a, ll &n)
{
    ll pw = 1;
    while (pw < n)
        pw <<= 1;
    n = pw;
    a.resize(n, 0);
    sgtree.resize(2 * n);
    for (ll i = 0; i < n; i++)
    {
        sgtree[n + i] = a[i];
    }
    for (ll i = n - 1; i >= 1; i--)
    {
        sgtree[i] = sgtree[i * 2] + sgtree[i * 2 + 1];
    }
}

int main()
{
    AMR
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n) ;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            if (x % (k + 1) == 0)
            {
                a[i] = 0;
            }
            else
            {
                a[i] = 1;
            }
        }
         sz = n ; 
        build(a , n );
        ll ans  = 0 ; 
        query(1 , 0 , n-1 , 1 , ans )  ; 
       /* for (ll i = 1; i <= sz ; i++)
        {
            ll ans = 0 ; 
            query(1 , 0 , n-1 , i , ans ) ; 
            cout << ans << ' ' ;
        }
            */
    }
    return 0;
}
