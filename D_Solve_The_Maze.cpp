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

bool vd(vector<string>& g , vector<vector<bool>>& v , ll n , ll m , ll x , ll y ){
    return( x >= 0 && y >=0 && x < n && y < m && g[x][y] != '#' && v[x][y] == 0 ) ; 
}
void dfs( vector<string>& g , vector<vector<bool>>& v , ll n , ll m , ll x , ll y , ll & cnt , bool & ans ){
    v[x][y] = 1 ; 
    if(g[x][y] == 'G')cnt ++ ;  
   if(x == n-1 && y == m-1)ans = 1 ;


    for( int i = 0  ;  i< 4 ; i++){
        ll nx = x+dx[i] ; 
        ll ny = y+dy[i] ; 
        if(vd( g , v ,  n , m , nx , ny ) ){
         dfs(g , v , n , m , nx , ny , cnt , ans ) ; 
        }
    } 
}

int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
        ll n , m ; 
        cin >> n >> m  ;
        vector<string> g(n) ; 
        bool ans = 1 ; 
        for(ll i= 0 ; i < n ; i ++)cin >> g[i];
        ll cnt1 = 0 ;  

        for(ll i = 0 ; i < n ; i ++){
            for(ll j = 0 ; j < m ; j++){
                if(g[i][j] == 'G')cnt1 ++ ;
                if(g[i][j] == 'B'){
                    if(i == n-1 && j == m-1 ){
                        ans = 0 ; 
                        break ; 
                    }
                    for( int k = 0 ; k < 4 ; k++ ){
                        ll nx = i+dx[k] ;
                        ll ny = j+dy[k] ; 
                        if(ny >= 0 && nx >= 0  && nx < n && ny < m){
                            if(g[nx][ny] == 'G' ){
                                ans  = 0 ; 
                                break  ;
                            }
                            if(g[nx][ny] != 'B' ){
                                g[nx][ny] = '#' ; 
                            }
                        }
                    }
                }
            }
        }
        if(!ans){
            cout << "No" << endl ;
            continue ; 
        }
        ll cnt = 0 ; 
        bool fn = 0 ; 
        bool r = 0 ; 
             for(ll i = 0 ; i < n ; i ++){
            for(ll j = 0 ; j < m ; j++){
                if(g[i][j] == 'G' ){
                    vector<vector<bool>> v(n , vector<bool>(m,0) ) ; 
              dfs(g , v , n , m , i , j , cnt  , r  ) ; 
             fn = 1 ; break ;  
                }
            }
            if(fn)break ; 
        }
        if((cnt == cnt1 && r )|| !fn){
            cout << "Yes" << endl ;
        }else{
            cout <<  "No" << endl ; 
        }
    }
    return 0;
}
