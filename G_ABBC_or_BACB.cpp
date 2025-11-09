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
        string s ; 
        cin >> s ; 
        map<ll,ll> m ;
        vector<ll> v ;   
        ll cnt  = 0 ;
        ll cnt2 = 0 ; 
        for(ll i = 0 ; i < s.size() ; i ++ ){
             if(s[i] == 'A')cnt++ ; 
            if(cnt != 0 && (s[i] == 'B' || i == s.size()-1 )){
                v.push_back(cnt) ; 
                cnt = 0 ; 
            }
            if(s[i] == 'B')cnt2 ++ ; 
        }
        sort(all(v)) ; 
        reverse(all(v)) ; 
        ll ans = 0 ; 
        ll l = min(cnt2 , (ll)(v.size())  ) ; 

        for(ll i = 0 ; i < l  ; i ++){
            ans += v[i] ; 
        }
        cout << ans << endl ;
    }
    return 0;
}
