#include <bits/stdc++.h>
#include "template.hpp"
using namespace std;

vector<Point> totsuhou(const vector<Point> &pos){
  int n = pos.size();
  vector<Point> g(2 * n);
  int k = 0;
  for(int i = 0; i < n; i++){
    while(k > 1 && cross(g[k-1] - g[k-2], pos[i] - g[k-1]) <= 0) k--;
    g[k++] = pos[i];
  }
  for(int i = n - 2, t = k; i >= 0; i--){
    while(k > t && cross(g[k-1] - g[k-2], pos[i] - g[k-1]) <= 0) k--;
    g[k++] = pos[i];
  }
  g.resize(--k);
  return g;
}