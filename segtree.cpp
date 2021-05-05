#include <bits/stdc++.h>
using namespace std;

//seg min
template<class T> struct segmentTree{
  public:
  segmentTree(int x){
    while(x > n) n *= 2;
    d.resize(2*n - 1, inf);
  }
  void update(int k, T a){
    k += n - 1;
    d[k] = a;
    while(k > 0){
      k = (k - 1) / 2;
      d[k] = min(d[k * 2 + 1], d[k * 2 + 2]);
    }
  }
  void set(int i, T x){ d[i + n - 1] = x; }
  void build(){
    for(int k = n - 2; k >= 0; k--)
      d[k] = min(d[2 * k + 1], d[2 * k + 2]);
  }
  T query(int a, int b){ return query_sub(a, b, 0, 0, n); }
  int min_right(int a, int b, T x){ return find_rightest_sub(a, b, x, 0, 0, n); }
  int min_left(int a, int b, T x){ return min_left_sub(a, b, x, 0, 0, n); }
  
  private:
  const T inf = numeric_limits<T>::max();
  int n = 1;
  vector<T> d;
  T query_sub(int a, int b, int k, int l, int r){
    if(r <= a || b <= l) return inf;
    if(a <= l && r <= b) return d[k];
    T vlef = query_sub(a, b, k*2 + 1, l, (r+l)/2);
    T vrig = query_sub(a, b, k*2 + 2, (r+l)/2, r);
    return min(vlef, vrig);
  }
  //範囲外であればreturn a-1
  int min_right_sub(int a, int b, T x, int k, int l, int r){
    if(d[k] > x || r <= a || b <= l){
      return a - 1;
    }else if(k >= n - 1){
      return k - (n - 1);
    }else{
      int vrig = min_right_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
      if(vrig != a - 1){
        return vrig;
      }else{
        return min_right_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
      }
    }
  }
  //範囲外であればreturn b
  int min_left_sub(int a, int b, T x, int k, int l, int r){
    if (d[k] > x || r <= a || b <= l){
      return b;
    }else if(k >= n - 1) {
      return k - (n - 1);
    }else{
      int vlef = min_left_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
      if(vlef != b){
        return vlef;
      }else{
        return min_left_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
      }
    }
  }
};


//seg sum
template<class T> struct bit{
  public:
  bit(int x){
    while(x > n) n *= 2;
    d.resize(n);
  }
  T sum(int l, int r){
    return sum(r) - sum(l);
  }
  void add(int i, T x){
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