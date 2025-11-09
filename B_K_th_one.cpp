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

ll query(ll nd, ll l, ll r, ll k)
{
   // cout << nd << endl ;
    if(l == r )return r ;
      ll  md = (l + r) / 2;
      if(tree[nd *2 ] < k){
        return query(  nd *2 +1 , md +1  , r , k - tree[nd *2 ]) ;  
      }else{
        return query(  nd *2  , l  , md , k ) ;  
      }
      
    
}

void update(ll i, ll v, ll n)
{
    tree[i + n] = v;
    for (ll j = (n + i) / 2; j >= 1; j /= 2)
    {
        tree[j] = tree[j * 2] + tree[j * 2 + 1];
    }
}

void build(vector<ll> &a, ll &n)
{
     ll pw = 1;
    while (pw < n) pw <<= 1;
    n = pw;
    a.resize(n, 0);
    tree.resize(2 * n);
    for (ll i = 0; i < n; i++) {
        tree[n + i] = a[i];
    }
    for (ll i = n - 1; i >= 1; i--) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
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
        build(a, n);
        //q = 2 ; 
        while (q--)
        {
            ll c;
            cin >> c;
            if (c == 1)
            {
                ll j, v;
                cin >> j;
                if (a[j] == 0)
                {
                    v = 1;
                }
                else
                {
                    v = 0;
                }
                update(j, v, n);
                a[j] = v ;
            }
            else
            {
                ll k ;
                cin >> k ;
                k ++ ; 
                cout << query(1 , 0 , n-1 , k) << endl ; 
            }
        }
    }
    return 0;
}
