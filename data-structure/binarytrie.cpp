#include <bits/stdc++.h>
using namespace std;

template<typename T, size_t MAX_DIGIT>
struct BinaryTrie {
  struct Node {
    size_t cnt;
    Node *prev, *left, *right;
    Node(Node *prev) : cnt(0), prev(prev), left(nullptr), right(nullptr){}
  };
  T lazy;
  Node *root;
  BinaryTrie() : lazy(0), root(emplace(nullptr)){}
  inline size_t get_count(Node *v){ return v ? v->cnt : 0; }
  // add and get value of Node
  void add(T val){
    lazy ^= val;
  }
  T get(Node *v){
    if(!v) return -1;
    T res = 0;
    for(int i = 0; i < MAX_DIGIT; i++){
      if(v == v->prev->right) res |= T(1) << i;
      v = v->prev;
    }
    return res ^ lazy;
  }

  // find Node* whose value is val
  Node *find(T val){
    T nval = val ^ lazy;
    Node *v = root;
    for(int i = MAX_DIGIT-1; i >= 0; i--){
      bool flag = nval >> i & 1;
      if(flag) v = v->right;
      else v = v->left;
      if(!v) return v;
    }
    return v;
  }
  // insert
  inline Node *emplace(Node *prev){
    return new Node(prev);
  }
  void insert(T val, size_t k = 1){
    T nval = val ^ lazy;
    Node *v = root;
    for(int i = MAX_DIGIT-1; i >= 0; i--){
      bool flag = nval >> i & 1;
      if(flag && !v->right) v->right = emplace(v);
      if(!flag && !v->left) v->left = emplace(v);
      if(flag) v = v->right;
      else v = v->left;
    }
    v->cnt += k;
    while(v = v->prev) v->cnt = get_count(v->left) + get_count(v->right);
  }
  // erase
  Node* clear(Node *v){
    if(!v || get_count(v)) return v;
    delete v;
    return nullptr;
  }
  bool erase(Node *v, size_t k = 1){
    if(!v) return false;
    v->cnt -= k;
    while(v = v->prev){
      v->left = clear(v->left);
      v->right = clear(v->right);
      v->cnt = get_count(v->left) + get_count(v->right);
    }
    return true;
  }
  bool erase(T val){
    auto v = find(val);
    return erase(v);
  }
  // max (with xor-addition of val) and min (with xor-addition of val)
  Node *get_max(T val = 0){
    T nval = val ^ lazy;
    Node *v = root;
    for(int i = MAX_DIGIT-1; i >= 0; i--){
      bool flag = nval >> i & 1;
      if(!v->right) v = v->left;
      else if(!v->left) v = v->right;
      else if(flag) v = v->left;
      else v = v->right;
    }
    return v;
  }
  Node *get_min(T val = 0){
    return get_max(~val & ((T(1) << MAX_DIGIT)-1));
  }
  // lower_bound, upper_bound
  Node *get_cur_node(Node *v, int i){
    if(!v) return v;
    Node *left = v->left, *right = v->right;
    if(lazy >> i & 1) swap(left, right);
    if(left) return get_cur_node(left, i+1);
    else if(right) return get_cur_node(right, i+1);
    return v;
  }
  Node *get_next_node(Node *v, int i){
    if(!v->prev) return nullptr;
    Node *left = v->prev->left, *right = v->prev->right;
    if(lazy >> (i+1) & 1) swap(left, right);
    if(v == left && right) return get_cur_node(right, i);
    else return get_next_node(v->prev, i+1);
  }
  Node *lower_bound(T val){
    T nval = val ^ lazy;
    Node *v = root;
    for(int i = MAX_DIGIT-1; i >= 0; i--){
      bool flag = nval >> i & 1;
      if(flag && v->right) v = v->right;
      else if(!flag && v->left) v = v->left;
      else if(val >> i & 1) return get_next_node(v, i);
      else return get_cur_node(v, i);
    }
    return v;
  }
  Node *upper_bound(T val){
    return lower_bound(val + 1);
  }
  size_t order_of_val(T val){
    Node *v = root;
    size_t res = 0;
    for(int i = MAX_DIGIT-1; i >= 0; i--){
      Node *left = v->left, *right = v->right;
      if(lazy >> i & 1) swap(left, right);
      bool flag = val >> i & 1;
      if(flag){
        res += get_count(left);
        v = right;
      }
      else v = left;
    }
    return res;
  }
  // k-th, k is 0-indexed
  Node *get_kth(size_t k, T val = 0){
    Node *v = root;
    if(get_count(v) <= k) return nullptr;
    for(int i = MAX_DIGIT-1; i >= 0; i--){
      bool flag = lazy >> i & 1;
      Node *left = (flag ? v->right : v->left);
      Node *right = (flag ? v->left : v->right);
      if(get_count(left) <= k) k -= get_count(left), v = right;
      else v = left;
    }
    return v;
  }
  // debug
  void print(Node *v, string prefix = ""){
    if(!v) return;
    cout << prefix << ": " << v->cnt << "\n";
    print(v->left, prefix + "0");
    print(v->right, prefix + "1");
  }
  void print(){ print(root); }
  vector<T> eval(Node *v, int digit){
    vector<T> res;
    if(!v) return res;
    if(!v->left && !v->right){
      for(int i = 0; i < get_count(v); i++) res.push_back(0);
      return res;
    }
    const auto &left = eval(v->left, digit-1);
    const auto &right = eval(v->right, digit-1);
    for(auto val : left) res.push_back(val);
    for(auto val : right) res.push_back(val + (T(1) << digit));
    return res;
  }
  vector<T> eval(){
    auto res = eval(root, MAX_DIGIT-1);
    for(auto &val : res) val ^= lazy;
    return res;
  }
};