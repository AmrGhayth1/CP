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
    next :
    while (t--)
    {
        ll n ; 
        cin >> n ; 
        ll a , b ; 
        cin >> a >> b ; 
        ll x , y ; 
        cin >> x >> y ; 
        x ++ ; y ++ ; a ++ ; b ++ ; n ++ ; 
        ll r = a < x ? (x-1) : (n - x) ;
        if(a == x )r = 0 ;  
        ll c = b < y ? (y-1) : (n - y) ;
        if(b == y)c = 0 ; 
        cout << max(r , c )<< endl ; 
    }
    return 0;
}
