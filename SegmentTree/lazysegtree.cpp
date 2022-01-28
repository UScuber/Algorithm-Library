#include <bits/stdc++.h>
using ll = long long;
using namespace std;

template <class T, T(*op)(const T&,const T&), T(*e)(), class F,
          T(*mapping)(const F&,const T&), F(*composition)(const F&,const F&), F(*id)()>
struct LazySegmentTree {
  LazySegmentTree(int _n) : n(_n){
    while((1 << log) < n) log++;
    len = 1 << log;
    d.assign(len * 2, e());
    lazy.assign(len, id());
  }
  void set(int i, const T &x){
    assert(0 <= i && i < n);
    d[i + len] = x;
  }
  T &operator[](int i){
    assert(0 <= i && i < n);
    return d[i + len];
  }
  void build(){
    for(int i = len - 1; i >= 1; i--) update(i);
  }
  void update(int l, int r, const F &x){
    assert(0 <= l && l <= r && r <= n);
    l += len; r += len;
    for(int i = log; i >= 1; i--){
      if((l >> i) << i != l) push(l >> i);
      if((r >> i) << i != r) push((r - 1) >> i);
    }
    const int lt = l, rt = r;
    while(l < r){
      if(l & 1) apply(l++, x);
      if(r & 1) apply(--r, x);
      l >>= 1; r >>= 1;
    }
    l = lt; r = rt;
    for(int i = 1; i <= log; i++){
      if((l >> i) << i != l) update(l >> i);
      if((r >> i) << i != r) update((r - 1) >> i);
    }
  }
  T query(int l, int r){
    assert(0 <= l && l <= r && r <= n);
    l += len; r += len;
    for(int i = log; i >= 1; i--){
      if((l >> i) << i != l) push(l >> i);
      if((r >> i) << i != r) push((r - 1) >> i);
    }
    T left = e(), right = e();
    while(l < r){
      if(l & 1) left = op(left, d[l++]);
      if(r & 1) right = op(d[--r], right);
      l >>= 1; r >>= 1;
    }
    return op(left, right);
  }
  private:
  vector<T> d;
  vector<F> lazy;
  int n = 1, log = 0, len = 0;
  void update(const int &k){ d[k] = op(d[2*k], d[2*k+1]); }
  void apply(const int &k, const F &x){
    d[k] = mapping(x, d[k]);
    if(k < len) lazy[k] = composition(lazy[k], x);
  }
  void push(const int &k){
    apply(2*k, lazy[k]);
    apply(2*k+1, lazy[k]);
    lazy[k] = id();
  }
};
struct Data {
  ll a, len;
};
struct Lazy {
  ll a, b;
};
Data op(const Data &a, const Data &b){
  return { a.a+b.a, a.len+b.len };
}
Data e(){
  return { 0, 0 };
}
Data mapping(const Lazy &a, const Data &b){
  return { a.a*b.a + a.b*b.len, b.len };
}
Lazy composition(const Lazy &a, const Lazy &b){
  return { a.a*b.a, a.b*b.a + b.b };
}
Lazy id(){
  return { 1, 0 };
}