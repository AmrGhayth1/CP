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
 
        ld x , y ; 
        cin >> x >> y ; 
        ld ans = atan2(y , x) ; 
        if(0 > ans)ans += 2 * 3.141592654  ; 
        cout << fixed << setprecision(5) << ans ; 
    
    return 0;
}
