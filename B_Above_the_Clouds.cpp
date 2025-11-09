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
    ll  n;
    string s;
    cin >> n >> s;
    
    bool ans = 0 ; 
    map<char , ll> m ; 
    m[s[0]] ++ ; 
    m[s[n-1]] ++ ; 
    for (ll i = 1 ; i < n-1 ; ++i) {
        m[s[i]] ++ ; 
        if(m[s[i]] >=  2  )ans = 1 ; 
    
    }

    if (ans ) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    }
    return 0;
}
