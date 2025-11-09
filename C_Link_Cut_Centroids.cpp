#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;

       vector<ll> mx(100005,-1)  ;


void dfs(ll u, ll p , vector<ll> tree[] , ll subtree_size[] , ll & centroid  , ll & best , ll & centroid2 , ll & n ) {
    subtree_size[u] = 1;
    ll max_part = 0;

    for (ll v : tree[u]) {
        if (v != p){
        dfs(v, u , tree , subtree_size , centroid , best , centroid2  , n );
        subtree_size[u] += subtree_size[v];
        if( subtree_size[v] > max_part ){
            mx[u] = v ; 
        }
        max_part = max(max_part, subtree_size[v]);
    }
}

    max_part = max(max_part, n - subtree_size[u]); 

    if (max_part < best) {
        best = max_part;
        centroid = u;
        centroid2 = -1 ; 
    }else if ( max_part == best ){
        centroid2 = u ; 
    }
    
}


int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
        ll n ; 
        cin >> n ; 
        vector<ll> tree[n+1] ;
        ll sub[n+1];

        
         ll centroid = -1;
         ll best = n , centroid2 = -1 ; 

         ll x , y ; 
        for(ll i = 0 ; i < n-1 ; i ++){
            cin >> x >> y ; 
            tree[x].push_back(y) ; 
            tree[y].push_back(x) ; 
        }
        dfs(1 , 0 , tree , sub , centroid , best , centroid2 , n ) ;
        if(centroid == -1 || centroid2 == -1 ){
            cout << x << ' '<< y << endl ; 
            cout << x << ' '<< y << endl ; 
            continue ; 
        } 

        cout << centroid << ' '<< mx[centroid] << endl; 
        cout << centroid2 << ' '<< mx[centroid] << endl ;
    }
    return 0;
}
