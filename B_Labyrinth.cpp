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
    //cin >> t;
    next :
    while (t--)
    {
        ll n ,m ; 
        cin >> n >> m ; 
        ll r , c ; 
        cin >> r >> c ; 
        r -- ; c -- ; 
        ll x , y ; 
        cin >> x >> y ;
        string s[n] ; 
        for(auto& e : s)cin >> e ;    
        deque< pair<pair<ll,ll>,pair<ll,ll>>> q ;  
        vector<vector<bool>> vs(n+1 , vector<bool>(m, 0));
        auto can =[&](ll x , ll y){
            return (x >= 0 && y >= 0 && x < n && y < m && s[x][y] != '*' && vs[x][y] == 0 ) ; 
        };
        q.push_front({{r,c},{x,y}}) ; 
        vs[r][c] = 1 ; 
        while(!q.empty()){
            ll i = q.front().first.first ; 
            ll j = q.front().first.second;
            ll l = q.front().second.first;
            ll r = q.front().second.second;
            q.pop_front();
            for(ll k = 0 ; k < 4 ; k ++){
                ll nr = r ; 
                ll nl = l ; 
                ll nx = i + dx[k] ; 
                ll ny = j + dy[k] ; 
                if(dy[k] == 1 )nr -- ; 
                if(dy[k] == -1)nl -- ; 
                if(can(nx , ny) && nr >= 0 && nl >= 0 ){
                    if(dy[k] == 0 ){
                    q.push_front({{nx ,ny} , {nl , nr}}) ; 
                   
                    }else{
                        q.push_back({{nx ,ny} , {nl , nr}}) ; 
                    }
                     vs[nx][ny] = 1 ;
                }
            }
        }
        ll ans = 0; 
        for(ll i = 0 ;  i < n ; i ++){
            for(ll j = 0  ; j < m ; j ++ ){
                if(vs[i][j])ans ++ ; 
            }
        }
        cout << ans ;
    }
    return 0;
}
