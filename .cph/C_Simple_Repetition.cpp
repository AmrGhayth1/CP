#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
#define endl "\n"

bool T( ll  n) {
    if (n <= 1) return 0; 
    if (n == 2) return 1;   
    if (n % 2 == 0) return 0; 

    for ( ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }

    return 1;
}

int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {        
        ll x , y ;
        cin >> x >> y ; 
        bool ans = 0 ; 
        if(x == 1  && y == 2){
            ans = 1 ; 
        }
        if(y == 1 ){
            ans = T(x) ; 
        }
        if(ans){
            cout << "YES" << endl ; 
        }else{
            cout << "NO" << endl ;
        }
    }
    return 0;
}
