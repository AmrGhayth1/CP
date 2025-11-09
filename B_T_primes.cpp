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
     sieve() ; 
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
        ll n ; 
        cin >> n ;
        ll y = sqrt(n) ; 
        if(y*y == n && is_prime[y] ){
            cout << "YES" <<  endl ; 
        }else{
            cout << "NO" << endl ;  
        }
    }
    return 0;
}
