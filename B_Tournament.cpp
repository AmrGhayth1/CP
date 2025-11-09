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
        ll n , j , k ; 
        cin >> n >> j >> k ; 
        ll a[n] ; 
        for(ll &y : a)cin >> y ; 
        ll tg = a[j-1] ;
        if(k == 1 && tg != *max_element(a,a+n) ){
            cout << "NO" << endl; 
        }else{
            cout << "YES" << endl ; 
        }
    }
    return 0;
}
