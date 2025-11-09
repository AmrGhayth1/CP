#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
//typedef unsigned int128 bll;

bool is(vector<ll> a , ll n , ll x , ll m ){
    ll mn = 0; 
    for(ll i = 0 ; i < n ; i++){
        ll z = (a[i] + x) % m;
        if(a[i] + x < mn && a[i] < mn )return 0 ; 
        ll mm = max(a[i] , mn ) ; 
        ll mm2 = min(z , mn ) ;
        mn = max(mm , mm2 ) ;  
     
    }
    return 1;
}

int main()
{
    AMR
    ll t = 1 ;
    // cin >> t;
    while (t--)
    {
        ll n , m ; 
        cin >> n >> m ; 
        vector<ll> a(n);
        for(ll i = 0 ; i < n ; i++) cin >> a[i]; 

        ll l = 0 , r = m , ans = m; 
        while(l <= r){
            ll md = (l + r) / 2 ; 
            if(is(a , n , md , m )){
                ans = md ; 
                r = md - 1 ; 
            }else{
                l = md + 1 ; 
            }
        }
        cout << ans << endl; 
    }
    return 0;
}