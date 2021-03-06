#include <bits/stdc++.h>
using namespace std;

//一つの値を加算、区間和

template<class T> struct bit{
  public:
  bit(int x){
    while(x > n) n *= 2;
    d.resize(n);
  }
  T sum(int l, int r){
    assert(0 <= l && l <= r && r <= n);
    return sum(r) - sum(l);
  }
  void add(int i, T x){
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
  T sum(int i){
    T tot = 0;
    while(i > 0){
      tot += d[i - 1];
      i -= i & -i;
    }
    return tot;
  }
};