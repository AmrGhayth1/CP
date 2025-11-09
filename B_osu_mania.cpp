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
    while (t--)
    { 
        ll n ; 
        cin >> n ; 
        vector<ll> ans ;  
        for(ll i = 0 ; i < n  ; i  ++ ){
            string s ; 
            cin >> s ; 
            for(ll j = 0 ; j < 4 ; j ++){
                if(s[j] == '#'){
                    ans.push_back(j+1) ; 
                }
            }
        }

        for(ll i = ans.size() -1  ; i >=0  ; i --)cout << ans[i] << ' ';

        cout << endl; 
    }
    return 0;
}
