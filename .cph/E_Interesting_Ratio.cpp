#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
typedef unsigned __int128 bll;

const ll N = 1e7 + 1 ; 
vector<bool> is_prime(N, true);
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i < N; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
int main()
{
   
    AMR
    ll t = 1 ;
   cin >> t; 
   sieve() ;
    while (t--)
    {
        ll n ; 
        cin >> n ; 
        ll ans = 0 ; 
      fi(1,n+1){
        if(is_prime[i]){
            ll x = n / i ; 
            ans += x ; 
        }
      }
      cout << ans << endl ;
    }
    return 0;
}
