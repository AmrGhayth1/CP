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

vector<ll> vis(1e5 + 5, 0);
vector <ll> c(1e5 + 5 , 0 );
vector<bool> cyc(1e5 +5 , 0 );


void dfs(ll v, vector<ll>& to, vector<ll> &topo , vector<ll>& mnc )
{
    vis[v] = 1;
    ll ch = to[v];
    if (vis[ch] == 0)
    {
        dfs(ch, to, topo , mnc);
    }
    else if (vis[ch] == 1)
    {
        ll mn = c[ch];
        ll m = ch;
            cyc[ch] = 1 ; 
        while (ch != v)
        {
            
            ch = to[ch];
             cyc[ch] = 1 ; 
            if (mn > c[ch])
            {
                mn = c[ch];
                m = ch;
            }
        }
        mnc.push_back(m) ; 
    }
    topo.push_back(v);
    vis[v] = 2;
}
int main()
{
    AMR
        ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> to(n + 1, -1);
        for (ll i = 1; i <= n; i++)
        {
            ll y;
            cin >> y;
            to[i] = y;
        }
         for (ll i = 1; i <= n; i++)
        {
            vis[i] = 0;
            c[i] = 0 ; 
            cyc[i] = 0 ;
        }
        vector<ll> topo;
        for (ll i = 1; i <= n; i++)
        {
            ll x;
            cin >> x;
            c[i] = x;
        }
         vector<ll> mnc ;  
        for (ll i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                dfs(i, to, topo , mnc );
            }
        }
        reverse(all(topo));
        for (ll y : topo)
        {
            if (cyc[y] == 0)
            {
                cout << y << ' ';
            }
        }
        for(ll x : mnc){
            ll ch = to[x] ; 
            while(ch != x){
                cout << ch << ' ' ;
                ch = to[ch] ; 
            } 
            cout << x << ' ' ; 
        }
        cout << endl;
    }
    return 0;
}
