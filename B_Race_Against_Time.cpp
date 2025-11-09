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
        ll h , m , s , t1 , t2 ; 
        cin >> h >> m >> s >> t1 >> t2 ;
        h = (h%12 + (m/60)%12 + (s/3600)%12 )%12 ; 
        m =( m%60  + ( s / 60 )%60  ) %60 ;
        ld l1 = h ; 
        ld l2 = (m/60) ; 
        ld l3 = (s/60) ;   
        bool ans = 0 ; 
        if(( h > t1 && h < t2) && (m > t1m && m < t2m ) && (s > t1s && s <t2s ) )ans = 1 ; 
        if(( h < t1 && h > t2) && (m < t1m && m > t2m ) && (s < t1s && s > t2s ) )ans = 1 ; 


        if(ans)
        cout << "YES" ; 
        else 
        cout << "NO" ;
    }
    return 0;
}
