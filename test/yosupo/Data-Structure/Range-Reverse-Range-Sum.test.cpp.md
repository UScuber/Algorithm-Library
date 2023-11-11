---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/Treap.hpp
    title: data-structure/Treap.hpp
  - icon: ':question:'
    path: others/fastIO.hpp
    title: others/fastIO.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_reverse_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_reverse_range_sum
  bundledCode: "#line 1 \"test/yosupo/Data-Structure/Range-Reverse-Range-Sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_reverse_range_sum\"\n\
    \n#line 1 \"template/template.hpp\"\n#include <iostream>\r\n#include <cmath>\r\
    \n#include <string>\r\n#include <vector>\r\n#include <algorithm>\r\n#include <tuple>\r\
    \n#include <cstdint>\r\n#include <cstdio>\r\n#include <map>\r\n#include <queue>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <deque>\r\n#include <bitset>\r\
    \n#include <cctype>\r\n#include <climits>\r\n#include <functional>\r\n#include\
    \ <cassert>\r\n#include <numeric>\r\n#include <cstring>\r\n#define rep(i, n) for(int\
    \ i = 0; i < (n); i++)\r\n#define per(i, n) for(int i = (n) - 1; i >= 0; i--)\r\
    \nusing ll = long long;\r\n#define vi vector<int>\r\n#define vvi vector<vi>\r\n\
    #define vl vector<ll>\r\n#define pii pair<int, int>\r\n#define pll pair<ll, ll>\r\
    \n#define all(a) (a).begin(), (a).end()\r\n#define rall(a) (a).rbegin(), (a).rend()\r\
    \nconstexpr int mod = 1000000007;\r\nusing namespace std;\r\ntemplate<class T,\
    \ class U>\r\nbool chmax(T &a, const U &b){ return a < b ? (a = b, 1) : 0; }\r\
    \ntemplate<class T, class U>\r\nbool chmin(T &a, const U &b){ return a > b ? (a\
    \ = b, 1) : 0; }\n#line 4 \"test/yosupo/Data-Structure/Range-Reverse-Range-Sum.test.cpp\"\
    \n\n#line 1 \"data-structure/Treap.hpp\"\n#include <random>\n#include <chrono>\n\
    // T0: \u5143\u306E\u914D\u5217\u306E\u30E2\u30CE\u30A4\u30C9\n// T1: T0\u306B\
    \u5BFE\u3059\u308B\u4F5C\u7528\u7D20\u30E2\u30CE\u30A4\u30C9\ntemplate <class\
    \ T0, class T1>\nstruct BaseImplicitTreap {\nprivate:\n  virtual T0 f0(const T0\
    \ &, const T0 &) = 0;\n  const T0 u0;\n  virtual T1 f1(const T1 &, const T1 &)\
    \ = 0;\n  const T1 u1;\n  virtual T0 g(const T0 &, const T1 &) = 0;\n  virtual\
    \ T1 p(const T1 &, const int) = 0;\n\n  struct xorshift {\n    uint64_t x;\n \
    \   xorshift(){\n      mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());\n\
    \      x = rnd();\n      for(int i = 0; i < 100; i++){\n        random();\n  \
    \    }\n    }\n    uint64_t random(){\n      x = x ^ (x << 7);\n      return x\
    \ = x ^ (x >> 9);\n    }\n  } rnd;\n\n  struct Node {\n    T0 value, acc;\n  \
    \  T1 lazy;\n    int priority, cnt;\n    bool rev;\n    Node *l, *r;\n    Node(const\
    \ T0 &value_, const int priority_, const T0 &u0_, const T1 &u1_)\n        : value(value_),\
    \ acc(u0_), lazy(u1_), priority(priority_), cnt(1), rev(false), l(nullptr), r(nullptr){}\n\
    \  } *root = nullptr;\n\n  using Tree = Node *;\n\n  inline int cnt(Tree t) const\
    \ noexcept{ return t ? t->cnt : 0; }\n  inline T0 acc(Tree t) const noexcept{\
    \ return t ? t->acc : u0; }\n  void update_cnt(Tree t){\n    if(t) t->cnt = 1\
    \ + cnt(t->l) + cnt(t->r);\n  }\n  void update_acc(Tree t){\n    if(t) t->acc\
    \ = f0(acc(t->l), f0(t->value, acc(t->r)));\n  }\n  void pushup(Tree t){ update_cnt(t),\
    \ update_acc(t); }\n  void pushdown(Tree t){\n    if(t && t->rev){\n      t->rev\
    \ = false;\n      swap(t->l, t->r);\n      if(t->l) t->l->rev ^= 1;\n      if(t->r)\
    \ t->r->rev ^= 1;\n    }\n    if(t && t->lazy != u1){\n      if(t->l){\n     \
    \   t->l->lazy = f1(t->l->lazy, t->lazy);\n        t->l->acc = g(t->l->acc, p(t->lazy,\
    \ cnt(t->l)));\n      }\n      if(t->r){\n        t->r->lazy = f1(t->r->lazy,\
    \ t->lazy);\n        t->r->acc = g(t->r->acc, p(t->lazy, cnt(t->r)));\n      }\n\
    \      t->value = g(t->value, p(t->lazy, 1));\n      t->lazy = u1;\n    }\n  \
    \  pushup(t);\n  }\n  void split(Tree t, int key, Tree &l, Tree &r){\n    if(!t){\n\
    \      l = r = nullptr;\n      return;\n    }\n    pushdown(t);\n    int implicit_key\
    \ = cnt(t->l) + 1;\n    if(key < implicit_key){\n      split(t->l, key, l, t->l),\
    \ r = t;\n    }else{\n      split(t->r, key - implicit_key, t->r, r), l = t;\n\
    \    }\n    pushup(t);\n  }\n  void insert(Tree &t, int key, Tree item){\n   \
    \ Tree t1, t2;\n    split(t, key, t1, t2);\n    merge(t1, t1, item);\n    merge(t,\
    \ t1, t2);\n  }\n  void merge(Tree &t, Tree l, Tree r){\n    pushdown(l);\n  \
    \  pushdown(r);\n    if(!l || !r){\n      t = l ? l : r;\n    }else if(l->priority\
    \ > r->priority){\n      merge(l->r, l->r, r), t = l;\n    }else{\n      merge(r->l,\
    \ l, r->l), t = r;\n    }\n    pushup(t);\n  }\n  void erase(Tree &t, int key){\n\
    \    Tree t1, t2, t3;\n    split(t, key + 1, t1, t2);\n    split(t1, key, t1,\
    \ t3);\n    merge(t, t1, t2);\n  }\n  void update(Tree t, int l, int r, T1 x){\n\
    \    if(l >= r) return;\n    Tree t1, t2, t3;\n    split(t, l, t1, t2);\n    split(t2,\
    \ r - l, t2, t3);\n    t2->lazy = f1(t2->lazy, x);\n    t2->acc = g(t2->acc, p(x,\
    \ cnt(t2)));\n    merge(t2, t2, t3);\n    merge(t, t1, t2);\n  }\n  T0 query(Tree\
    \ t, int l, int r){\n    if(l == r) return u0;\n    Tree t1, t2, t3;\n    split(t,\
    \ l, t1, t2);\n    split(t2, r - l, t2, t3);\n    T0 ret = t2->acc;\n    merge(t2,\
    \ t2, t3);\n    merge(t, t1, t2);\n    return ret;\n  }\n  // [l, r)\u306E\u4E2D\
    \u3067\u5DE6\u304B\u3089\u4F55\u756A\u76EE\u304B\n  int find(Tree t, T0 x, int\
    \ offset, bool left = true){\n    if(f0(t->acc, x) == x){\n      return -1;\n\
    \    }else{\n      if(left){\n        if(t->l && f0(t->l->acc, x) != x){\n   \
    \       return find(t->l, x, offset, left);\n        }else{\n          return\
    \ (f0(t->value, x) != x) ? offset + cnt(t->l) : find(t->r, x, offset + cnt(t->l)\
    \ + 1, left);\n        }\n      }else{\n        if(t->r && f0(t->r->acc, x) !=\
    \ x){\n          return find(t->r, x, offset + cnt(t->l) + 1, left);\n       \
    \ }else{\n          return (f0(t->value, x) != x) ? offset + cnt(t->l) : find(t->l,\
    \ x, offset, left);\n        }\n      }\n    }\n  }\n  void reverse(Tree t, int\
    \ l, int r){\n    if(l >= r) return;\n    Tree t1, t2, t3;\n    split(t, l, t1,\
    \ t2);\n    split(t2, r - l, t2, t3);\n    t2->rev ^= 1;\n    merge(t2, t2, t3);\n\
    \    merge(t, t1, t2);\n  }\n  // [l, r)\u306E\u5148\u982D\u304Cm\u306B\u306A\u308B\
    \u3088\u3046\u306B\u30B7\u30D5\u30C8\u3055\u305B\u308B\u3002std::rotate\u3068\u540C\
    \u3058\u4ED5\u69D8\n  void rotate(Tree t, int l, int m, int r){\n    reverse(t,\
    \ l, r);\n    reverse(t, l, l + r - m);\n    reverse(t, l + r - m, r);\n  }\n\
    \  void dump(Tree t){\n    if(!t) return;\n    pushdown(t);\n    dump(t->l);\n\
    \    cout << t->value << \" \";\n    dump(t->r);\n  }\npublic:\n  BaseImplicitTreap(const\
    \ T0 &u0_, const T1 &u1_) : u0(u0_), u1(u1_){}\n  void set_by_vector(const vector<T0>\
    \ &a){\n    for(int i = 0; i < (int)a.size(); i++){\n      insert(i, a[i]);\n\
    \    }\n  }\n  int size(){ return cnt(root); }\n  void insert(int pos, const T0\
    \ &x){ insert(root, pos, new Node(x, rnd.random(), u0, u1)); }\n  void update(int\
    \ l, int r, const T1 &x){ update(root, l, r, x); }\n  T0 query(int l, int r){\
    \ return query(root, l, r); }\n  // \u4E8C\u5206\u63A2\u7D22\u3002[l, r)\u5185\
    \u306Ek\u3067f0(tr[k], x) != x\u3068\u306A\u308B\u6700\u5DE6/\u6700\u53F3\u306E\
    \u3082\u306E\u3002\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F-1\n  // \u305F\
    \u3068\u3048\u3070MinMonoid\u306E\u5834\u5408\u3001x\u672A\u6E80\u306E\u6700\u5DE6\
    /\u6700\u53F3\u306E\u8981\u7D20\u306E\u4F4D\u7F6E\u3092\u8FD4\u3059\n  int binary_search(int\
    \ l, int r, const T0 &x, bool left = true){\n    if(l >= r) return -1;\n    Tree\
    \ t1, t2, t3;\n    split(root, l, t1, t2);\n    split(t2, r - l, t2, t3);\n  \
    \  int ret = find(t2, x, l, left);\n    merge(t2, t2, t3);\n    merge(root, t1,\
    \ t2);\n    return ret;\n  }\n  void erase(int pos){ erase(root, pos); }\n  void\
    \ reverse(int l, int r){ reverse(root, l, r); }\n  void rotate(int l, int m, int\
    \ r){ rotate(root, l, m, r); }\n  void dump(){\n    dump(root);\n    cout << \"\
    \\n\";\n  }\n  T0 operator[](int pos){ return query(pos, pos + 1); }\n};\n\ntemplate\
    \ <class T0, class T1>\nstruct MinUpdateQuery : public BaseImplicitTreap<T0, T1>\
    \ {\n  using BaseImplicitTreap<T0, T1>::BaseImplicitTreap;\n  MinUpdateQuery()\
    \ : MinUpdateQuery(numeric_limits<T0>::max(), numeric_limits<T1>::min()){}\n \
    \ T0 f0(const T0 &x, const T0 &y) override{ return min(x, y); }\n  T1 f1(const\
    \ T1 &x, const T1 &y) override{ return y == numeric_limits<T1>::min() ? x : y;\
    \ }\n  T0 g(const T0 &x, const T1 &y) override{ return y == numeric_limits<T1>::min()\
    \ ? x : y; }\n  T1 p(const T1 &x, const int len) override{ return x; }\n};\n\n\
    template <class T0, class T1>\nstruct SumAddQuery : public BaseImplicitTreap<T0,\
    \ T1> {\n  using BaseImplicitTreap<T0, T1>::BaseImplicitTreap;\n  SumAddQuery()\
    \ : SumAddQuery(0, 0){}\n  T0 f0(const T0 &x, const T0 &y) override{ return x\
    \ + y; }\n  T1 f1(const T1 &x, const T1 &y) override{ return x + y; }\n  T0 g(const\
    \ T0 &x, const T1 &y) override{ return x + y; }\n  T1 p(const T1 &x, const int\
    \ len) override{ return x * len; }\n};\n\ntemplate <class T0, class T1>\nstruct\
    \ MinAddQuery : public BaseImplicitTreap<T0, T1> {\n  using BaseImplicitTreap<T0,\
    \ T1>::BaseImplicitTreap;\n  MinAddQuery() : MinAddQuery(numeric_limits<T0>::max(),\
    \ 0){}\n  T0 f0(const T0 &x, const T0 &y) override{ return min(x, y); }\n  T1\
    \ f1(const T1 &x, const T1 &y) override{ return x + y; }\n  T0 g(const T0 &x,\
    \ const T1 &y) override{ return x + y; }\n  T1 p(const T1 &x, const int len) override{\
    \ return x; }\n};\n\ntemplate <class T0, class T1>\nstruct SumUpdateQuery : public\
    \ BaseImplicitTreap<T0, T1> {\n  using BaseImplicitTreap<T0, T1>::BaseImplicitTreap;\n\
    \  SumUpdateQuery() : SumUpdateQuery(0, numeric_limits<T1>::min()){}\n  T0 f0(const\
    \ T0 &x, const T0 &y) override{ return x + y; }\n  T1 f1(const T1 &x, const T1\
    \ &y) override{ return y == numeric_limits<T1>::min() ? x : y; }\n  T0 g(const\
    \ T0 &x, const T1 &y) override{ return y == numeric_limits<T1>::min() ? x : y;\
    \ }\n  T1 p(const T1 &x, const int len) override{ return x == numeric_limits<T1>::min()\
    \ ? numeric_limits<T1>::min() : x * len; }\n};\n\ntemplate <class T0>\nstruct\
    \ SumAffineQuery : public BaseImplicitTreap<T0, pair<T0, T0>> {\n  using T1 =\
    \ pair<T0, T0>; // first * x + second\n  using BaseImplicitTreap<T0, T1>::BaseImplicitTreap;\n\
    \  SumAffineQuery() : SumAffineQuery(0, { 1, 0 }){}\n  T0 f0(const T0 &x, const\
    \ T0 &y) override{ return x + y; }\n  T1 f1(const T1 &x, const T1 &y) override{\
    \ return {x.first * y.first, x.second * y.first + y.second}; }\n  T0 g(const T0\
    \ &x, const T1 &y) override{ return y.first * x + y.second; }\n  T1 p(const T1\
    \ &x, const int len) override{ return {x.first, x.second * len}; }\n};\n\ntemplate\
    \ <class T>\nstruct MinmaxAffineQuery : public BaseImplicitTreap<pair<T, T>, pair<T,\
    \ T>> {\n  using T0 = pair<T, T>; // {min, max}\n  using T1 = pair<T, T>; // first\
    \ * x + second\n  using BaseImplicitTreap<T0, T1>::BaseImplicitTreap;\n  MinmaxAffineQuery()\
    \ : MinmaxAffineQuery({numeric_limits<T>::max(), -numeric_limits<T>::max()}, {\
    \ 1, 0 }){}\n  T0 f0(const T0 &x, const T0 &y) override{ return { min(x.first,\
    \ y.first), max(x.second, y.second) }; }\n  T1 f1(const T1 &x, const T1 &y) override{\
    \ return { x.first * y.first, x.second * y.first + y.second }; }\n  T0 g(const\
    \ T0 &x, const T1 &y) override{\n    T0 ret = { x.first * y.first + y.second,\
    \ x.second * y.first + y.second };\n    if(y.first < 0) swap(ret.first, ret.second);\n\
    \    return ret;\n  }\n  T1 p(const T1 &x, int len) override{ return x; }\n};\n\
    #line 1 \"others/fastIO.hpp\"\nnamespace FastIO {\r\nstruct PreCalc {\r\n  char\
    \ num[10000 * 4];\r\n  constexpr PreCalc() : num(){\r\n    for(int i = 0; i <\
    \ 10000; i++){\r\n      int t = i;\r\n      for(int j = 3; j >= 0; j--){\r\n \
    \       num[i*4 + j] = (t % 10) + '0';\r\n        t /= 10;\r\n      }\r\n    }\r\
    \n  }\r\n};\r\nstatic constexpr PreCalc pr;\r\nstruct FastIO {\r\n  template <class\
    \ T>\r\n  using enable_if_integer = enable_if_t<is_integral<T>::value || is_same<T,\
    \ __int128_t>::value || is_same<T, __uint128_t>::value>;\r\n  static constexpr\
    \ int buf_size = 1 << 20;\r\n  static constexpr int rem = 1 << 6;\r\n  char in_buf[buf_size],\
    \ *in_cur = in_buf + buf_size;\r\n  char out_buf[buf_size], *out_cur = out_buf;\r\
    \n  FastIO(){ load(); }\r\n  ~FastIO(){ flush(); }\r\n  void load(){\r\n    const\
    \ int len = in_buf + buf_size - in_cur;\r\n    memmove(in_buf, in_cur, len);\r\
    \n    in_cur = in_buf;\r\n    fread(in_buf + len, 1, buf_size - len, stdin);\r\
    \n  }\r\n  void flush(){\r\n    fwrite(out_buf, 1, out_cur - out_buf, stdout);\r\
    \n    out_cur = out_buf;\r\n  }\r\n  void through(){\r\n    if(in_cur - in_buf\
    \ >= buf_size - rem) load();\r\n    while(*in_cur <= ' ') in_cur++;\r\n    assert(in_buf\
    \ <= in_cur && in_cur < in_buf + buf_size);\r\n  }\r\n  #define gc() (*in_cur++)\r\
    \n  template <class T, enable_if_integer<T>* = nullptr>\r\n  inline void read(T\
    \ &x){\r\n    through();\r\n    bool neg = false;\r\n    int c = gc();\r\n   \
    \ if(c == '-') neg = true, c = gc();\r\n    x = c^'0'; c = gc();\r\n    while(c\
    \ >= '0' && c <= '9') x = x*10 + (c^'0'), c = gc();\r\n    if(neg) x = -x;\r\n\
    \  }\r\n  inline void read(string &x){\r\n    through();\r\n    x.clear();\r\n\
    \    while(true){\r\n      char *p = in_cur;\r\n      while(*p > ' ' && p - in_buf\
    \ < buf_size - rem) p++;\r\n      copy(in_cur, p, back_inserter(x));\r\n     \
    \ in_cur = p;\r\n      if(*p <= ' ') break;\r\n      load();\r\n    }\r\n  }\r\
    \n  inline void read(char &x){\r\n    through();\r\n    x = gc();\r\n  }\r\n \
    \ #undef gc\r\n  #define pc(c) *out_cur++ = (c)\r\n  template <class T, enable_if_integer<T>*\
    \ = nullptr>\r\n  inline void out(T x){\r\n    static constexpr int tmp_size =\
    \ sizeof(T)*5/2;\r\n    static char tmp[tmp_size];\r\n    if(out_cur - out_buf\
    \ >= buf_size - rem) flush();\r\n    if(!x){ pc('0'); return; }\r\n    if(x <\
    \ 0){ pc('-'); x = -x; }\r\n    int idx = tmp_size;\r\n    while(x >= 10000){\r\
    \n      idx -= 4;\r\n      memcpy(tmp + idx, pr.num + (x % 10000)*4, 4);\r\n \
    \     x /= 10000;\r\n    }\r\n    if(x < 100){\r\n      if(x < 10){\r\n      \
    \  pc(x + '0');\r\n      }else{\r\n        pc(x/10 + '0');\r\n        pc(x%10\
    \ + '0');\r\n      }\r\n    }else{\r\n      if(x < 1000){\r\n        memcpy(out_cur,\
    \ pr.num + x*4 + 1, 3);\r\n        out_cur += 3;\r\n      }else{\r\n        memcpy(out_cur,\
    \ pr.num + x*4, 4);\r\n        out_cur += 4;\r\n      }\r\n    }\r\n    memcpy(out_cur,\
    \ tmp + idx, tmp_size - idx);\r\n    out_cur += tmp_size - idx;\r\n  }\r\n  inline\
    \ void out(const string &s){\r\n    flush();\r\n    fwrite(s.c_str(), 1, s.size(),\
    \ stdout);\r\n  }\r\n  inline void out(const char c){\r\n    if(out_cur - out_buf\
    \ >= buf_size - rem) flush();\r\n    pc(c);\r\n  }\r\n  #undef pc\r\n  template\
    \ <class T>\r\n  friend FastIO &operator>>(FastIO &io, T &x){\r\n    io.read(x);\r\
    \n    return io;\r\n  }\r\n  template <class T>\r\n  friend FastIO &operator<<(FastIO\
    \ &io, const T &x){\r\n    io.out(x);\r\n    return io;\r\n  }\r\n};\r\nFastIO\
    \ io;\r\n} // namespace FastIO\r\nusing FastIO::io;\r\n#define cin io\r\n#define\
    \ cout io\n#line 7 \"test/yosupo/Data-Structure/Range-Reverse-Range-Sum.test.cpp\"\
    \n\nint main(){\n  int n,q;\n  cin >> n >> q;\n  SumAddQuery<ll,ll> tr;\n  rep(i,\
    \ n){\n    int a;\n    cin >> a;\n    tr.insert(i, a);\n  }\n  rep(_, q){\n  \
    \  int t,l,r;\n    cin >> t >> l >> r;\n    if(t == 0){\n      tr.reverse(l, r);\n\
    \    }else{\n      cout << tr.query(l, r) << '\\n';\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_reverse_range_sum\"\
    \n\n#include \"../../../template/template.hpp\"\n\n#include \"../../../data-structure/Treap.hpp\"\
    \n#include \"../../../others/fastIO.hpp\"\n\nint main(){\n  int n,q;\n  cin >>\
    \ n >> q;\n  SumAddQuery<ll,ll> tr;\n  rep(i, n){\n    int a;\n    cin >> a;\n\
    \    tr.insert(i, a);\n  }\n  rep(_, q){\n    int t,l,r;\n    cin >> t >> l >>\
    \ r;\n    if(t == 0){\n      tr.reverse(l, r);\n    }else{\n      cout << tr.query(l,\
    \ r) << '\\n';\n    }\n  }\n}"
  dependsOn:
  - template/template.hpp
  - data-structure/Treap.hpp
  - others/fastIO.hpp
  isVerificationFile: true
  path: test/yosupo/Data-Structure/Range-Reverse-Range-Sum.test.cpp
  requiredBy: []
  timestamp: '2023-11-12 01:15:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Data-Structure/Range-Reverse-Range-Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Data-Structure/Range-Reverse-Range-Sum.test.cpp
- /verify/test/yosupo/Data-Structure/Range-Reverse-Range-Sum.test.cpp.html
title: test/yosupo/Data-Structure/Range-Reverse-Range-Sum.test.cpp
---
