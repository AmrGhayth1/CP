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
struct Node{
    ll oring;
    ll lazy=0;
    bool islazy = 0;
    Node(){     //neutral node
        oring = 0;
    }
    Node(ll x){ 
        oring = x;
    }
    void update(ll x, ll lx, ll rx){
        oring |= x;
        lazy |= x;
        islazy = true;
    }
};
struct segtree{
    ll treesize;
    vector<Node> segdata;
    Node merge(Node &ln, Node &rn){
        Node ans = Node();
        ans.oring = (ln.oring | rn.oring);
        return ans;
    }
    segtree(vector<ll> &arr){
        treesize = 1;
        while(treesize < arr.size()) treesize *= 2;
        segdata.assign(2*treesize, Node());
        for(ll i = 0; i < arr.size(); i++){
            segdata[treesize + i - 1] = Node(arr[i]);
        }
        for(ll i = treesize - 2; i >= 0; i--){
            segdata[i] = merge(segdata[2*i+1], segdata[2*i+2]);
        }
    }
    void propagate(ll ni, ll lx, ll rx){
        if(rx-lx==1 || !segdata[ni].islazy) return;
        ll mid = (lx + rx)/2;
        segdata[2*ni+1].update(segdata[ni].lazy, lx, mid);
        segdata[2*ni+2].update(segdata[ni].lazy, mid, rx);
        segdata[ni].lazy= segdata[ni].islazy = 0;
    }
    void update_range(ll x,ll l,ll r,ll ni, ll lx, ll rx){
        propagate(ni, lx, rx);
        if(rx <= l || lx >= r) return;
        if(lx >= l && rx <= r){
            segdata[ni].update(x, lx, rx);
            return;
        }
        ll mid = (rx + lx)/2;
        update_range(x, l, r, 2*ni+1, lx, mid);
        update_range(x, l, r, 2*ni+2, mid, rx);
        segdata[ni] = merge(segdata[2*ni+1], segdata[2*ni+2]);
    }
    Node get(ll l, ll r, ll ni, ll lx, ll rx){
        propagate(ni, lx, rx);
        if(rx <= l || lx >= r) return Node();
        if(lx >= l && rx <= r) return segdata[ni];
        ll mid = (rx+lx)/2;
        Node ln = get(l, r, 2*ni+1, lx, mid);
        Node rn = get(l, r, 2*ni+2, mid, rx);
        return merge(ln, rn);
    }
    ll query(ll i, ll ni, ll lx, ll rx){
        propagate(ni,lx,rx);
        if (rx <= i || lx > i) return 0;
        if (rx - lx == 1) return segdata[ni].oring;
        ll mid = (lx + rx) / 2;
        if (i < mid) return query(i, 2 * ni + 1, lx, mid);
        else return query(i, 2 * ni + 2, mid, rx);
    }
};
using namespace std;
int main() {
    HONDA
    int t = 1;
    //cin >> t;
    while(t--){
        ld n,s;cin>>n>>s;
        vector<ld> d(n),t(n);
        fi(0,n) cin>>t[i];
        fi(0,n) cin>>d[i];
        ll cnt=0;
        fi(0,n){
            ld time = (d[i]/(s*(1.0)));
            if(time <= t[i]) cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}