#include <bits/stdc++.h>
using namespace std;

template <class T>
struct CumulativeSum2D {
  CumulativeSum2D(const int h, const int w) : h(h), w(w), a(h+1, vector<T>(w+1)){}
  CumulativeSum2D(const vector<vector<T>> &v) : h(v.size()), w(v[0].size()), a(h+1, vector<T>(w+1)){
    for(int i = 0; i < h; i++)
      for(int j = 0; j < w; j++) a[i + 1][j + 1] = v[i][j];
  }
  void set(const int i, const int j, const T x){
    assert(0 <= i && i < h);
    assert(0 <= j && j < w);
    a[i + 1][j + 1] += x;
  }
  void build(){
    for(int i = 0; i < h; i++)
      for(int j = 0; j < w; j++)
        a[i + 1][j + 1] += a[i + 1][j] + a[i][j + 1] - a[i][j];
  }
  T query(const int ly, const int lx, const int ry, const int rx) const{
    assert(0 <= ly && ly <= ry && ry <= h);
    assert(0 <= lx && lx <= rx && rx <= w);
    return a[ry][rx] - a[ry][lx] - a[ly][rx] + a[ly][lx];
  }
  private:
  int h, w;
  vector<vector<T>> a;
};
