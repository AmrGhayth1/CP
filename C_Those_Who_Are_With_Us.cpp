#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;

int main()
{
    AMR
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll a[n][m];
        ll mx = -1e18;
        
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                cin >> a[i][j];
                mx = max(mx, a[i][j]);
            }
        }

        ll freq = 0;
        vector<ll> r(n+1,0) ; 
        vector<ll> c(m+1,0) ; 
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                if (a[i][j] == mx){
                    r[i] ++ ; 
                    c[j] ++ ; 
                    freq ++ ; 
                }
            }
        }
        ll cnt = 0 ;
        bool T = 1 ; 
         for (ll i = 0; i < n && T ; i++) {
            for (ll j = 0; j < m && T ; j++) {
               cnt = c[j] + r[i] ; 
               if(a[i][j] == mx)cnt -- ; 
               if(cnt == freq )T = 0 ; 
            }
        }
        if ( cnt >= freq ){
            cout << mx -1 << endl  ; 
        }else{
            cout << mx << endl ;
        }
    }
    return 0;
}
