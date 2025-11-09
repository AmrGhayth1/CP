#include <bits/stdc++.h>
using namespace std;
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
        ll n , k ; 
        cin >> n >> k  ;
        string s ; 
        cin >> s ;
        ll ans = 0 ;
        ll lst = -1e18 ;  
        for(ll i = 0 ; i < n ; i ++){
            if(s[i] == '1'){
                if((i - lst ) > k-1 )ans  ++ ; 
               // cout << i << ' '<< lst << endl ;
                lst = i ; 
            }
        }
        cout << ans << endl; 

    }
    return 0;
}
