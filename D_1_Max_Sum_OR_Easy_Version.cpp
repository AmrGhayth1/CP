#include <bits/stdc++.h>
using namespace std;
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
    while (t--)
    {
        ll l, n;
        cin >> l >> n;
        vector<ll> ans(n + 1, -1);
        ll limite = log2(n);

        auto NOT = [&](ll x)
        {
            ll res = 0;
            for (ll i = 0; i <= limite; i++)
            {
                if ((x & (1LL << i)) == 0)
                {
                    res += (1LL << i);
                }
            }
            return res;
        };
        auto dec = [&](ll x)
        {
            for (ll i = limite ; i >= 0 ; i -- )
            {
                if (x & (1LL << i))
                {
                    x -= (1LL << i);
                    break;
                }
            }
            return x;
        };
        vector<ll> used(n + 1, 0);
        for (ll i = n; i >= l ; i--)
        {
            if (used[i])
                continue;

            ll tg = NOT(i);
            if (tg <= n  && ans[tg] == -1){
                ans[tg] = i;
                ans[i] = tg ; 
                used[i] = true ; 
                used[tg] = true ; 
            }else{
            while (tg >= l && ( tg > n || ans[tg] != -1 ))
            {
                tg = dec(tg);
            }
            if( tg >= l && tg <= n && ans[tg] == -1){
                ans[tg] = i;
                ans[i] = tg ; 
                used[i] = true ; 
                used[tg] = true ; 
            }
        }
        }
        ll sum = 0 ; 
        for(ll i = l ; i <= n ; i ++){
            sum += (ans[i] | i) ; 
        }
        cout << sum << endl; 
        for(ll y : ans )cout << y << ' ' ;
        cout << endl ;
    }
    return 0;
}
