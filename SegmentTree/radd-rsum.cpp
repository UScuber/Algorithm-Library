#include <bits/stdc++.h>
using namespace std;

//区間加算、区間和

template<class T> struct segmentTree {
  segmentTree(int x){
    while(n < x) n *= 2;
    d.resize(2 * n - 1);
    lazy.resize(2 * n - 1);
  }
  void set(int i, T x){
    assert(0 <= i && i < n);
    d[i + n - 1] += x;
  }
  void build(){
    for(int i = n - 2; i >= 0; i--)
      d[i] = d[i * 2 + 1] + d[i * 2 + 2];
  }
  void add(int l, int r, T x){
    assert(0 <= l && l <= r && r <= n);
    add(l, r, x, 0, 0, n);
  }
  T sum(int l, int r){
    assert(0 <= l && l <= r && r <= n);
    return sum(l, r, 0, 0, n);
  }
  private:
  int n = 1;
  vector<T> d, lazy;
  void eval(int k, int l, int r){
    d[k] += lazy[k];
    if(r - l > 1){
      lazy[2*k+1] += lazy[k] / 2;
      lazy[2*k+2] += lazy[k] / 2;
    }
    lazy[k] = 0;
  }
  void add(int a, int b, T x, int k, int l, int r){
    eval(k, l, r);
    if(b <= l || r <= a) return;
    if(a <= l && r <= b) {
      lazy[k] += (r - l) * x;
      eval(k, l, r);
    }else{
      add(a, b, x, 2*k+1, l, (l+r)/2);
      add(a, b, x, 2*k+2, (l+r)/2, r);
      d[k] = d[2*k+1] + d[2*k+2];
    }
  }
  T sum(int a, int b, T k, int l, int r){
    eval(k, l, r);
    if(b <= l || r <= a) return 0;
    if(a <= l && r <= b) return d[k];
    T vlef = sum(a, b, 2*k+1, l, (l+r)/2);
    T vrig = sum(a, b, 2*k+2, (l+r)/2, r);
    return vlef + vrig;
  }
};