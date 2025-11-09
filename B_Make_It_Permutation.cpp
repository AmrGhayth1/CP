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
        ll n ; 
        cin >> n ; 
        ll l = 2  ; 
        vector<pair<ll,pair<ll ,ll >>> s ; 
        for(ll i = 1 ; i <= n ; i ++){
            if(i != 1 ){ 
                s.push_back({i , {1 , i}} ) ;
            }
            if(i < n-1 ){
                s.push_back({i , {i+1 , n}} ) ;
            }
        }
        cout << s.size() << endl ; 
        for(ll i = 0 ; i < s.size() ; i ++){
            cout << s[i].first  << ' '<< s[i].second.first << ' '<< s[i].second.second << endl ;
        }
    }
    return 0;
}