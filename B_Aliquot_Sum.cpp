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
 
ll sum_of_divisors(ll n) {
    ll sum = 0;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0){
            sum += i;
            //cout << i << ' ' ;
            if (i != n / i) sum += n / i; 
        }
    }
    return sum;
}

int main()
{
    sieve() ; 
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
        ll n ; 
        cin >> n ; 
        ll ss = sum_of_divisors(n) - n ; 
        if(ss > n){
            cout << "abundant\n" ;
        }else if(ss < n){
            cout << "deficient\n" ;
        }else{
            cout << "perfect\n" ;
        }
        //cout << ss << ' '<< n << endl ; 
    }
    return 0;
}
