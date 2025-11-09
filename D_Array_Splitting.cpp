#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int main()
{
    AMR
        ll n,
        k;
    cin >> n >> k;
    ll k1 = k ;
    ll a[n];
    vector<ll> ans ;
    priority_queue<pair<ll, ll>> p;
    ll pf[n];
    ll pref = 0;
    fi(0, n)
    {
        cin >> a[i];
    }
    for (ll i = n - 1; i >= 0; i--)
    {
        pref += a[i];
        if(i != 0){
        p.push({pref, i}); }
        pf[i] = pref ;
    }
    k-=1 ;
    while(!p.empty() && k-- ){
        ans.push_back(p.top().second) ;
        p.pop();
    }
    ans.push_back(0);
    sort(all(ans)) ;
    ll x = 0;
    ll res = 0;
    for(ll i = k1 ; i > 0 ; i --){
        res += (pf[ans[i-1]] -x) * i ;
        x = pf[ans[i-1]] ;
    }
    cout << res ; 
 
    return 0;
}