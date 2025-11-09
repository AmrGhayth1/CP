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
        ll n , s ; 
        cin >> n >> s ; 
        ll a[n] ; 
       for(ll i = 0; i < n; i++) cin >> a[i];   
        ll mx = *max_element(a , a+n) ; 
        ll mn = *min_element(a , a+n) ; 
        ll ans = min( abs(mx -s) , abs(s - mn) ) ;
        if((s != mn || s != mx  )&& n != 1 )ans += (abs(mx - mn)  ) ;  
        cout << ans << endl ;
    }
    return 0;
}
