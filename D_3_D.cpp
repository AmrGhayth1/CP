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
int main()
{
    AMR
    ll t = 1 ;
   //cin >> t;
    while (t--)
    {
        ll n ;
        cin >> n ; 
        ll a[n][3] ;
        map<ll,ll> x , y , z ; 
        for(ll i = 0 ; i < n ; i ++){
            for( ll j = 0 ; j < 3 ; j ++){
                cin >> a[i][j] ; 
                if(j == 0)x[a[i][j]] ++ ;
                if(j == 1)y[a[i][j]] ++ ;
                if(j == 2)z[a[i][j]] ++ ;
            }
        }
        for(ll i = 0 ; i < n ; i ++){
            cout << x[a[i][0]] -1 << ' '<< y[a[i][1]] -1 << ' '<< z[a[i][2]] -1 << endl ; 
        }
    }
    return 0;
}
