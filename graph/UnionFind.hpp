struct UnionFind {
  private:
  int n;
  public:
  vector<int> d;
  UnionFind(int n): n(n), d(n, -1){}
  int root(int x){
    assert(0 <= x && x < n);
    if(d[x] < 0) return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y){
    x = root(x);
    y = root(y);
    if(x == y) return false;
    if(d[x] > d[y]) swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y){
    return root(x) == root(y);
  }
  int size(int x){
    return -d[root(x)];
  }
};
