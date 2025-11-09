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
typedef __int128 bll;

bool is(string st , ll s){
    ll x = 0; 
    for (char c : st) {
        x += (c - '0');
    }
    return (x <= s); 
}

int main()
{
    AMR
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll s;
        string a ; 
        cin >> a >> s;
        ll n = a.size() ;
        ll ans = 0 ;
        ll x = 0 ; 
        for(ll i = 0 ; i < n ; i ++ ){
            x  += a[i] - '0' ;
        }
        if(s >= x){
            cout << 0 << endl ; 
            continue;
        }
        ll c = 0 ; 
        ll ten_pow = 1;
        for(ll i = n-1 ; i >= 0 ; i --){
            ll y = a[i]- '0' ;
            y += c ; 
            if(y == 0){
                ten_pow *= 10;
                continue;
            }
            ll z = 10 - y ;
            ans += ten_pow * z;
            x -= (y - 1) ; 
            c = 1 ; 
            ten_pow *= 10;
            if(s >= x) break; 
        }
        cout << ans << endl;
    }
    return 0;
}
