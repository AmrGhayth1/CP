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
// typedef unsigned __int128 bll;  // not used here

int main()
{
    AMR
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll sm = 0;
        vector<ll> a;

        for (ll i = 0; i < n; i++) {
            ll x;
            cin >> x;
            sm += __builtin_popcountll(x);
            for (ll j = 0; j <= 60; j++) {
                if ((x & (1LL << j)) == 0) {
                    a.push_back(1LL << j);
                }
            }
        }

        sort(all(a));
        for (ll i = 0; i < a.size(); i++) {
            if (k >= a[i]) {
                k -= a[i];
                sm++;
            } else {
                break;
            }
        }
        cout << sm << endl;
    }
    return 0;
}
