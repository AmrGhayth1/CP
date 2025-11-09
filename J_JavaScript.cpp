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
        string x , y ; 
        cin >> x >> y ; 
        bool T = 0 ; 
        for(char& z : x){
            if(z > '9' || z < '0')T = 1 ; 
        }
         for(char& z : y){
            if(z > '9' || z < '0')T = 1 ; 
        }
        if(T){
            cout << "NaN" ; 
        }else{
            ll a =  stoll(x) ; 
            ll b =  stoll(y) ;
            cout << a - b ;  
        }
    }
    return 0;
}
