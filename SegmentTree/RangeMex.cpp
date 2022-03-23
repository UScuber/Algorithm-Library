#include <bits/stdc++.h>
using namespace std;

template<class T>
struct SegmentTree {
  SegmentTree(int _n) : n(_n){
    while((1 << log) < n) log++;
    len = 1 << log;
    d.assign(len * 2, -1);
  }
  void update(int k, const T &x){
    assert(0 <= k && k < n);
    k += len;
    d[k] = x;
    while(k > 1){
      k >>= 1;
      d[k] = min(d[k*2], d[k*2+1]);
    }
  }
  int min_left(int l, int r, const T &x) const{
    assert(0 <= l && l <= r && r <= n);
    return min_left_sub(l, r, x, 1, 0, len);
  }
  private:
  const T inf = numeric_limits<T>::max() - 1;
  int n = 1, log = 0, len = 0;
  vector<T> d;
  //範囲外であればreturn b
  int min_left_sub(int a, int b, const T &x, int k, int l, int r) const{
    if(d[k] > x || r <= a || b <= l) return b;
    if(k >= len) return k - len;
    int vlef = min_left_sub(a, b, x, 2*k, l, (l+r)/2);
    if(vlef != b) return vlef;
    return min_left_sub(a, b, x, 2*k+1, (l+r)/2, r);
  }
};
struct RangeMexQuery {
  RangeMexQuery(const vector<int> &a) : d(a), n(a.size()), root(a.size()){}
  //add_query [l, r) 0-indexed
  void add_query(const int &l, const int &r){
    assert(0 <= l && l <= r && r <= n);
    root[r-1].emplace_back(l, idx);
    idx++;
  }
  void build(){
    SegmentTree<int> seg(n + 1);
    res.assign(idx, -1);
    for(int i = 0; i < n; i++){
      seg.update(d[i], i);
      for(auto &x : root[i]){
        int pos = seg.min_left(0, n+1, x.first-1);
        res[x.second] = pos;
      }
    }
  }
  vector<int> &get(){ return res; }
  private:
  vector<int> d, res;
  vector<vector<pair<int,int>>> root;
  int n, idx = 0;
};