#include <bits/stdc++.h>
using namespace std;
#define HONDA ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long double ld;
typedef long long ll;
#define mpll  map<ll,ll>
#define vll vector<ll>
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define fit(c) for(auto it = c.begin(); it != c.end(); ++it)
#define endl "\n"
int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};
inline bool in(int i, int j, int rows, int cols){
    return i>=0 && i<rows && j>=0 && j<cols;
}
inline bool in(int i, int l, int h){
    return i >= l && i <= h;
}
ll m;
void dfs(vector<vector<ll>> &adj, vector<ll> &par, ll node,ll parent){
    for(ll child:adj[node]){
        if(child == parent) continue;
        if(node < m){
            par[child] = node;
        }
        else{
            par[child] = par[node];
        }
        dfs(adj,par,child,node);
    }
}
using namespace std;
int main() {
    HONDA
    freopen("tree.in", "r", stdin);
    int t = 1;
    cin >> t;
    while(t--){
        ll n;cin>>n;
        cin>>m;
        vector<vector<ll>> adja(n);
        fi(0,n-1){
            ll x,y;cin>>x>>y;
            x--;y--;
            adja[x].push_back(y);
            adja[y].push_back(x);
        }
        vector<ll> para(n,-1);
        para[0]=-1;
        dfs(adja,para,0,-1);
        vector<vector<ll>> adjb(m);
        fi(0,m-1){
            ll x,y;cin>>x>>y;
            x--;y--;
            adjb[x].push_back(y);
            adjb[y].push_back(x);
        }
        vector<ll> parb(m, -1);
        parb[0]=-1;
        dfs(adjb, parb, 0,-1);
        bool ok = 1;
        fi(0,m){
            if(para[i]!=parb[i]) ok=0;
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
  return 0;
}
