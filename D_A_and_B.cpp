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
        string s ; 
        ll n ; 
        cin >> n ; 
        cin >> s;  
        vector<ll> va , vb ; 
        for(ll i = 0 ; i < n ; i ++){
            if(s[i] == 'a'){
                va.push_back(i) ; 
            }else{
                vb.push_back(i) ; 
            }
        }
        ll ind = va.size()/2  ; 
        ll mida = va.empty() ? 1e18 : va[ind]  ;
        ind = vb.size() ; 
        ll midb = vb.empty() ? 1e18 : vb[ind] ; 
        ll ans1 = 0 , ans2 = 0  ; 
        for(ll &i  : va){
            ans1 += abs(mida - i) ; 
        } 
        for(ll &i : vb){
            ans2 += abs(midb - i ) ; 
        }
        cout << min(ans1  - va.size() +1 , ans2 - vb.size() +1  ) << endl ; 
    }
    return 0;
}
