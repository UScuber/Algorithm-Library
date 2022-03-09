#include <bits/stdc++.h>
using namespace std;

int value = 0;
struct Mo {
  struct Query { int l,r,b,idx; };
  vector<int> res;
  vector<Query> d;
  int width, n, q;
  Mo(int n, int q) : n(n), q(q), width(max(1.0, n/max(1.0, sqrt(q*2.0/3)))), res(q), d(q){}
  void insert(const int &l, const int &r){
    assert(0 <= l && l <= r && r <= n);
    static int idx = 0;
    d[idx] = { l, r, l / width, idx };
    idx++;
  }
  void build(){
    sort(d.begin(), d.end(), [&](const Query &a, const Query &b){
      if(a.b != b.b) return a.b < b.b;
      return (a.b & 1) ? a.r > b.r : a.r < b.r;
    });
    int nl = 0, nr = 0;
    for(const auto &v : d){
      while(nl > v.l) add_left(--nl);
      while(nr < v.r) add_right(nr++);
      while(nl < v.l) del_left(nl++);
      while(nr > v.r) del_right(--nr);
      res[v.idx] = value;
    }
  }
  void add_left(int p);
  void add_right(int p);
  void del_left(int p);
  void del_right(int p);
};
void Mo::add_left(int p){
  
}
void Mo::add_right(int p){

}
void Mo::del_left(int p){

}
void Mo::del_right(int p){

}