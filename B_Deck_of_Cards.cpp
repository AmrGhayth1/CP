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
        ll n , k  ; 
        cin >> n >> k ; 
        string s; 
        cin >> s ; 
        vector<char> a(n,'+') ;
        ll l = 0 , r = n-1 ;
        ll shf =0;
        for(auto c : s){
            if(c == '0'){
                a[l] = '-';
                l ++ ; 
            }else if(c == '1'){
                a[r] = '-' ; 
                r -- ; 
            }else{
                shf  ++ ;
            }
        }
        r  ++ ; 
        l -- ; 

       // cout << r << ' '<< l << ' '<<  shf << endl; 
     for(ll i = 0 ; i < n ; i ++ ){
        if(a[i] == '+'){
            if((r - i)  + (i - l)  <= shf+1 ){
                a[i] = '-' ; 
            }else if((r - i)  <= shf  || (i - l)  <= shf  ){
                a[i] = '?' ; 
            }
           // cout << i << ' '<< r << ' ' << l << endl; 
        }
     }
        for(char c : a )cout << c ; 

        cout << endl; 
    }
    return 0;
}
