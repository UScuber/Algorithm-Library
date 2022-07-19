#include <bits/stdc++.h>
#include "template.hpp"
using namespace std;

#include <functional>
template <class graph>
pair<vector<int>, int> find_centor(const graph &g){
  const int n = g.size();
  vector<int> dist(n), prev(n, -1);
  function<void(int,int)> dfs = [&](int pos, int par){
    for(const auto &x : g[pos]) if(x != par){
      dist[x] = dist[pos] + 1;
      prev[x] = pos;
      dfs(x, pos);
    }
  };
  dfs(0, -1);
  int pos = max_element(dist.begin(), dist.end()) - dist.begin();
  dist.assign(n, 0); prev.assign(n, -1);
  dfs(pos, -1);
  pos = max_element(dist.begin(), dist.end()) - dist.begin();
  const int longest = dist[pos];
  int max_dist = longest;
  vector<int> res;
  for(int i = pos; i != -1; i = prev[i]){
    if(max_dist == longest/2 || max_dist == (longest+1)/2) res.push_back(i);
    max_dist--;
  }
  return { res, longest };
}