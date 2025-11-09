#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
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
        string s ; 
        cin >> s ; 
        ll n = s.size() ; 
        sort(all(s)) ;
        map<char , ll> m ; 
        fi(0,n)m[s[i]] ++ ;  
        string ss ; 
        for( char i = '9' ; i >= '0' ; i --){
            char x = i ; 
            while(m[x] == 0 ){
            x ++ ; 
            }
            m[x] -- ; 
            ss.push_back(x) ; 
        }
        cout << ss << endl ; 
    }
    return 0;
}
