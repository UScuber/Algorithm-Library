#include <bits/stdc++.h>
#include "template.hpp"
using namespace std;

struct Cycle {
  Cycle(const graph &_g) : g(_g){}
  vector<Edge<int>> detect(){
    const int n = g.size();
    used.assign(n, 0);
    prev.assign(n, -1);
    for(int i = 0; i < n; i++){
      if(!used[i] && dfs(i)){
        reverse(cyc.begin(), cyc.end());
        return cyc;
      }
    }
    return {};
  }
  private:
  const graph &g;
  vector<int> used;
  vector<Edge<int>> prev, cyc;
  bool dfs(int pos){
    used[pos] = 1;
    for(const auto &x : g[pos]){
      if(!used[x]){
        prev[x] = x;
        if(dfs(x)) return true;
      }else if(used[x] == 1){
        int cur = pos;
        cyc.push_back(x);
        while(cur != x){
          cyc.push_back(prev[cur]);
          cur = prev[cur].from;
        }
        return true;
      }
    }
    used[pos] = 2;
    return false;
  }
};