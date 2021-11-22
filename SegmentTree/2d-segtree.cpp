#include <bits/stdc++.h>
#include <cassert>
using namespace std;

template <class T, T(*op)(const T&,const T&), T id>
struct SegmentTree2D {
  int h,w, logh,logw;
  vector<vector<T>> d;
  SegmentTree2D() : SegmentTree2D(0,0){}
  SegmentTree2D(int _h, int _w){
    h = w = 1;
    logh = logw = 1;
    while((h <<= 1) < _h) logh++;
    while((w <<= 1) < _w) logw++;
    d.resize(h * 2, vector<T>(2 * w, id));
  }
  void set(int i, int j, T x){
    d[i + h][j + w] = x;
  }
  void build(){
    for(int i = 2*h-1; i >= h ; i--){
      for(int j = w - 1; j >= 1; j--){
        updateX(i,j);
      }
    }
    for(int i = h-1; i >= 1; i--){
      for(int j = 2*w-1 ; j >= 1; j--){
        updateY(i,j);
      }
    }
  }
  void update(int py, int px, T x){
    assert(0 <= py && py < h);
    assert(0 <= px && px < w);
    py += h, px += w;
    d[py][px] = x;
    for(int j = 1; j <= logw; j++){
      updateX(py, px>>j);
    }
    for(int i = 1; i <= logh; i++){
      for(int j = 0 ; j <= logw; j++){
        updateY(py>>i, px>>j);
      }
    }
  }
  T get(int i, int j){
    assert(0 <= i && i < h);
    assert(0 <= j && j < w);
    return d[i + h][j + w];
  }
  T query(int ly, int lx, int ry , int rx){
    assert(0 <= ly && ly <= ry && ry <= h);
    assert(0 <= lx && lx <= rx && rx <= w);
    T sml = id, smr = id;
    ly += h, ry += h;
    while(ly < ry){
      if(ly & 1) sml = op(sml, query_sub(lx, rx, ly++));
      if(ry & 1) smr = op(query_sub(lx, rx, --ry), smr);
      ly >>= 1;
      ry >>= 1;
    }
    return op(sml, smr);
  }
  private:
  T query_sub(int lx, int rx, int y){
    T sml = id, smr = id;
    lx += w, rx += w;
    while(lx < rx){
      if(lx & 1) sml = op(sml, d[y][lx++]);
      if(rx & 1) smr = op(d[y][--rx], smr);
      lx >>= 1;
      rx >>= 1;
    }
    return op(sml, smr);
  }
  void updateX(int i, int j){
    d[i][j] = op(d[i][2*j], d[i][2*j+1]);
  }
  void updateY(int i, int j){
    d[i][j] = op(d[2*i][j], d[2*i+1][j]);
  }
};

int op(const int &a, const int &b){
  return a + b;
}