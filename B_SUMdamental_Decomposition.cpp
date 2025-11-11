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
vector<ll> tob(ll n)
{
    vector<ll> ans;
    while (n)
    {
        if (n % 2 == 0)
            ans.push_back(0);
        else
            ans.push_back(1);
        n /= 2;
    }
    ll g = 32 - ans.size() ;
    if (g <  0 )g = 0 ;  
    while(g--){ 
        ans.push_back(0);
    }

    return ans;
}
int main()
{
    AMR
        ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        vector<ll> a;
        a = tob(x);
        ll ss = n - __popcount(x);
        if (ss < 0)
            ss = 0;
        ll ans = 0;
        fi(0, a.size())
        {
            ll cr = n;
            if (a[i] == 1)
            {
                ans += (1LL << i);
                cr--;
            }
            ll pairs ; 
            if(ss < cr ){
         pairs = (min(ss, cr) +1)/ 2;
            }else{
         pairs = (min(ss, cr) )/ 2;
            }
            ans += (1LL << i) * 2 * pairs;
            ss -= 2 * pairs;
            cr -= 2 * pairs;
            
              //cout << ss << ' '<< cr << ' ' <<  ans << endl ;
        }
        if (ss > 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
}
