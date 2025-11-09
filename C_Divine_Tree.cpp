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
        ll n , m ; 
        cin >> n >> m ; 
        ll gs = (n*(n+1))/2 ; 
        if(gs < m  || n > m ){
            cout << -1 << endl; 
            continue ; 
        }
        vector <pair<ll,ll>> v ;
        map<ll,bool> u ; 
        ll c = gs-m ; 
        for(ll i = n ; i >= 1 ; i --){
            if(i != 1 && i-1 <= c ){
                c -= (i-1)  ; 
                v.push_back({1 , i } ) ; 
                u[i] = 1 ; 
            }
        }
        ll r = 1 ; 
        for(ll i = n ; i >= 1 ; i --){
            if(u[i] == 0 ){
                r = i ; 
                break ; 
            }
        }
        cout << r << endl ; 
        vector<ll> nu ; 
         for(ll i = n ; i >= 1 ; i --){
            if(u[i] == 0 ){
                nu.push_back(i) ; 
            }
        }
         for(ll i = 0 ; i < nu.size()-1 ; i ++){
            cout << nu[i] << ' '<< nu[i+1] << endl ;
        }

        for(pair<ll,ll> p : v ){
            cout << p.first << ' '<< p.second << endl ; 
        }
        
    }
    return 0;
}
