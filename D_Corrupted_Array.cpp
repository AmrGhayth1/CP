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
        ll a[n+2] ; 
        for(ll & y : a)cin >> y ; 
        sort(a , a + n+2) ;
        ll tg1 , tg2 ;
        tg1 = a[n+1] ; 
        tg2 = a[n] ; 
        ll tt = 0 ; 
        for(ll i = 0 ; i < n ;i ++){
            tt += a[i] ; 
        }
        if(tt == tg1 || tt == tg2 ){
            for(ll i = 0 ; i < n ; i ++){
                cout << a[i] << ' ';
            }
            cout << endl ;
            continue; 
        }
        //cout << tt << ' '<< tg1 << ' '<< tg2 << endl ;
        ll x = tg1 - tt ; 
        if(!binary_search(a , a+n , tg2 - x )){
            cout << -1 << endl ; 
        }else{
            bool us = 1 ; 
           for(ll i = 0 ; i < n ;i ++){
                if(us && a[i] == (tg2 -x ) ){
                    cout << tg2 << ' ';
                    us = 0 ;  
                }else{
                    cout << a[i] << ' ';
                }
            }
            cout << endl ;
        }
        
    }
    return 0;
}
