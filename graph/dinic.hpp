#include "template.hpp"

template<class T>
struct dinic {
  const T INF;
  struct edge {
    int to,rev;
    T cap;
    bool isrev;
    int idx;
  };

  int n;
  vector<vector<edge>> graph;
  vector<int> min_cost, iter;

  dinic(int n): INF(numeric_limits<T>::max()), graph(n), n(n){}

  void add_edge(int from, int to, T cap, int idx = -1){
    graph[from].emplace_back((edge){to, (int)graph[to].size(), cap, false, idx});
    graph[to].emplace_back((edge){from, (int)graph[from].size() - 1, 0, true, idx});
  }
  T max_flow(int s, int t){
    T flow = 0;
    while(bfs(s, t)){
      iter.assign(n, 0);
      T f = 0;
      while((f = dfs(s, t, INF)) > 0) flow += f;
    }
    return flow;
  }
  private:
  bool bfs(int s, int t){
    min_cost.assign(n, -1);
    queue<int> que;
    min_cost[s] = 0;
    que.push(s);
    while(!que.empty() && min_cost[t] == -1){
      int p = que.front();
      que.pop();
      for(auto &e : graph[p]){
        if(e.cap > 0 && min_cost[e.to] == -1){
          min_cost[e.to] = min_cost[p] + 1;
          que.push(e.to);
        }
      }
    }
    return min_cost[t] != -1;
  }
  T dfs(int idx, const int t, T flow){
    if(idx == t) return flow;
    for(int &i = iter[idx]; i < graph[idx].size(); i++){
      edge &e = graph[idx][i];
      if(e.cap > 0 && min_cost[idx] < min_cost[e.to]){
        T d = dfs(e.to, t, min(flow, e.cap));
        if(d > 0){
          e.cap -= d;
          graph[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
  public:
  void debug(){
    for(int i = 0; i < n; i++){
      for(auto &e : graph[i]){
        if(e.isrev) continue;
        auto &rev_e = graph[e.to][e.rev];
        cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
      }
    }
  }
};