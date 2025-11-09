#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;
const ll MOD = 1e9 +7 ; 
const ll N = 1e7 + 1;
vector<ll> spf(N);
 
void sieve()
{
    for (ll i = 0; i < N; i++)
        spf[i] = i;
    for (ll i = 2; i * i < N; i++)
    {
        if (spf[i] == i)
        {
            for (ll j = i * i; j < N; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}
 
vector<ll> get_factors(ll x)
{
    vector<ll> factors;
    while (x != 1)
    {
        factors.push_back(spf[x]);
        x /= spf[x];
    }
    return factors;
}

int main()
{
    sieve() ; 

    // بسم الله 
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {  
        
    }
    return 0;
}
