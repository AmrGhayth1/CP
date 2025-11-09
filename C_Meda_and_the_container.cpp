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

const ll MOD = 1e9 + 7;
const ll N = 1e7 + 10; 

long long fct[N], invfct[N];

long long modPow(long long a, long long b, ll mod) {
    long long res = 1;
    while(b > 0) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void factorials() {
    fct[0] = 1;
    for(ll i = 1; i < N; i++)
    fct[i] = (fct[i - 1] * i) % MOD;

        invfct[N - 1] = modPow(fct[N - 1], MOD - 2, MOD);
    for(ll i = N - 2; i >= 0; i--)
    invfct[i] = (invfct[i + 1] * (i + 1)) % MOD;
}

int main()
{
    factorials() ;
    AMR
    ll t = 1 ;
   //cin >> t;
    while (t--)
    {
        ll n , k ; 
        cin >> n >> k ; 
        n ++ ; 
        ll a[n] ; 
        ll sm = 0 ; 
        for(ll i = 1 ; i < n ; i ++ ){
         ll x = i%MOD  ; 
            x = (x * (fct[n]%MOD) )%MOD ; 
            x = (x * (invfct[i+1]%MOD) )%MOD ; 
            x = (x * (invfct[n-i-1]%MOD) )%MOD ; 
            sm =( (sm%MOD)  + (x%MOD))%MOD ;
            a[i] = sm ;   
        }
        for(ll i = 0 ; i < k ; i ++){
            ll z ; cin >> z ; 
            cout << a[z] << ' ';
        }
    }
    return 0;
}
