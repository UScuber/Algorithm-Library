template<class T, const T&(*op)(const T&,const T&)>
struct SegmentTree {
  SegmentTree(const int _n) : n(_n){
    while((1 << log) < n) log++;
    len = 1 << log;
    d.assign(len * 2, inf);
  }
  void update(int k, const T &x){
    assert(0 <= k && k < n);
    k += len;
    d[k] = x;
    while(k > 1){
      k >>= 1;
      d[k] = op(d[k*2], d[k*2+1]);
    }
  }
  void set(const int i, const T &x){
    assert(0 <= i && i < n);
    d[i + len] = x;
  }
  T get(const int i) const{
    assert(0 <= i && i < n);
    return d[i + len];
  }
  void build(){
    for(int k = len - 1; k >= 1; k--) d[k] = op(d[2*k], d[2*k+1]);
  }
  T query(int l, int r){
    assert(0 <= l && l <= r && r <= n);
    l += len; r += len;
    T left = inf, right = inf;
    while(l < r){
      if(l & 1) left = op(left, d[l++]);
      if(r & 1) right = op(d[--r], right);
      l >>= 1; r >>= 1;
    }
    return op(left, right);
  }
  template <class F>
  int max_right(int l, F f) const{
    assert(0 <= l && l <= n);
    assert(f(inf));
    if(l == n) return n;
    l += len;
    T sm = inf;
    do {
      l /= l & -l;
      if(!f(op(sm, d[l]))){
        while(l < len){
          l <<= 1;
          if(f(op(sm, d[l]))){
            sm = op(sm, d[l]);
            l++;
          }
        }
        return l - len;
      }
      sm = op(sm, d[l]);
      l++;
    }while(l & (l - 1));
    return n;
  }
  template <class F>
  int min_left(int r, F f) const{
    assert(0 <= r && r <= n);
    assert(f(inf));
    if(r == 0) return 0;
    r += len;
    T sm = inf;
    do {
      r /= r & -r;
      if(r > 1) r--;
      if(!f(op(d[r], sm))){
        while(r < len){
          r = r * 2 + 1;
          if(f(op(d[r], sm))){
            sm = op(d[r], sm);
            r--;
          }
        }
        return r + 1 - len;
      }
      sm = op(d[r], sm);
    }while(r & (r - 1));
    return 0;
  }
  private:
  const T inf = -op(numeric_limits<T>::max(), -numeric_limits<T>::max());
  int n = 1, log = 0, len = 0;
  vector<T> d;
};