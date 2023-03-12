template <class T>
vector<T> slide_min(const vector<T> &a, int k){
  int n = (int)a.size();
  deque<T> que;
  vector<T> res(n);
  for(int i = 0; i < n + k - 1; i++){
    while(!que.empty() && i < n && a[que.back()] >= a[i]){
      que.pop_back();
    }
    que.push_back(i);
    if(i - k + 1 >= 0){
      res[i - k + 1] = a[que.front()];
      if(que.front() == i - k + 1) que.pop_front();
    }
  }
  return res;
}