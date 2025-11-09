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
   cin >> t;
    while (t--)
    {
        string l , r ; 
        cin >> l >> r ; 
        ll ans = 0 , x = 0 ; 
            for(ll i = 0 ; i < r.size() ; i ++){
                if(l[i] == r[i]+x ){
                    x = 0 ; 
                    ans += 2 ; 
                }
                else if(l[i]+1 == r[i]+x ){
                    ans += 1 ; 
                    x = 10 ; 
                }else{
                    break ; 
                }
            }
            cout << ans << endl ;

    }
    return 0;
}
