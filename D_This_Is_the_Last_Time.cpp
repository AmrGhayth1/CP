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
struct Tri {
    ll first, second, third;
};
int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
         ll n , k ; cin >> n >> k ; 
         Tri a[n] ; 
         for(ll i = 0 ; i < n ; i ++)cin >> a[i].first >> a[i].second >> a[i].third ;

         sort(a , a+n , [&](Tri a, Tri b ){
           return a.third < b.third ; 
         }); 
         for(ll i = 0 ; i < n ; i ++){
            if(k >= a[i].first && k <= a[i].second && k < a[i].third )k = a[i].third ; 
         }
         cout << k << endl ; 
    }
    return 0;
}
