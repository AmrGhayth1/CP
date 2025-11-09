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
   cin >> t;
    while (t--)
    {
        ll n ; 
        cin >> n ; 
        ll a[n] ; 
        ld p1 , p2 , q1 , q2 ; 
        cin >> p1 >> p2 >> q1 >> q2 ; 
        ld x =  sqrt((q1 - p1 )*(q1 - p1 )  + (q2 - p2 )*(q2 - p2 ) ) ; 
        ll sm = 0 , mx = 0 ; 
        for(ll & y : a){
            cin >> y ; 
            sm += y ; 
            mx = max(mx , y ) ; 
        }
        //cout << sm << ' '<< y << ' '<< x << endl ; 
        if(sm >= x &&  x >= (mx*2 - sm) ){
            cout << "Yes\n" ; 
        }else{
            cout << "No\n" ; 
        }
    }
    return 0;
}
