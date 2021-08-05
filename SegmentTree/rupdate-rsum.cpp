#include <bits/stdc++.h>
using namespace std;

//区間の更新、区間和

template <class T> struct LazySegTree {
  LazySegTree(int x){
    while(n < x) n *= 2;
    d.resize(n*2 - 1);
    lazy.resize(n*2 - 1, inf);
    si.resize(n*2 - 1);
    si[0] = n;
    for(int i = 1; i < n*2 - 1; i++) si[i] = si[(i-1) / 2] / 2;
  }
  void set(int i, T x){ d[i + n - 1] = x; }
  void build(){
    for(int i = n - 2; i >= 0; i--)
      d[i] = d[i*2+1] + d[i*2+2];
  }
  void update(int a, int b, T x){ update_sub(a, b, 0, 0, n, x); }
  T query(int a, int b){ return query_sub(a, b, 0, 0, n); }
  private:
  vector<T> d, lazy, si;
  int n = 1;
  const T inf = numeric_limits<T>::max();
  void eval(int k){
    if(lazy[k] == inf) return;
    if(k < n - 1){
      lazy[2*k+1] = lazy[k];
      lazy[2*k+2] = lazy[k];
    }
    d[k] = lazy[k] * si[k];
    lazy[k] = inf;
  }
  void update_sub(int a, int b, int k, int l, int r, T x){
    eval(k);
    if(r <= a || b <= l) return;
    if(a <= l && r <= b){
      lazy[k] = x;
      eval(k);
    }else{
      update_sub(a, b, 2*k+1, l, (l+r)/2, x);
      update_sub(a, b, 2*k+2, (l+r)/2, r, x);
      d[k] = d[2*k+1] + d[2*k+2];
    }
  }
  T query_sub(int a, int b, int k, int l, int r){
    eval(k);
    if(r <= a || b <= l) return 0;
    if(a <= l && r <= b) return d[k];
    else{
      T vlef = query_sub(a, b, k*2+1, l, (l+r)/2);
      T vrig = query_sub(a, b, k*2+2, (l+r)/2, r);
      return vlef + vrig;
    }
  }
};