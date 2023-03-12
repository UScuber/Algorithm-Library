template <class graph>
struct scc {
  scc(const graph &g): root(g), n(g.size()){ init(); }
  void init(){
    rroot.resize(n);
    used.resize(n);
    ord.resize(n);
    comp.resize(n, -1);
    build();
  }
  void build(){
    for(int i = 0; i < n; i++){
      for(const auto &x : root[i])
        rroot[x].push_back(i);
    }
    for(int i = 0; i < n; i++) dfs(i);
    reverse(ord.begin(), ord.end());
    int cnt = 0;
    for(const auto &x : ord) if(comp[x] == -1){
      rdfs(x, cnt);
      cnt++;
    }
    dag.resize(cnt);
    group.resize(cnt);
    for(int i = 0; i < n; i++){
      for(const auto &x : root[i]){
        const int a = comp[i], b = comp[x];
        if(a == b) continue;
        dag[a].push_back(b);
      }
    }
    for(int i = 0; i < n; i++){
      group[comp[i]].push_back(i);
    }
  }
  int operator[](int i) const{
    return comp[i];
  }
  vector<vector<int>> group, dag;
  private:
  int n = 0;
  const graph &root;
  graph rroot; //rev
  vector<int> used, ord, comp;
  void dfs(int pos){
    if(used[pos]) return;
    used[pos] = 1;
    for(const auto &x : root[pos]) dfs(x);
    ord.push_back(pos);
  }
  void rdfs(int pos, const int cnt){
    if(comp[pos] != -1) return;
    comp[pos] = cnt;
    for(const auto &x : rroot[pos]) rdfs(x, cnt);
  }
};