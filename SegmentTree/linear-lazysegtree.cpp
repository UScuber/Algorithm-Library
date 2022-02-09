#include <bits/stdc++.h>
using ll = long long;
using namespace std;

template <class T>
struct LazySegmentTree {
  struct Lazy {
    T s,p;
  };
  LazySegmentTree(int _n) : n(_n){
    while((1 << log) < n) log++;
    len = 1 << log;
    d.assign(len * 2, 0);
    lazy.assign(len, {0,0});
    si = new int[len * 2];
    si[1] = len;
    for(int i = 2; i < len * 2; i++) si[i] = si[i>>1]>>1;
  }
  ~LazySegmentTree(){ delete si; }
  void set(int i, const T &x){
    assert(0 <= i && i < n);
    d[i + len] = x;
  }
  T get(int p){
    assert(0 <= p && p < n);
    p += len;
    for(int i = log; i >= 1; i--) push(p >> i);
    return d[p];
  }
  void build(){
    for(int i = len - 1; i >= 1; i--) update(i);
  }
  void update(int l, int r, const Lazy &x){
    assert(0 <= l && l <= r && r <= n);
    l += len; r += len;
    const int l_ctz = __builtin_ctz(l);
    const int r_ctz = __builtin_ctz(r);
    for(int i = log; i > l_ctz; i--) push(l >> i);
    for(int i = log; i > r_ctz; i--) push((r - 1) >> i);
    const int lt = l, rt = r;
    int L = l - len, R = r - len;
    while(l < r){
      if(l & 1){
        apply(l, x, L-lt+len);
        L += si[l++];
      }
      if(r & 1){
        R -= si[--r];
        apply(r, x, R-lt+len);
      }
      l >>= 1; r >>= 1;
    }
    l = lt; r = rt;
    for(int i = l_ctz + 1; i <= log; i++) update(l >> i);
    for(int i = r_ctz + 1; i <= log; i++) update((r - 1) >> i);
  }
  T query(int l, int r){
    assert(0 <= l && l <= r && r <= n);
    l += len; r += len;
    const int l_ctz = __builtin_ctz(l);
    const int r_ctz = __builtin_ctz(r);
    for(int i = log; i > l_ctz; i--) push(l >> i);
    for(int i = log; i > r_ctz; i--) push((r - 1) >> i);
    T res = 0;
    while(l < r){
      if(l & 1) res += d[l++];
      if(r & 1) res += d[--r];
      l >>= 1; r >>= 1;
    }
    return res;
  }
  private:
  vector<T> d;
  vector<Lazy> lazy;
  int *si;
  int n = 1, log = 0, len = 0;
  void update(const int &k){ d[k] = d[2*k] + d[2*k+1]; }
  void apply(const int &k, const Lazy &x, const int &r){
    const T tot = (x.s*2+x.p*(r*2+si[k]-1))*si[k] / 2;
    d[k] += tot;
    if(k < len){
      lazy[k].s += x.s + x.p*r;
      lazy[k].p += x.p;
    }
  }
  void push(const int &k){
    if(lazy[k].s == 0 && lazy[k].p == 0) return;
    apply(2*k, lazy[k], 0);
    apply(2*k+1, lazy[k], si[2*k+1]);
    lazy[k] = { 0, 0 };
  }
};

int main(){
  int n,q;
  cin >> n >> q;
  LazySegmentTree<ll> seg(n);
  for(int i = 0; i < q; i++){
    int t; cin >> t;
    //update: (l <= i < r)  a[i] = a[i] + s + p*(i - l)
    if(t == 0){
      int l,r; ll s,p;
      cin >> l >> r >> s >> p;
      l--;
      seg.update(l, r, { s, p });
    }
    //query: a[l]+a[l+1]+...+a[r-2]+a[r-1]
    else{
      int l,r;
      cin >> l >> r;
      l--;
      cout << seg.query(l, r) << "\n";
    }
  }
}