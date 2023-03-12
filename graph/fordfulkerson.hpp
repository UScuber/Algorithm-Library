template <class T>
struct maxflow {
  struct edge {
    int to,rev; T cap;
  };
  maxflow(int n) : n(n), G(n), used(n){}
  maxflow(const vector<vector<edge>> &g): n(g.size()), G(g){}
  void add_edge(int from, int to, T cap){
    G[from].push_back({to, (int)G[to].size(), cap});
    G[to].push_back({from, (int)G[from].size()-1, 0});
  }
  T max_flow(int s, int t){
    T flow = 0;
    while(true){
      used.assign(n, false);
      T f = dfs(s, t, mod);
      if(f == 0) return flow;
      flow += f;
    }
  }
  private:
  int n;
  vector<vector<edge>> G;
  vector<bool> used;

  T dfs(int v, int t, T f){
    if(v == t) return f;
    used[v] = true;
    for(edge &e : G[v]){
      if(!used[e.to] && e.cap > 0){
        T d = dfs(e.to, t, min(f, e.cap));
        if(d > 0){
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
};