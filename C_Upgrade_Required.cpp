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

struct SegTree {
    struct Node {
        ll val;
        bool assign; 
        ll lazy_sub; 
        Node(): val(0), assign(false), lazy_sub(0) {}
    };

    int n;
    vector<Node> tree;

    SegTree(int n): n(n) {
        tree.resize(4*n);
    }

    void build(vector<ll>& a, int idx, int l, int r) {
        if(l == r) {
            tree[idx].val = a[l];
            return;
        }
        int mid=(l+r)/2;
        build(a,idx*2,l,mid);
        build(a,idx*2+1,mid+1,r);
    }

    void push(int idx, int l, int r) {
        if(tree[idx].assign) {
            tree[idx].val = 0;
            if(l!=r) {
                tree[idx*2].assign = true;
                tree[idx*2].lazy_sub = 0;
                tree[idx*2+1].assign = true;
                tree[idx*2+1].lazy_sub = 0;
            }
            tree[idx].assign = false;
        }
        if(tree[idx].lazy_sub != 0) {
            tree[idx].val -= tree[idx].lazy_sub * (r-l+1);
            if(l!=r) {
                tree[idx*2].lazy_sub += tree[idx].lazy_sub;
                tree[idx*2+1].lazy_sub += tree[idx].lazy_sub;
            }
            tree[idx].lazy_sub = 0;
        }
    }

    void make0(int idx, int l, int r, int ql, int qr) {
        push(idx,l,r);
        if(ql>r || qr<l) return;
        if(ql<=l && r<=qr) {
            tree[idx].assign = true;
            tree[idx].lazy_sub = 0;
            push(idx,l,r);
            return;
        }
        int mid=(l+r)/2;
        make0(idx*2,l,mid,ql,qr);
        make0(idx*2+1,mid+1,r,ql,qr);
    }

    void sub(int idx, int l, int r, int ql, int qr, ll val) {
        push(idx,l,r);
        if(ql>r || qr<l) return;
        if(ql<=l && r<=qr) {
            tree[idx].lazy_sub += val;
            push(idx,l,r);
            return;
        }
        int mid=(l+r)/2;
        sub(idx*2,l,mid,ql,qr,val);
        sub(idx*2+1,mid+1,r,ql,qr,val);
    }

    ll query(int idx, int l, int r, int pos) {
        push(idx,l,r);
        if(l==r) return tree[idx].val;
        int mid=(l+r)/2;
        if(pos<=mid) return query(idx*2,l,mid,pos);
        else return query(idx*2+1,mid+1,r,pos);
    }

};

int main()
{
    // بسم الله
    AMR
        ll t = 1;
// cin >> t;
next:
    while (t--)
    {

        ll n, q;
        cin >> n >> q;
        vector<ll> a(n + 1);
        for (ll i = 1; i <= n; i++)
            a[i] = i;

        SegTree st(n);
        st.build(a, 1 , 1 ,  n );

        while (q--)
        {
            ll l, r;
            cin >> l >> r;
            ll x = st.query(1 , 1 , n , l);
            cout << x << endl; ;
            st.make0(1 ,1 , n , 1 , l - 1);
            st.sub(1 , 1 , n , l, r - 1, x);
        }
    }

    return 0;
}
