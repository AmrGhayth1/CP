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
ll np = 0 ; 
bool vd(ll x , ll y , ll n , ll m , vector<string>& g , vector<vector<bool>>& v ){
    if(x >= n || y >= m || y < 0 || x < 0 )return 0 ; 
    if(g[x][y] != '.' || v[x][y] == 1 )return 0 ; 
    return 1 ; 
}
void dfs(ll x , ll y  , vector<vector<bool>> & v , vector<string>& g , ll n , ll m , ll & cnt ){
        if(np > cnt) return;

        np ++ ; 
        
    v[x][y] = 1 ; 
    if(np > cnt) return;

    for(int i = 0 ; i < 4 ; i ++ ){
      ll  nx = x +  dx[i] ; 
      ll ny = y +  dy[i]  ; 
      if(vd( nx , ny , n , m ,  g , v )){
        dfs(nx , ny , v, g , n  , m , cnt ) ;  
      }
    }

}

int main()
{
    AMR
    ll t = 1 ;
   //cin >> t;
    while (t--)
    {
        ll n , m , k ; 
        cin >> n >> m >> k ; 
        vector<string> g(n) ;
       vector<vector<bool>> v(n , vector<bool>(m,0) ) ;

        for(string &x : g)cin >> x ; 

        ll cnt = 0 , x1 = -1 , y1 = -1 ; 
        for(ll i = 0 ; i < n ; i ++){
            for(ll j = 0 ; j < m ; j ++){
                if(g[i][j] == '.')cnt++ ; 
            }
        }
        cnt -= k ; 
        bool fn = 0 ; 
           for(ll i = 0 ; i < n ; i ++){
            for(ll j = 0 ; j < m ; j ++){
                if(g[i][j] == '.'){
                np = 1 ; 
                dfs( i , j , v , g , n , m , cnt ) ;
                if(np > cnt ){
                fn = 1 ;  
                break ; 
                }
            }
            }
            if(fn)break ; 
        }
          for(ll i = 0 ; i < n ; i ++){
            for(ll j = 0 ; j < m ; j ++){
                if( g[i][j] == '.' && v[i][j] == 0){
                    cout << 'X' ; 
                }else{
                cout << g[i][j] ;
            }
        }
            cout << endl ; 
        }
 
    }
    return 0;
}
