template <class T, size_t MAX_DIGIT>
struct BinaryTrie {
  struct Node {
    int cnt = 0;
    T sum = 0;
    int ch[2] = { -1, -1 };
  };
  T lazy = 0;
  BinaryTrie() : root(1){}
  void xor_all(T x){ lazy ^= x; }
  void reserve(int s){ root.reserve(s); }
  void insert(T val, T xor_val = 0){ add(val, 1, xor_val); }
  void erase(T val, T xor_val = 0){ add(val, -1, xor_val); }
  void add(T val, int num, T xor_val = 0){
    const T nval = val ^ lazy ^ xor_val;
    int idx = 0;
    root[idx].cnt += num;
    root[idx].sum += val * num;
    for(int i = MAX_DIGIT-1; i >= 0; i--){
      const int f = nval >> i & 1;
      if(root[idx].ch[f] == -1){
        root[idx].ch[f] = (int)root.size();
        root.emplace_back(Node());
      }
      idx = root[idx].ch[f];
      root[idx].cnt += num;
      root[idx].sum += val * num;
    }
  }
  void clear(){
    root = { 0 };
    lazy = 0;
  }
  pair<T, T> kth_elem(int k, T xor_val = 0) const{
    xor_val ^= lazy;
    int idx = 0;
    T res = 0, tot = 0;
    for(int i = MAX_DIGIT-1; i >= 0; i--){
      const int f = xor_val >> i & 1;
      const int l = root[idx].ch[f];
      const int r = root[idx].ch[!f];
      if(l == -1 || root[l].cnt <= k){
        if(l != -1){
          k -= root[l].cnt;
          tot += root[l].sum;
        }
        idx = r;
        res |= T(1) << i;
      }else idx = l;
    }
    tot += res * (k + 1);
    return { res, tot };
  }
  int order(T val, T xor_val = 0) const{
    xor_val ^= lazy;
    int idx = 0, ord = 0;
    for(int i = MAX_DIGIT-1; i >= 0; i--){
      const int f = xor_val >> i & 1;
      const int l = root[idx].ch[f];
      const int r = root[idx].ch[!f];
      if(val >> i & 1){
        if(l != -1) ord += root[l].cnt;
        idx = r;
      }else idx = l;
      if(idx == -1) break;
    }
    return ord;
  }
  int count(T val) const{
    const int t = find(val);
    return t == -1 ? 0 : root[t].cnt;
  }
  int size() const{ return root.size(); }
  int num_size() const{ return root[0].cnt; }
  private:
  vector<Node> root;
  int find(T val, T xor_val = 0) const{
    const T nval = val ^ lazy ^ xor_val;
    int idx = 0;
    for(int i = MAX_DIGIT-1; i >= 0; i--){
      const int f = nval >> i & 1;
      if(root[idx].ch[f] == -1) return -1;
      idx = root[idx].ch[f];
    }
    return idx;
  }
};