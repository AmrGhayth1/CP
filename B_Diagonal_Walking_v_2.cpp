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
        ll n , m , k ; 
        cin >> n >> m >> k ;  
        ll ans = 0 ; 
        ll d = abs(n-m) ; 
        if(d == 0){
            ll y = n-1 ; 
            if(y == 1 ){
                cout << 1 << endl ;
            }else{
                ll z = k - y ; 
                cout << y + z << endl ; 
            }
            continue;
        }
        ll x = k - d ;
        if(x >= min(n,m)){
            cout << x << endl ; 
        }else{
            cout << -1 << endl ;
        }
    }
    return 0;
}
