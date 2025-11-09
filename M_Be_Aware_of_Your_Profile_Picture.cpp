#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
 
void SOLVE(){
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for(auto & val : a) cin >> val;
  vector<bool> done(n);
  int sum = 0;
  for(int j = k - 1; j >= 0; j--){
    bool can = true;
    int counter = 0;
    for(int i = 0; i < n; i++){
        if(a[i] & (1 << j)){
            counter++;
            continue;
        }
        if(done[i]){
            can = false;
            break;
        }
    }
    if(!can) continue;
    sum += (1 << j);
    for(int i = 0; i < n; i++){
        if(a[i] & (1 << j)) continue;
        done[i] = true;
    }
  }
  cout << sum << endl;
} 
signed main() {
  ios_base::sync_with_stdio(false), cout.tie(nullptr); cin.tie(nullptr);
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int o_o = 1; cin >> o_o;
  while(o_o --) SOLVE();
  return 0;
}