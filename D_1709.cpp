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

int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
        ll  n  ; 
        cin >> n  ;
        ll a[n] ; 
        ll b[n] ; 
        vector<pair<ll,ll> > p  ;
        for(ll &x : a)cin >> x ; 
        for(ll &x : b)cin >> x ;
        for(ll i = 0 ; i < n ; i ++ ){
            if(a[i] > b[i] ){
                swap(a[i] , b[i] ) ;
                p.push_back({3 , i+1,}) ; 
        } 
    }
        for(ll i = 0 ; i < n-1 ; i ++ ){
                  if( a[i] > a[i+1] ){ 
                    swap(a[i] , a[i+1] ) ;
                    p.push_back({ 1 , i+1 }) ;  
                    i = -1  ; 
            }
        }
           for(ll i = 0 ; i < n-1 ; i ++ ){
                if( b[i] > b[i+1] ){ 
                    swap(b[i] , b[i+1] ) ;
                    p.push_back({ 2 , i+1 }) ;  
                    i = -1  ; 
            }

            
        }
        cout << p.size() << endl ; 
        for(ll i = 0 ; i < p.size() ; i ++){
            cout << p[i].first << ' '<< p[i].second << endl ; 
        }
    }
    return 0;
}
