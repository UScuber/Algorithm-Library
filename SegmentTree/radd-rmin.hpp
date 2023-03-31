template <class T, const T&(*op)(const T&,const T&)>
struct LazySegmentTree {
  LazySegmentTree(const int _n) : n(_n){
    while((1 << log) < n) log++;
    len = 1 << log;
    d.assign(len * 2, 0);
    lazy.assign(len, 0);
  }
  void set(const int i, const T &x){
    assert(0 <= i && i < n);
    d[i + len] = x;
  }
  T get(int p){
    assert(0 <= p && p < n);
    p += len;
    for(int i = log; i >= 1; i--) push(p >> i);
    return d[p];
  }
  void build(){
    for(int i = len - 1; i >= 1; i--) update(i);
  }
  void update(int l, int r, const T &x){
    assert(0 <= l && l <= r && r <= n);
    l += len; r += len;
    const int l_ctz = __builtin_ctz(l);
    const int r_ctz = __builtin_ctz(r);
    for(int i = log; i > l_ctz; i--) push(l >> i);
    for(int i = log; i > r_ctz; i--) push((r - 1) >> i);
    const int lt = l, rt = r;
    while(l < r){
      if(l & 1) apply(l++, x);
      if(r & 1) apply(--r, x);
      l >>= 1; r >>= 1;
    }
    l = lt; r = rt;
    for(int i = l_ctz + 1; i <= log; i++) update(l >> i);
    for(int i = r_ctz + 1; i <= log; i++) update((r - 1) >> i);
  }
  T query(int l, int r){
    assert(0 <= l && l <= r && r <= n);
    l += len; r += len;
    const int l_ctz = __builtin_ctz(l);
    const int r_ctz = __builtin_ctz(r);
    for(int i = log; i > l_ctz; i--) push(l >> i);
    for(int i = log; i > r_ctz; i--) push((r - 1) >> i);
    T left = inf, right = inf;
    while(l < r){
      if(l & 1) left = op(left, d[l++]);
      if(r & 1) right = op(d[--r], right);
      l >>= 1; r >>= 1;
    }
    return op(left, right);
  }
  template <class G>
  int max_right(int l, G g){
    assert(0 <= l && l <= n);
    assert(g(inf));
    if(l == n) return n;
    l += len;
    for(int i = log; i >= 1; i--) push(l >> i);
    T sm = inf;
    do {
      l /= l & -l;
      if(!g(op(sm, d[l]))){
        while(l < len){
          push(l);
          l <<= 1;
          if(g(op(sm, d[l]))){
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
  template <class G>
  int min_left(int r, G g){
    assert(0 <= r && r <= n);
    assert(g(inf));
    if(r == 0) return 0;
    r += len;
    for(int i = log; i >= 1; i--) push((r - 1) >> i);
    T sm = inf;
    do {
      r /= r & -r;
      if(r > 1) r--;
      if(!g(op(d[r], sm))){
        while(r < len){
          push(r);
          r = r * 2 + 1;
          if(g(op(d[r], sm))){
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
  vector<T> d, lazy;
  int n = 1, log = 0, len = 0;
  const T inf = -op(numeric_limits<T>::max(), -numeric_limits<T>::max());
  inline void update(const int k){ d[k] = op(d[2*k], d[2*k+1]); }
  inline void apply(const int k, const T &x){
    d[k] += x;
    if(k < len) lazy[k] += x;
  }
  inline void push(const int k){
    if(!lazy[k]) return;
    apply(2*k, lazy[k]);
    apply(2*k+1, lazy[k]);
    lazy[k] = 0;
  }
};