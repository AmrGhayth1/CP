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
bool ans(ll l1 , ll b1 , ll l2 , ll b2 , ll l3 ,ll  b3 ){

       ll tt = l1 * b1 + l2 * b2 + l3 * b3;
    ll s = sqrt(tt);
    if (s * s != tt) {
        return 0;
    }

    if (l1 == s && l2 == s && l3 == s && b1 + b2 + b3 == s) {
        return 1;
    }
    if (b1 == s && b2 == s && b3 == s && l1 + l2 + l3 == s) {
        return 1;
    }
    if (l1 == l2 && b1 + b2 == s && l3 == s - l1 && b3 == s) {
        return 1;
    }
    if (b1 == b2 && l1 + l2 == s && b3 == s - b1 && l3 == s) {
        return 1;
    }
    if (l1 == s && b2 == b3 && l2 + l3 == s && b1 + b2 == s) {
        return 1;
    }
    if (b1 == s && l2 == l3 && b2 + b3 == s && l1 + l2 == s) {
        return 1;
    }
    if (l1 + l2 == s && b1 == b2 && b1 + b3 == s && l3 == s) {
        return 1;
    }
    if (b1 + b2 == s && l1 == l2 && l1 + l3 == s && b3 == s) {
        return 1;
    }
    if (l1 + l3 == s && b1 == b3 && b1 + b2 == s && l2 == s) {
        return 1;
    }
    if (b1 + b3 == s && l1 == l3 && l1 + l2 == s && b2 == s) {
        return 1;
    }
    if (l2 + l3 == s && b2 == b3 && b2 + b1 == s && l1 == s) {
        return 1;
    }
    if (b2 + b3 == s && l2 == l3 && l2 + l1 == s && b1 == s) {
        return 1;
    }
    return 0;

}

int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
      ll l1, b1, l2, b2, l3, b3;
        cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
      
        if (ans(l1 , b1 , l2 , b2 , l3 , b3 ) ){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}
