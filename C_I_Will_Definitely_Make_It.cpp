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
int main()
{
    AMR
        ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> v;
        ll a[n];
        for (ll &y : a)
            cin >> y;
        ll x = a[k - 1];
        map<ll, ll> us;
        for (ll i = 0; i < n; i++)
        {
            if (us[a[i]] == 0 && a[i] > x)
            {
                v.push_back(a[i]);
                us[a[i]] = 1;
            }
        }
        v.push_back(x);
        sort(all(v));
        bool ans = 1;
        x = 0 ; 
        for (ll i = 1; i < v.size(); i++)
        {
             //    cout << x +(v[i] - v[i - 1])  << ' '<< v[i-1] << endl ; 

            if (v[i-1] < x +(v[i] - v[i - 1])  ){
                ans = 0;
                break;
            }
                x += v[i] - v[i - 1] ; 
        }
        if (ans)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
