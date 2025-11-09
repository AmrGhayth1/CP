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
        ll n , k ; 
        cin >> n >> k ; 
        string s; 
        cin >> s ; 
        ll cnt1 = 0 ; 
        for(ll i = 0 ;i < n ; i ++){
            if(s[i] == '1')cnt1 ++ ;
        }
        ll x = cnt1 - k ; 
        x = max(x , 0LL ) ;
        if( x == 0 || k*2 > n  ){
            cout << "Alice" << endl ;
        }else{
            cout << "Bob" << endl ;
        }
    }
    return 0;
}