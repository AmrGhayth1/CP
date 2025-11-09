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
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;
const ll MOD = 1e9 + 7;

int main()
{
    // بسم الله
    AMR
        ll t = 1;
    cin >> t;
next:
    while (t--)
    {
        ll n, m, l, r;
        cin >> n >> m >> l >> r;
        vector<ll> a(n);
        for (ll &y : a)
            cin >> y;
        auto fn = [&](ll k, ll mx)
        {
            if(k <= 0 || mx <= 0 )return 0LL ; 
            map<ll, ll> fq;
            ll dist = 0;
            ll ans = 0;
            ll L = 0;
            for (ll R = 0; R < n; R++)
            {
                fq[a[R]]++;
                if (fq[a[R]] == 1)
                    dist++;
                while (dist > k)
                {
                    fq[a[L]]--;
                    if (fq[a[L]] == 0)
                        dist--;
                    L++;
                }
                ll rng = R - L + 1;
                if(rng > mx )L = R - mx +1 ; 
                ans += R - L +1 ; 
            }
            return ans ; 
        } ;

        cout << (fn(m , r) - fn(m , l-1)) - (fn(m-1 , r )-fn(m-1 , l -1 )) << endl ;  
    }
    return 0;
}