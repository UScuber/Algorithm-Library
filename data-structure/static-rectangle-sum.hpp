#include "../SegmentTree/BinaryIndexedTree.hpp"

template <class T, class F>
struct RectangleSum {
  struct Point {
    T y,x; F w;
    bool operator<(const Point &a) const{ return y < a.y; }
  };
  struct Query {
    T y,x, tx; //[x, tx)
    int idx = -1; bool add;
    bool operator<(const Query &a) const{ return y < a.y; }
  };
  vector<Query> query;
  vector<Point> ps;
  vector<T> posx;
  int idx = 0;
  RectangleSum(){}
  void add_point(const T &y, const T &x, const F &w){
    ps.emplace_back((Point){ y, x, w });
    posx.emplace_back(x);
  }
  void add_rect(const T &ly, const T &lx, const T &ry, const T &rx){
    query.emplace_back((Query){ ly, lx, rx, idx, 0 });
    query.emplace_back((Query){ ry, lx, rx, idx, 1 });
    idx++;
  }
  inline int get_pos(const T &x) const{
    return lower_bound(posx.begin(), posx.end(), x) - posx.begin();
  }
  vector<F> run(){
    sort(posx.begin(), posx.end());
    posx.erase(unique(posx.begin(), posx.end()), posx.end());
    sort(query.begin(), query.end());
    sort(ps.begin(), ps.end());
    int cur = 0;
    vector<F> ans(idx);
    BIT<F> seg(posx.size());
    for(const Query &que : query){
      while(cur != ps.size() && ps[cur].y < que.y){
        seg.add(get_pos(ps[cur].x), ps[cur].w);
        cur++;
      }
      int l = get_pos(que.x), r = get_pos(que.tx);
      const F v = seg.sum(l, r);
      if(que.add) ans[que.idx] += v;
      else ans[que.idx] -= v;
    }
    return ans;
  }
};