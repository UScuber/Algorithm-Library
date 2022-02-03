#include <bits/stdc++.h>
using namespace std;

template <class T>
struct Bit {
  Bit(int _n = 0) : n(_n), d(n){}
  Bit(const vector<T> &v) : d(v), n(v.size()){
    for(int i = 1; i <= n; i++){
      const int j = i + (i & -i);
      if(j <= n) d[j - 1] += d[i - 1];
    }
  }
  T sum(int l, int r) const{
    assert(0 <= l && l <= r && r <= n);
    return sum(r) - sum(l);
  }
  void add(int i, const T &x){
    assert(0 <= i && i < n);
    i++;
    while(i <= n){
      d[i - 1] += x;
      i += i & -i;
    }
  }
  private:
  int n = 1;
  vector<T> d;
  T sum(int i) const{
    T tot = 0;
    while(i > 0){
      tot += d[i - 1];
      i -= i & -i;
    }
    return tot;
  }
};