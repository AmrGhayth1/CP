#include <bits/stdc++.h>
using namespace std;
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

vector<ll> tree;
 
vector<ll> ans , pf , sf ; 


ll query(ll nd, ll l, ll r, ll ql, ll qr)
{
    if (ql <= l && r <= qr)
    {
        return tree[nd];
    }
    if (l > qr || r < ql)
    {
        return 0;
    }
    ll md = (l + r) / 2;
    return query(2 * nd, l, md, ql, qr) + query(2 * nd + 1, md + 1, r, ql, qr);
}

void update(ll i, ll v, ll n)
{
    tree[i + n] = v;
    sf[i+n] = v ; 
    pf[i+n] = v ; 
    ans[i+n] = v ; 
    for (ll j = (n + i) / 2; j >= 1; j /= 2)
    {
        tree[j] = tree[j * 2] + tree[j * 2 + 1];
       pf[j] = max(pf[j*2] , tree[j*2] + pf[j*2 + 1 ]  ) ; 
        sf[j] = max(sf[j*2 +1 ] , tree[j*2 +1 ] + sf[j*2] ) ;
        ans[j] = max(ans[j*2] , max(ans[j*2 +1] , pf[j*2 +1 ] + sf[j*2] )) ; 
   }
}

void build(vector<ll> &a, ll &n )
{
    while (__popcount(n) != 1)
    {
        n++;
        a.push_back(0);
    }
    tree.resize(2 * n);
    ans.resize(2 * n);
    pf.resize(2 * n);
    sf.resize(2 * n);


    for (ll i = 0; i < n; i++)
    {
        tree[n + i] = a[i];
        pf[n+i] =  a[i]  ;
        sf[n+i] =  a[i]  ; 
        ans[n+i] =  a[i]  ; 
    }
    for (ll i = n - 1; i >= 1; i--)
    {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
        pf[i] = max(pf[i*2] , tree[i*2] + pf[i*2 + 1 ]  ) ; 
        sf[i] = max(sf[i*2 +1 ] , tree[i*2 +1 ] + sf[i*2] ) ;
        ans[i] = max(ans[i*2] , max(ans[i*2 +1] , pf[i*2 +1 ] + sf[i*2] ))  ; 

    }
}
int main()
{
    AMR
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, q;
        cin >> n >> q;
        vector<ll> a(n);
        for (ll &y : a)
            cin >> y;
 
        build(a, n );
        cout << ans[1]  << endl ; 
        while (q--)
        {
                ll i, v;
                cin >> i >> v;
                update(i, v, n );
                cout << ans[1] << endl ; 
        }
    }
    return 0;
}