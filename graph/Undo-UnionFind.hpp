struct UndoUnionFind {
  private:
  int n;
  stack<pair<int,int>> hist;
  public:
  vector<int> d;
  UndoUnionFind(int n): n(n), d(n, -1){}
  int root(int x){
    assert(0 <= x && x < n);
    if(d[x] < 0) return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y){
    x = root(x);
    y = root(y);
    hist.emplace(x, d[x]);
    hist.emplace(y, d[y]);
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
  void undo(){
    assert(!hist.empty());
    d[hist.top().first] = hist.top().second;
    hist.pop();
    d[hist.top().first] = hist.top().second;
    hist.pop();
  }
  void snapshot(){
    while(!hist.empty()) hist.pop();
  }
  void rollback(){
    while(!hist.empty()) undo();
  }
};