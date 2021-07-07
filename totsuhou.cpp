#include <bits/stdc++.h>
using namespace std;

template <class T>
struct point {
  T x,y;
  point operator+=(const point &a){
    x += a.x; y += a.y;
    return *this;
  }
  point operator-=(const point &a){
    x -= a.x; y -= a.y;
    return *this;
  }
  point operator+(const point &a) const{ return point(*this) += a; }
  point operator-(const point &a) const{ return point(*this) -= a; }
  bool operator<(const point &a) const{
    if(x != a.x) return x < a.x;
    return y < a.y;
  }
  T det(const point &a) const{
    return x * a.y - y * a.x;
  }
};
template <class T>
vector<point<T>> totsuhou(const vector<vector<T>> &pos){
  int n = pos.size();
  vector<point<T>> g(2 * n);
  int k = 0;
  for(int i = 0; i < n; i++){
    while(k > 1 && (g[k-1] - g[k-2]).det(pos[i] - g[k-1]) <= 0) k--;
    g[k++] = pos[i];
  }
  for(int i = n - 2, t = k; i >= 0; i--){
    while(k > t && (g[k-1] - g[k-2]).det(pos[i] - g[k-1]) <= 0) k--;
    g[k++] = pos[i];
  }
  g.resize(--k);
  return g;
}