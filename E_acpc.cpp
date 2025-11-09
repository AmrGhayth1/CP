#include <bits/stdc++.h> 
using namespace std;
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
        ll n , m ; 
        cin >> n >> m ; 
        char a[n][m] ; 
        ll l = 0 , w = 0 ; 
        for(ll i = 0 ; i < n ; i++){
            for(ll j = 0 ; j < m ; j ++){
                cin >> a[i][j] ;
                if(a[i][j] == '|')l ++ ; 
                if(a[i][j] == '-')w ++ ; 
            }
        }
        l /= 2 ; 
        w /= 2 ; 
        cout << l*w ; 
    }
    return 0;
}
