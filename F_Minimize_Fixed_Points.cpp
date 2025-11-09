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
   
    ll T;
    cin >> T;
    vector<ll> Ns(T);
    ll Nmax = 0;
    for(ll i = 0; i < T; i++){
        cin >> Ns[i];
        Nmax = max(Nmax, Ns[i]);
    }

    vector<bool> is_prime(Nmax+1, 1);
    is_prime[0] = is_prime[1] = 0 ;
    for(ll i = 2; i*i <= Nmax; i++){
        if(is_prime[i]){
            for(ll j = i*i; j <= Nmax; j += i)
                is_prime[j] = 0;
        }
    }
    vector<ll> primes;
    for(ll i = 2; i <= Nmax; i++)
        if(is_prime[i])
            primes.push_back(i);

    sort(primes.rbegin(), primes.rend());

    for(ll n : Ns){
        vector<ll> p(n+1, 0);
        vector<bool> used(n+1, 0);

        for(ll pr : primes){
            if (pr > n) continue;
            vector<ll> L;
            for(ll k = 1; pr * k <= n; k++){
                ll x = pr * k;
                if(!used[x])
                    L.push_back(x);
            }
            if(L.size() >= 2){
                for(ll i = 0; i + 1 < (ll)L.size(); i++){
                    p[L[i]] = L[i+1];
                    used[L[i]] = true;
                }
                p[L.back()] = L[0];
                used[L.back()] = true;
            }
        }

        for(ll i = 1; i <= n; i++){
            if(p[i] == 0)
                p[i] = i;
        }

        for(ll i = 1; i <= n; i++){
            cout << p[i] << ' ';
        }
        cout << endl ;
    }
    return 0;
}
