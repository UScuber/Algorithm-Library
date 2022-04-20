#include <bits/stdc++.h>
using namespace std;

template <class T, T(*op)(const T&,const T&), T(*e)()>
struct SegmentTree {
  SegmentTree(int _n) : n(_n){
    while((1 << log) < n) log++;
    len = 1 << log;
    d.resize(len * 2, e());
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
  void set(int i, const T &x){
    assert(0 <= i && i < n);
    d[i + len] = x;
  }
  T get(const int &i) const{
    assert(0 <= i && i < n);
    return d[i + len];
  }
  void build(){
    for(int k = len - 1; k >= 1; k--)
      d[k] = op(d[2*k], d[2*k+1]);
  }
  T query(int l, int r){
    assert(0 <= l && l <= r && r <= n);
    l += len; r += len;
    T left = e(), right = e();
    while(l < r){
      if(l & 1) left = op(left, d[l++]);
      if(r & 1) right = op(d[--r], right);
      l >>= 1; r >>= 1;
    }
    return op(left, right);
  }
  private:
  int n = 1, log = 0, len = 0;
  vector<T> d;
};

/*
struct Data {
  int a;
};
Data op(const Data &a, const Data &b){
  return { min(a.a, b.a) };
}
Data e(){
  return { 0 };
}
*/