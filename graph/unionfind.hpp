#include <bits/stdc++.h>
using namespace std;

//Union Find
struct UnionFind {
  private:
  int n;
  public:
  vector<int> d;
  UnionFind(int n): n(n), d(n, -1){}
  int root(int x){
    assert(0 <= x && x < n);
    if(d[x] < 0) return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y){
    x = root(x);
    y = root(y);
    if(x == y) return false;
    if(d[x] > d[y]) swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y){
    return root(x) == root(y);
  }
  int size(int x){
    return -d[root(x)];
  }
};




//重み付きUnion Find
struct UnionFindW {
  private:
  int n;
  vector<int> par, rank;
  vector<int> diff_weight;
  public:
  UnionFindW(int n = 1, int sum_unity = 0) : n(n), par(n), rank(n), diff_weight(n){
    for(int i = 0; i < n; i++) par[i] = i, rank[i] = 0, diff_weight[i] = sum_unity;
  }
  int root(int x){
    assert(0 <= x && x < n);
    if(par[x] == x){
      return x;
    }else{
      int r = root(par[x]);
      diff_weight[x] += diff_weight[par[x]];
      return par[x] = r;
    }
  }
  int weight(int x){
    root(x);
    return diff_weight[x];
  }
  bool same(int x, int y){
    return root(x) == root(y);
  }
  bool merge(int x, int y, int w){
    w += weight(x); w -= weight(y);
    x = root(x); y = root(y);
    if(x == y) return false;
    if(rank[x] < rank[y]) swap(x, y), w = -w;
    if(rank[x] == rank[y]) ++rank[x];
    par[y] = x;
    diff_weight[y] = w;
    return true;
  }
  int diff(int x, int y){
    return weight(y) - weight(x);
  }
};




struct UndoUnionFind {
  private:
  int n;
  stack<pair<int,int>> hist;
  public:
  vector<int> d;
  UndoUnionFind(int n): n(n), d(n, -1){}
  int root(int x){
    assert(0 <= x && x < n);
    if(d[x] < 0) return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y){
    x = root(x);
    y = root(y);
    hist.emplace(x, d[x]);
    hist.emplace(y, d[y]);
    if(x == y) return false;
    if(d[x] > d[y]) swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y){
    return root(x) == root(y);
  }
  int size(int x){
    return -d[root(x)];
  }
  void undo(){
    assert(!hist.empty());
    d[hist.top().first] = hist.top().second;
    hist.pop();
    d[hist.top().first] = hist.top().second;
    hist.pop();
  }
  void snapshot(){
    while(!hist.empty()) hist.pop();
  }
  void rollback(){
    while(!hist.empty()) undo();
  }
};