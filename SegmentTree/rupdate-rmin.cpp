#include <bits/stdc++.h>
using namespace std;

//区間更新、区間の最小値/最大値

template<class T, const T&(*op)(const T&,const T&)>
struct segmentTree {
  segmentTree(int x){
    while(x > n) n *= 2;
    inf = -op(inf, -inf);
    d.resize(2*n - 1, inf);
    lazy.resize(2*n - 1, inf);
  }
  void set(int i, T x){ d[i + n - 1] = x; }
  T &operator[](int i){ return d[i + n - 1]; }
  void build(){
    for(int k = n - 2; k >= 0; k--)
      d[k] = min(d[k * 2 + 1], d[k * 2 + 2]);
  }
  void eval(int k){
    if(lazy[k] == inf) return;
    if(k < n - 1){
      lazy[k * 2 + 1] = lazy[k];
      lazy[k * 2 + 2] = lazy[k];
    }
    d[k] = lazy[k];
    lazy[k] = inf;
  }
  void update(int a, int b, T x){ update(a, b, x, 0, 0, n); }
  T query(int a, int b){ return query_sub(a, b, 0, 0, n); }
  int min_right(int l, int r, T x){ return min_right_sub(l, r, x, 0, 0, n); }
  int min_left(int l, int r, T x){ return min_left_sub(l, r, x, 0, 0, n); }
  private:
  T inf = numeric_limits<T>::max();
  int n = 1;
  vector<T> d, lazy;
  void update(int a, int b, T x, int k, int l, int r){
    eval(k);
    if(a <= l && r <= b){
      lazy[k] = x;
      eval(k);
    }else if(a < r && l < b){
      update(a, b, x, k*2 + 1, l, (l+r)/2);
      update(a, b, x, k*2 + 2, (l+r)/2, r);
      d[k] = op(d[k * 2 + 1], d[k * 2 + 2]);
    }
  }
  T query_sub(int a, int b, int k, int l, int r){
    eval(k);
    if(r <= a || b <= l) return inf;
    if(a <= l && r <= b) return d[k];
    T vlef = query_sub(a, b, k*2 + 1, l, (r+l)/2);
    T vrig = query_sub(a, b, k*2 + 2, (r+l)/2, r);
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