template <class T>
struct UnionFindW {
  vector<int> par, rank;
  vector<T> diff_weight;

  UnionFindW(int n = 1, T sum_unity = 0) : n(n), par(n), rank(n), diff_weight(n){
    for(int i = 0; i < n; i++) par[i] = i, rank[i] = 0, diff_weight[i] = sum_unity;
  }
  int root(int x){
    assert(0 <= x && x < n);
    if(par[x] == x){
      return x;
    }else{
      const int r = root(par[x]);
      diff_weight[x] += diff_weight[par[x]];
      return par[x] = r;
    }
  }
  T weight(int x){
    root(x);
    return diff_weight[x];
  }
  bool same(int x, int y){
    return root(x) == root(y);
  }
  bool merge(int x, int y, T w){
    w += weight(x); w -= weight(y);
    x = root(x); y = root(y);
    if(x == y) return false;
    if(rank[x] < rank[y]) swap(x, y), w = -w;
    if(rank[x] == rank[y]) ++rank[x];
    par[y] = x;
    diff_weight[y] = w;
    return true;
  }
  T diff(int x, int y){
    return weight(y) - weight(x);
  }
  private:
  int n;
};