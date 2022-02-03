#include <bits/stdc++.h>
using namespace std;

template<class T, const T&(*op)(const T&,const T&)>
struct SegmentTree {
  SegmentTree(int _n) : n(_n){
    while((1 << log) < n) log++;
    len = 1 << log;
    //inf = -op(inf-1, -inf+1);
    inf = -op(inf, -inf);
    d.resize(len * 2, inf);
  }
  void update(int k, const T &x){
    assert(0 <= k && k < n);
    k += len;
    d[k] = x;
    while(k > 1){
      k >>= 1;
      d[k] = op(d[k*2], d[k*2+1]);
    }
  }
  void set(const int &i, const T &x){
    assert(0 <= i && i < n);
    d[i + len] = x;
  }
  void get(const int &i) const{
    assert(0 <= i && i < n);
    return d[i + len];
  }
  void build(){
    for(int k = len - 1; k >= 1; k--) d[k] = op(d[2*k], d[2*k+1]);
  }
  T query(int l, int r){
    assert(0 <= l && l <= r && r <= n);
    l += len; r += len;
    T left = inf, right = inf;
    while(l < r){
      if(l & 1) left = op(left, d[l++]);
      if(r & 1) right = op(d[--r], right);
      l >>= 1; r >>= 1;
    }
    return op(left, right);
  }
  int min_right(int l, int r, const T &x){
    assert(0 <= l && l <= r && r <= n);
    return min_right_sub(l, r, x, 1, 0, n);
  }
  int min_left(int l, int r, const T &x){
    assert(0 <= l && l <= r && r <= n);
    return min_left_sub(l, r, x, 1, 0, n);
  }
  private:
  T inf = numeric_limits<T>::max();
  int n = 1, log = 0, len = 0;
  vector<T> d;
  //範囲外であればreturn a-1
  int min_right_sub(int a, int b, const T &x, int k, int l, int r){
    if(op(d[k]+op(1,-1),x)==x || r <= a || b <= l) return a - 1;
    if(k >= n) return k - n;

    int vrig = min_right_sub(a, b, x, 2*k+1, (l+r)/2, r);
    if(vrig != a - 1) return vrig;
    return min_right_sub(a, b, x, 2*k, l, (l+r)/2);
  }
  //範囲外であればreturn b
  int min_left_sub(int a, int b, const T &x, int k, int l, int r){
    if(op(d[k]+op(1,-1),x)==x || r <= a || b <= l) return b;
    if(k >= n) return k - n;

    int vlef = min_left_sub(a, b, x, 2*k, l, (l+r)/2);
    if(vlef != b) return vlef;
    return min_left_sub(a, b, x, 2*k+1, (l+r)/2, r);
  }
};