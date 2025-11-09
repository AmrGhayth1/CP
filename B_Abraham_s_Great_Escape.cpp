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
next:
    while (t--)
    {
        ll n, k;
        cin >> n >> k; 
        if ( n*n - k == 1  )
        {
            cout << "NO" << endl;
            goto next;
        }
        else
        {
            cout << "YES" << endl;
        }
       vector<vector<char>> s(n , vector<char>(n,'D')) ;
       k = n*n - k ; 
       for(ll i = 0 ; i < n ; i ++){
        for(ll j = 0 ; j <n ; j ++){
            if(!(i == 0 && j == 0 )){
                if( j == 1 && i == 0 ){
                    k -= 2 ; 
                }else{
                    k -- ; 
                }
                if(i == 0 ){
                    s[j][i] = 'U' ;
                }else{
                    s[j][i] = 'L' ; 
                }
            }
            if(k == 0){
                goto A ; 
            }
        }
       }
       A :
       for(auto c : s){
        for(auto x : c){
            cout << x ; 
        }
        cout << endl; 
       }
    }
    return 0;
}
