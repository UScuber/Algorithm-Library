#include <bits/stdc++.h>
using namespace std;

struct UnionFindW{
  vector<int> par, rank;
  vector<int> diff_weight;

  UnionFindW(int n = 1, int sum_unity = 0) : par(n), rank(n), diff_weight(n){
    for(int i = 0; i < n; i++) par[i] = i, rank[i] = 0, diff_weight[i] = sum_unity;
  }
  int root(int x){
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