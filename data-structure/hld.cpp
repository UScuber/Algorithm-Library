#include <bits/stdc++.h>
#include "../graph/template.hpp"
#include "../math/mint.hpp"
#include "../SegmentTree/segtree.hpp"
using namespace std;

template <class T, T(*op)(const T&,const T&), T(*rev_op)(const T&,const T&), T(*e)()>
struct HLD {
  graph root;
  int n, in_cnt = 0;
  vector<int> pre, sh, sz, p;
  SegmentTree<T,op,e> seg;
  SegmentTree<T,rev_op,e> rseg;
  HLD(const graph &g) : root(g), n(g.size()), pre(n), sh(n), sz(n), p(n), seg(n), rseg(n){
    size(0, -1);
    calc(0, -1, 0);
  }
  void size(int pos, int par){
    sz[pos] = 1;
    int mx = -1, idx = -1, cnt = -1;
    for(const int &x : root[pos]){
      cnt++;
      if(x == par) continue;
      size(x, pos);
      sz[pos] += sz[x];
      if(chmax(mx, sz[x])) idx = cnt;
    }
    if(idx != -1) swap(root[pos][0], root[pos][idx]);
  }
  void calc(int pos, int par, int v){
    p[pos] = in_cnt++;
    sh[pos] = v;
    pre[pos] = par;
    int cnt = -1;
    for(const int &x : root[pos]){
      cnt++;
      if(x == par) continue;
      if(cnt) calc(x, pos, x);
      else calc(x, pos, v);
    }
  }
  void set(int u, const T &x){
    seg.set(p[u], x);
    rseg.set(p[u], x);
  }
  void build(){
    seg.build();
    rseg.build();
  }

  void update(int u, const T &x){
    seg.update(p[u], x);
    rseg.update(p[u], x);
  }
  vector<pair<int,int>> query_path(int u, int v){
    vector<pair<int,int>> lef, rig;
    while(sh[u] != sh[v]){
      if(p[u] < p[v]){
        rig.emplace_back(p[sh[v]], p[v]);
        v = pre[sh[v]];
      }
      else{
        lef.emplace_back(p[u], p[sh[u]]);
        u = pre[sh[u]];
      }
    }
    if(p[u] < p[v]) rig.emplace_back(p[u], p[v]);
    else lef.emplace_back(p[u], p[v]);
    reverse(all(rig));
    lef.insert(lef.end(), all(rig));
    return lef;
  }
  T query(int u, int v){
    T res = e();
    for(const auto &x : query_path(u, v)){
      if(x.first <= x.second){
        res = op(res, seg.query(x.first, x.second+1));
      }else{
        res = op(res, rseg.query(x.second, x.first+1));
      }
    }
    return res;
  }
};

struct Data {
  mint a,b;
};
Data e(){
  return { 1, 0 };
}
Data op(const Data &l, const Data &m){
  return { l.a*m.a, l.b*m.a + m.b };
}
Data rev_op(const Data &l, const Data &m){
  return { m.a*l.a, m.b*l.a + l.b };
}
