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
        ll n = 8, m = 8;
        vector<string> a(n);
        for (ll i = 0 ; i < 8 ; i ++){
            cin >> a[i] ; 
        }
        bool r = 0;
        for (ll i = 0; i < n; i++)
        {
            r = 1;
            for (ll j = 0; j < m; j++)
            {
                if (a[i][j] != 'R' )
                    r = 0;
            }
            if (r)
            {
                break; 
            }
        }
        if (r)
        {
            cout << "R" << endl;
        }
        else
        {
            cout << "B" << endl;
        }
    }
    return 0;
}
