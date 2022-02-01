#include <bits/stdc++.h>
using namespace std;

//区間加算、区間の最小値/最大値

template<class T, const T&(*op)(const T&,const T&)>
struct segmentTree {
  segmentTree(int x, const T &sum_unity = T()){
    while(x > n) n *= 2;
    inf = -op(inf-1, -inf+1);
    d.resize(2*n - 1);
    lazy.resize(2*n - 1, 0);
    d[0] = sum_unity;
  }
  void set(int i, T x){
    assert(0 <= i && i < n);
    d[i + n - 1] += x;
  }
  void build(){
    for(int i = n - 2; i >= 0; i--)
      d[i] = op(d[i*2+1], d[i*2+2]);
  }
  void add(int l, int r, T x){
    assert(0 <= l && l <= r && r <= n);
    add_sub(l, r, x, 0, 0, n);
  }
  T query(int l, int r){
    assert(0 <= l && l <= r && r <= n);
    return query_sub(l, r, 0, 0, n);
  }
  int min_right(int l, int r, T x){
    assert(0 <= l && l <= r && r <= n);
    return min_right_sub(l, r, x, 0, 0, n);
  }
  int min_left(int l, int r, T x){
    assert(0 <= l && l <= r && r <= n);
    return min_left_sub(l, r, x, 0, 0, n);
  }
  private:
  vector<T> d, lazy;
  int n = 1;
  T inf = numeric_limits<T>::max();
  void eval(int k){
    d[k] += lazy[k];
    if(k < n - 1){
      lazy[k*2+1] += lazy[k];
      lazy[k*2+2] += lazy[k];
    }
    lazy[k] = 0;
  }
  void add_sub(int a, int b, T x, int k, int l, int r){
    eval(k);
    if(r <= a || b <= l) return;
    if(a <= l && r <= b){
      lazy[k] += x;
      eval(k);
    }else{
      add_sub(a, b, x, k*2+1, l, (l+r)/2);
      add_sub(a, b, x, k*2+2, (l+r)/2, r);
      d[k] = op(d[k*2+1], d[k*2+2]);
    }
  }
  T query_sub(int a, int b, int k, int l, int r){
    eval(k);
    if(r <= a || b <= l) return inf;
    if(a <= l && r <= b) return d[k];
    T vlef = query_sub(a, b, k*2+1, l, (l+r)/2);
    T vrig = query_sub(a, b, k*2+2, (l+r)/2, r);
    return op(vlef, vrig);
  }
  //範囲外であればreturn a-1
  int min_right_sub(int a, int b, T x, int k, int l, int r){
    eval(k);
    if(op(d[k]+op(1,-1),x)==x || r <= a || b <= l) return a - 1;
    if(k >= n - 1) return k - (n - 1);

    int vrig = min_right_sub(a, b, x, 2*k+2, (l+r)/2, r);
    if(vrig != a - 1) return vrig;
    return min_right_sub(a, b, x, 2*k+1, l, (l+r)/2);
  }
  //範囲外であればreturn b
  int min_left_sub(int a, int b, T x, int k, int l, int r){
    eval(k);
    if(op(d[k]+op(1,-1),x)==x || r <= a || b <= l) return b;
    if(k >= n - 1) return k - (n - 1);

    int vlef = min_left_sub(a, b, x, 2*k+1, l, (l+r)/2);
    if(vlef != b) return vlef;
    return min_left_sub(a, b, x, 2*k+2, (l+r)/2, r);
  }
};