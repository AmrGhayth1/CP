#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;
const ll MOD = 1e9 + 7;

int main()
{
    // بسم الله
    AMR
        ll t = 1;
    cin >> t;
next:
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n), fq(n + 1, 0);
        vector<bool> us(n+1 , 0 ) ;  
         vector<ll> ans ; 
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            fq[a[i]]++; 
        }

        ll lst = a.back();
       
        for (ll i = 1; i <= n ; i++)
        {
            if (!fq[i])
            {
                ans.push_back(i) ; 
                cout << i << ' ';
                a.push_back(i) ; 
                k--;
                lst = i;
            }
        if (k == 0)
        {
            cout << endl;
            goto next;
        }
        }
        for(ll i = a.size()-1 ; i >=0 ; i -- ){
            if(us[a[i]] == 0){
                ans.push_back(a[i]) ; 
                us[a[i]] = 1 ;
            }
        }
        reverse(all(ans)) ; 
        for(ll i = 0 ; i < k ; i ++){
            cout << ans[i%ans.size() ] << ' ';
        }
        cout << endl; 
    }
    return 0;
}
