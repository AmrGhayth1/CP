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
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;

vector<ll> sgtree, lazy;

void push(ll nd, ll l, ll r) {
    if (lazy[nd]) {
        sgtree[nd] += (r - l + 1) * lazy[nd]; // apply pending update
        if (l != r) { // not a leaf node
            lazy[2 * nd] += lazy[nd];
            lazy[2 * nd + 1] += lazy[nd];
        }
        lazy[nd] = 0;
    }
}

ll query(ll nd, ll l, ll r, ll ql, ll qr) {
    push(nd, l, r);
    if (ql > r || qr < l) return 0;
    if (ql <= l && r <= qr) return sgtree[nd];
    ll md = (l + r) / 2;
    return query(2 * nd, l, md, ql, qr) + query(2 * nd + 1, md + 1, r, ql, qr);
}

void range_update(ll nd, ll l, ll r, ll ql, ll qr, ll val) {
    push(nd, l, r);
    if (qr < l || ql > r) return;
    if (ql <= l && r <= qr) {
        lazy[nd] += val;
        push(nd, l, r);
        return;
    }
    ll md = (l + r) / 2;
    range_update(2 * nd, l, md, ql, qr, val);
    range_update(2 * nd + 1, md + 1, r, ql, qr, val);
    sgtree[nd] = sgtree[2 * nd] + sgtree[2 * nd + 1];
}

void build(vector<ll> &a, ll &n) {
    ll pw = 1;
    while (pw < n) pw <<= 1;
    n = pw;
    a.resize(n, 0);
    sgtree.assign(2 * n, 0);
    lazy.assign(2 * n, 0);
    for (ll i = 0; i < n; i++) {
        sgtree[n + i] = a[i];
    }
    for (ll i = n - 1; i >= 1; i--) {
        sgtree[i] = sgtree[i * 2] + sgtree[i * 2 + 1];
    }
}
int main()
{
    AMR
    ll t = 1 ;
   //cin >> t;
    while (t--)
    {
        ll n , q ; 
        cin >> n >> q ; 
        vector<ll>a(n ) ;
        build(a , n ) ;
        while(q--){
            ll c ; 
            cin >> c ; 
            if( c == 1){
                ll l  , r , v ; 
                cin >> l >> r >> v ; 
                range_update(1 , 0 , n -1 , l , r-1 , v ) ;
            }else{
                ll i ; 
                cin >> i ; 
                cout << query(1 ,0 , n-1 , i , i ) << endl ;
            }
        }
        
    }
    return 0;
}
