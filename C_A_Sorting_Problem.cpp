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
struct Fenwick {
    ll n;
    vector<ll> f;
    Fenwick(ll _n): n(_n), f(n+1,0) {}

    // add +v at index i
    void update(ll i, ll v=1) {
        for(; i <= n; i += i&-i)
            f[i] += v;
    }
    // sum of [1..i]
    ll query(ll i) const {
        ll s = 0;
        for(; i > 0; i -= i&-i)
            s += f[i];
        return s;
    }
    // sum of [l..r]
    ll query(ll l, ll r) const {
        if(l>r) return 0;
        return query(r) - query(l-1);
    }
};
int main()
{
    AMR
    ll t = 1 ;
   //cin >> t;
    while (t--)
    {
    ll n;
    cin >> n;
    vector<ll> p(n+1), ind(n+1);
    for(ll i = 1; i <= n; i++){
        cin >> p[i];
        ind[p[i]] = i;
    }

    Fenwick fw(n);
    ll inv = 0;

    for(ll j = 1; j <= n; j++){
        ll idx = ind[j];
        inv += fw.query(idx+1, n);
        fw.update(idx, 1);
    }

    cout << inv << endl ;
    }
    return 0;
}
