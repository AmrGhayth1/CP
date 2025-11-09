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

bool dfs(ll u, ll v, ll m, vector<ll> adj[])
{
    if(v == m )return 1 ; 
    for(ll ch : adj[v]){
        if(ch != v){
            return dfs(v , ch , m , adj ) ;
        }
    }
    return 0 ; 
}
int main()
{
    AMR
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> adj[n + 1];
        for (ll i = 0; i < n - 1; i++)
        {
            ll x;
            cin >> x;
            adj[i + 1].push_back(x + i + 1);
        }
        if (dfs(-1, 1, m, adj))
        {
            cout << "YES";
        }
        else
            cout << "NO";
    }
    return 0;
}
