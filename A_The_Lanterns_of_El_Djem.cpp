#include "bits/stdc++.h"
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vint vector<int>
#define pii pair<int, int>
#define mii map<int, int>
#define mmii multimap<int, int>
#define unmii unordered_map<int, int>
#define int long long
#define ld long double
#define PI 3.141592653589793238462
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pushh(x) push_back(x)
#define cinv(T) for(auto& i : T) cin>>i;
#define coutv(T) for(auto& i : T)cout<<i<<' ';cout<<nl;
#define pop pop_back()
#define nl '\n'
#define int long long 
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
const int N = 2e5 + 10;
 
void solve() {
    int n, a, b, c; cin>>n>>a>>b>>c;
    if (a + b + c > n) return void(cout<<-1<<nl);
 
    vector<pair<int, char>> m = {{a, 'R'}, {b, 'G'}, {c, 'B'}};
    string ans = "";
    char prev = ' ';
    int cry = n - (a+b+c) ; 
    for(int i = 0 ; i < cry ; i ++ ){
        sort(m.begin() , m.end());
        m[0].first ++ ; 
    }
    for (int i = 0; i < n; i++)
    {
        sort(rall(m));
        bool u = false;
        for (int j = 0; j < 3; j++) {
        if (m[j].first &&  m[j].second != prev) {
            ans += m[j].second;
            m[j].first--;
            prev = m[j].second;
            u = true;
            break;  
        }
    }
    if(!u) return void(cout<<-1<<nl);
}
    cout<<ans<<nl;
}
 
int32_t main() {
    fastio
    int t = 1; cin>>t;
    
    while (t--) {
         solve();
     }
 
    return 0;
}