#include <bits/stdc++.h>
using namespace std;
#define HONDA ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long double ld;
typedef long long ll;
#define mpll  map<ll,ll>
#define vll vector<ll>
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define fit(c) for(auto it = c.begin(); it != c.end(); ++it)
#define endl "\n"
int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};
inline bool in(int i, int j, int rows, int cols){
    return i>=0 && i<rows && j>=0 && j<cols;
}
inline bool in(int i, int l, int h){
    return i >= l && i <= h;
}
using namespace std;
int main() {
    HONDA
    int t = 1;
    //cin >> t;
    while(t--){
        ll n;cin>>n;
        ll cnt=0;
        bool overflow=0;
        unsigned __int128 num=1;
        vector<ll> nums;
        ll cnts=0;
        fi(0,n){
            string x;cin>>x;
            if(x == "add"){
                if(nums.size() == 0){
                    cnt ++ ; 
                }else{
                cnt += nums.back() ;
            }
        }
            else if(x == "for"){
                ll y;cin>>y;
                if(nums.size() == 0){
                    num = y ; 
                }else{
                num = y * nums.back() ;
                }
                if(num * y > (1LL<<32)-1){
                    num = (1LL<<32);
                }
                nums.push_back(num) ;
            }
            else{
                if(nums.size() != 0){
                    nums.pop_back();
                }
            }
            if(cnt>(1LL<<32)-1) overflow=1;
        }
        if(overflow) cout<<"OVERFLOW!!!";
        else cout<<cnt<<endl;
    }
    return 0;
}