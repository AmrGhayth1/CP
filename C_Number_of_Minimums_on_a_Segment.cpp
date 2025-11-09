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

vector<ll> tree  ; 
map<ll,ll> m ; 
pair<ll,ll> query (ll nd , ll l , ll r , ll ql , ll qr ){
    if(ql <= l  && r <= qr ){
        return {tree[nd] , m[nd] } ; 
    }
    if( l > qr || r < ql ){
        return {1e9 , 0}  ; 
    }
    ll md = (l + r ) / 2 ;
    pair<ll,ll> a =   query( 2 * nd , l , md , ql , qr ) ; 
    pair<ll,ll> b =   query( 2 * nd +1 , md + 1 , r , ql , qr ) ; 
      if( a.first >  b.first  ){
                  return b ;  
            }else if( a.first < b.first  ){
                return  a  ;
            }else{
                return { a.first , (a.second + b.second) } ;
            }
}

void update(ll i , ll v , ll n ){
    tree[i+n] = v ; 
    for( ll j = (n+i)/ 2 ; j >= 1 ; j /= 2 ){
        tree[j] = min ( tree[j*2] , tree[j*2 + 1] )  ; 
            if(tree[j* 2 + 1 ] >  tree[j*2] ){
                m[j] = m[j*2] ; 
            }else if( tree[j* 2 + 1 ] < tree[j*2]){
                m[j] = m[j*2 +1] ; 
            }else{
                m[j] = m[j*2] + m[j*2 +1 ] ; 
            }
    }
}

void build( vector<ll>& a , ll& n ){
       while( __popcount(n) != 1 ){
            n ++ ; 
            a.push_back(1e9); 
        }
        tree.resize(2 * n ) ; 
        for( ll i = 0 ; i < n ; i++){
            tree[n+i] = a[i] ; 
            m[n+i] = 1 ; 
        }
        for( ll i = n-1 ; i >= 1; i -- ){
            tree[i] = min( tree[i*2] , tree[i*2 +1 ] ) ;  
            if(tree[i* 2 + 1 ] >  tree[i*2] ){
                m[i] = m[i*2] ; 
            }else if( tree[i* 2 + 1 ] < tree[i*2]){
                m[i] = m[i*2 +1] ; 
            }else{
                m[i] = m[i*2] + m[i*2 +1 ] ; 
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
        ll n , q ; 
        cin >> n >> q; 
        vector<ll> a(n) ; 
        for(ll & y : a)cin >> y ; 

        build( a , n ) ; 

        while(q -- ){
            ll c ; 
            cin >> c ; 
            if(c == 2 ){
            ll x , y ; 
            cin >> x >> y ;
            y -- ;  
            pair<ll,ll> ans = query(1 , 0 , n - 1 , x , y  ) ; 
            cout << ans.first << ' '<< ans.second  << endl ;  
        }else{
            ll i , v ; 
            cin >> i >> v ; 
            update(i , v , n) ; 
        }
    }
    }
    return 0;
}
