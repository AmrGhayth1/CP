#include <bits/stdc++.h>
using namespace std;
#define HONDA ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;

ll fact(ll n){
    ll cnt = 0;
    for(ll i = 2; i * i <= n; i++){
        while(n % i == 0){
            n /= i;
            cnt++;
        }
    }
    if(n > 1) cnt++;
    return cnt - 1;
}

int main() {
    HONDA
    int t;
    cin >> t;
    while(t--){
        ll k;
        cin >> k;
        ll num = fact(k);
        if(num == 0) cout << -1 << endl ;
        else cout << num << endl ;
    }
    return 0;
}
