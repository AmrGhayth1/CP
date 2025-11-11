#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define endl "\n"
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
typedef unsigned __int128 bll;

const ll N = 1e7 + 1;
vector<bool> is_prime(N, true);
vector<ll> p;
void sieve()
{
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i < N; i++)
    {
        if (is_prime[i])
        {
            for (ll j = i * i; j < N; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    fi(0, 1e7)
    {
        if (is_prime[i])
        {
            p.push_back(i);
        }
    }
}
int main()
{
    AMR
    sieve();
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        fi(0, n) cin >> a[i];
        ll smp = 0 , sm = 0 ; 
        priority_queue<ll> prm ;
        priority_queue<ll> arr ;  
        fi(0, n)
        {
            smp += p[i] ; 
            sm += a[i] ; 
            prm.push(p[i]) ; 
            arr.push(-a[i]) ; 
        }
        ll cns = sm - smp ; 
        ll ans = 0 ; 
        while(cns < 0){
           // cout << prm.top() << ' '<< arr.top() << ' '<< cns << endl ;
            cns += prm.top() ;
            prm.pop() ; 
            cns += arr.top() ; 
            arr.pop() ; 
            ans ++ ;
        }
        cout << ans << endl;
    }
    return 0;
}
