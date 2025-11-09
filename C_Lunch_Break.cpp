#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
typedef unsigned __int128 bll;

int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
        ll a , b , c ; 
        cin >> a >> b >> c ; 
        if(a < b && a < c )cout << "First" << endl ;
        else if( b < a && b < c) cout << "Second" << endl ; 
        else cout << "Third" << endl;  
    }
    return 0;
}
