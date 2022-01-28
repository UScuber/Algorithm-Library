#include <bits/stdc++.h>
using namespace std;

template <class T, const T&(*op)(const T&,const T&)>
struct SparseTable {
  int n;
  vector<T> a;
  private:
  vector<vector<T>> d;
  vector<int> len;
  T inf = numeric_limits<T>::max();
  public:
  SparseTable(int n) : n(n), a(n), len(n + 1){}
  SparseTable(const vector<T> &a) : a(a), n(a.size()), len(a.size() + 1){}
  T &operator[](const int &i){ return a[i]; }
  void build(){
    inf = -op(inf, -inf);
    int logn = 0;
    while((1 << logn) < n) logn++;
    d.resize(logn + 1, vector<T>(n, inf));
    d[0] = a;
    for(int i = 0; i < logn; i++){
      for(int j = 0; j <= n - (1 << i); j++){
        d[i + 1][j] = op(d[i][j], d[i][j + (1 << i)]);
      }
    }
    for(int i = 2; i <= n; i++) len[i] = len[i >> 1] + 1;
  }
  T query(int l, int r) const{
    assert(0 <= l && l <= r && r <= n);
    if(l == r) return inf;
    const int range = len[r - l];
    assert(0 <= range && range < d.size());
    return op(d[range][l], d[range][r - (1 << range)]);
  }
};