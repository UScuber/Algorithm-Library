#include <bits/stdc++.h>
using namespace std;

template <class T>
struct LazySegmentTree {
  LazySegmentTree(const int _n) : n(_n){
    while((1 << log) < n) log++;
    len = 1 << log;
    d.assign(len * 2, 0);
    lazy.assign(len, inf);
    si.assign(len * 2, 1);
    for(int i = len - 1; i >= 1; i--) si[i] = si[i<<1] << 1;
  }
  void set(const int i, const T &x){
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
  void update(int l, int r, const T &x){
    assert(0 <= l && l <= r && r <= n);
    l += len; r += len;
    const int l_ctz = __builtin_ctz(l);
    const int r_ctz = __builtin_ctz(r);
    for(int i = log; i > l_ctz; i--) push(l >> i);
    for(int i = log; i > r_ctz; i--) push((r - 1) >> i);
    const int lt = l, rt = r;
    while(l < r){
      if(l & 1) apply(l++, x);
      if(r & 1) apply(--r, x);
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
  vector<T> d, lazy;
  vector<int> si;
  const T inf = numeric_limits<T>::min();
  int n = 1, log = 0, len = 0;
  inline void update(const int k){ d[k] = d[2*k] + d[2*k+1]; }
  inline void apply(const int k, const T &x){
    d[k] = x * si[k];
    if(k < len) lazy[k] = x;
  }
  inline void push(const int k){
    if(lazy[k] == inf) return;
    apply(2*k, lazy[k]);
    apply(2*k+1, lazy[k]);
    lazy[k] = inf;
  }
};