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
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
typedef unsigned __int128 bll;
const ll MOD = 1e9 + 7;
ll n , m ; 
string a[51] ; 
bool can(ll i , ll j){
    return(i > 0 && j >= 0 && i <= n && j < m && a[i][j] == '*') ; 
}

int main()
{
    // بسم الله
    AMR
        ll t = 1;
    cin >> t;
    while (t--)
    {
        cin >> n >> m ; 

        for(ll i = 1 ; i <= n ; i++){
            cin >> a[i] ; 
        }
        ll ans = 0 ; 
        ll cnt = 0 ; 
           for(ll i = 1 ; i <= n ; i++){
            for(ll j = 0 ; j < m ; j ++){
                if(a[i][j] == '*')cnt ++ ; 
              if(
                ! can(i -2, j -1 ) &&! can(i -2, j ) &&! can(i -2, j +1 ) &&! can(i -2, j +2 )  &&
                ! can(i-1 , j -1 ) && can(i -1, j )  && can(i -1, j +1 )  &&! can(i -1, j +2 ) &&
                 ! can(i , j -1 )  && can(i , j )    &&! can(i , j +1 )   &&! can(i , j +2 )  &&
                 ! can(i +1, j -1 )&&! can(i +1, j ) &&! can(i +1, j +1 )  
              )ans ++ ; 
                if(
                                     ! can(i -2, j ) &&! can(i -2, j +1 )  &&! can(i -2, j +2 )  &&
                ! can(i-1 , j -1 ) &&! can(i -1, j ) && can(i -1, j +1 )   &&! can(i -1, j +2 ) &&
                 ! can(i , j -1 )  && can(i , j )    && can(i , j +1 )     &&! can(i , j +2 )  &&
                 ! can(i +1, j -1 )&&! can(i +1, j ) &&! can(i +1, j +1 )  &&! can(i +1, j +2 )  
              )ans ++ ; 

               if(
                ! can(i -2, j -1 )  &&! can(i -2, j ) &&! can(i -2, j +1 ) &&
                ! can(i-1 , j -1 )  && can(i -1, j )  &&! can(i -1, j +1 ) &&! can(i -1, j +2 ) &&
                 ! can(i , j -1 )   && can(i , j )    && can(i , j +1 )    &&! can(i , j +2 )  &&
                 ! can(i +1, j -1 ) &&! can(i +1, j ) &&! can(i +1, j +1 ) &&! can(i +1, j +2 )  
              )ans ++ ; 
              if(
                ! can(i -2, j -1 )  &&! can(i -2, j ) &&! can(i -2, j +1 ) &&! can(i -2, j +2 )  &&
                ! can(i-1 , j -1 )  && can(i -1, j )  && can(i -1, j +1 ) &&! can(i -1, j +2 ) &&
                 ! can(i , j -1 )   &&! can(i , j )   && can(i , j +1 )   &&! can(i , j +2 )  &&
                                      ! can(i +1, j ) &&! can(i +1, j +1 ) &&! can(i +1, j +2 )  
              )ans ++ ; 
            }
        }
        bool T = 0 ;
        if(cnt % 3 == 0 && ans == cnt/3)T = 1 ; 
        cout << (T ? "YES" : "NO") << endl ;
      //  cout << cnt << ' '<< ans << endl ; 
    }
    return 0;
}
