#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int main()
{
    AMR
    ll t = 1 ;
    cin >> t;
    priority_queue<ll> p ;
     map<ll,queue<ll>> mp ;
     queue<ll> q ;
      ll rank = 1 ;
     fi(0 , t){
    {     
     ll ch ; 
     cin >> ch ;
    
     if(ch == 1 ){
        ll x ; 
        cin >> x  ;
        p.push(x) ;
        q.push(x) ;
        
            mp[x].push( rank ) ;
        rank ++ ;
     }
     if(ch == 2){
        while(mp[q.front()].empty() ){
            q.pop() ;
        }
        cout << mp[q.front()].front() << ' ' ;
        mp[q.front() ].pop() ; 
        q.pop() ; 
     }
     if(ch == 3 ){
        while(mp[p.top()].empty() ){
            p.pop() ;
        }
        cout <<mp[p.top()].front() << ' ';
        mp[p.top()].pop() ;
        p.pop() ;
     }
    
       } }
    return 0;
}
