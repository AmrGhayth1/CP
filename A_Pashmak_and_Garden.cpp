#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int main()
{
    AMR
   ll x , y , a , b ;
   cin >> x >> y >> a >> b ;
   if(x == a && y != b){
    ll l = b - y ;
    cout << x+l <<' '<< y << ' '<< a+l <<' '<<b ; 
   }else if(b == y && x != a){
    ll l = a - x ;
    cout << x <<' '<< y+l << ' '<< a <<' '<< b+l ; 
   }else if(abs(a - x) == abs(b - y)){
    cout << x <<' '<< b << ' '<< a <<' '<< y ; 
   }else{
    cout << -1 ;
   }
    return 0;
}
