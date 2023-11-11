---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/bitvector.hpp
    title: data-structure/bitvector.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/wavelet-matrix-comp.hpp
    title: data-structure/wavelet-matrix-comp.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/wavelet-matrix.hpp
    title: data-structure/wavelet-matrix.hpp
  - icon: ':heavy_check_mark:'
    path: others/fastIO.hpp
    title: others/fastIO.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"test/yosupo/Data-Structure/Range-Kth-Smallest.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n#line\
    \ 1 \"template/template.hpp\"\n#include <iostream>\r\n#include <cmath>\r\n#include\
    \ <string>\r\n#include <vector>\r\n#include <algorithm>\r\n#include <tuple>\r\n\
    #include <cstdint>\r\n#include <cstdio>\r\n#include <map>\r\n#include <queue>\r\
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
    \ = b, 1) : 0; }\n#line 4 \"test/yosupo/Data-Structure/Range-Kth-Smallest.test.cpp\"\
    \n\n#line 1 \"data-structure/bitvector.hpp\"\nstruct BitVector {\r\n  using uint\
    \ = unsigned int;\r\n  static constexpr int w = 32;\r\n  #define rem(k) ((k) &\
    \ (w - 1))\r\n  int len, blocks;\r\n  vector<uint> bit, sum;\r\n  BitVector(){}\r\
    \n  BitVector(const int len) : len(len), blocks((len+w-1)/w){\r\n    bit.assign(blocks,\
    \ 0);\r\n    sum.assign(blocks, 0);\r\n  }\r\n  inline void set(const int k, const\
    \ int b = 1) noexcept{\r\n    if(b) bit[k / w] |= 1U << rem(k);\r\n    else bit[k\
    \ / w] &= ~(1U << rem(k));\r\n  }\r\n  void build(){\r\n    sum[0] = 0;\r\n  \
    \  for(int i = 1; i < blocks; i++){\r\n      sum[i] = sum[i - 1] + __builtin_popcount(bit[i\
    \ - 1]);\r\n    }\r\n  }\r\n  int operator[](const int k) const{\r\n    return\
    \ bit[k / w] >> rem(k) & 1;\r\n  }\r\n  inline int rank(const int k) const noexcept{\r\
    \n    return sum[k / w] + __builtin_popcount(bit[k / w] & ((1U << rem(k)) - 1));\r\
    \n  }\r\n  inline int rank(const int val, const int k) const noexcept{\r\n   \
    \ return val ? rank(k) : k - rank(k);\r\n  }\r\n  #undef rem\r\n};\n#line 2 \"\
    data-structure/wavelet-matrix.hpp\"\n\r\n//----- Wavelet Matrix -----\r\n\r\n\
    template <class T, int maxlog, bool USE_SUM = false>\r\nstruct WaveletMatrix {\r\
    \n  int len;\r\n  BitVector matrix[maxlog];\r\n  int mid[maxlog];\r\n  vector<T>\
    \ sum[maxlog];\r\n  WaveletMatrix(){}\r\n  WaveletMatrix(vector<T> v) : len(v.size()){\r\
    \n    vector<T> l(len), r(len);\r\n\t\tfill(matrix, matrix + maxlog, BitVector(len\
    \ + 1));\r\n    if(USE_SUM) fill(sum, sum + maxlog, vector<T>(len + 1));\r\n \
    \   for(int level = maxlog - 1; level >= 0; level--){\r\n      int left = 0, right\
    \ = 0;\r\n      for(int i = 0; i < len; i++){\r\n        if(v[i] >> level & 1){\r\
    \n          matrix[level].set(i);\r\n          r[right++] = v[i];\r\n        }else{\r\
    \n          l[left++] = v[i];\r\n        }\r\n      }\r\n      mid[level] = left;\r\
    \n      matrix[level].build();\r\n      v.swap(l);\r\n      copy(r.begin(), r.begin()\
    \ + right, v.begin() + left);\r\n      if(USE_SUM){\r\n        sum[level][0] =\
    \ 0;\r\n        for(int i = 0; i < len; i++){\r\n          sum[level][i + 1] =\
    \ sum[level][i] + v[i];\r\n        }\r\n      }\r\n    }\r\n  }\r\n  inline int\
    \ succ(const int f, const int l, const int level) const{\r\n    return matrix[level].rank(f,\
    \ l) + mid[level] * f;\r\n  }\r\n  //find v[k]\r\n  T access(int k) const{\r\n\
    \    assert(0 <= k && k < len);\r\n    T res = 0;\r\n    for(int level = maxlog\
    \ - 1; level >= 0; level--){\r\n      const bool f = matrix[level][k];\r\n   \
    \   if(f) res |= T(1) << level;\r\n      k = matrix[level].rank(f, k) + mid[level]*f;\r\
    \n    }\r\n    return res;\r\n  }\r\n  T operator[](const int k) const{ return\
    \ access(k); }\r\n  // count i  (0 <= i < r) && v[i] == x\r\n  int rank(const\
    \ T x, int r) const{\r\n    assert(0 <= r && r <= len);\r\n    int l = 0;\r\n\
    \    for(int level = maxlog - 1; level >= 0; level--){\r\n      l = succ(x >>\
    \ level & 1, l, level);\r\n      r = succ(x >> level & 1, r, level);\r\n    }\r\
    \n    return r - l;\r\n  }\r\n  //k-th value v[l,r)\r\n  T kth_smallest(int l,\
    \ int r, int k) const{\r\n    assert(0 <= l && l <= r && r <= len);\r\n    assert(0\
    \ <= k && k < r - l);\r\n    T res = 0;\r\n    for(int level = maxlog - 1; level\
    \ >= 0; level--){\r\n      int cnt = matrix[level].rank(0, r) - matrix[level].rank(0,\
    \ l);\r\n      bool f = cnt <= k;\r\n      if(f){\r\n        res |= T(1) << level;\r\
    \n        k -= cnt;\r\n      }\r\n      l = succ(f, l, level);\r\n      r = succ(f,\
    \ r, level);\r\n    }\r\n    return res;\r\n  }\r\n  T kth_largest(int l, int\
    \ r, int k) const{\r\n    return kth_smallest(l, r, r-l-k-1);\r\n  }\r\n  // sum\
    \ of [0,k)th smallest elements([l, r))\r\n  T kth_smallest_sum(int l, int r, int\
    \ k) const{\r\n    assert(0 <= l && l <= r && r <= len);\r\n    assert(0 <= k\
    \ && k <= r - l);\r\n    assert(USE_SUM);\r\n    T res = 0;\r\n    for(int level\
    \ = maxlog - 1; level >= 0; level--){\r\n      const int l0 = matrix[level].rank(0,\
    \ l);\r\n      const int r0 = matrix[level].rank(0, r);\r\n      if(k < r0 - l0){\r\
    \n        l = l0, r = r0;\r\n      }else{\r\n        k -= r0 - l0;\r\n       \
    \ res += sum[level][r0] - sum[level][l0];\r\n        l += mid[level] - l0;\r\n\
    \        r += mid[level] - r0;\r\n      }\r\n    }\r\n    if(k) res += sum[0][l\
    \ + k] - sum[0][l];\r\n    return res;\r\n  }\r\n  // sum of [0,k)th largest elements([l,\
    \ r))\r\n  T kth_largest_sum(int l, int r, int k) const{\r\n    assert(0 <= l\
    \ && l <= r && r <= len);\r\n    assert(0 <= k && k <= r - l);\r\n    assert(USE_SUM);\r\
    \n    return  kth_smallest_sum(l, r, r - l) - kth_smallest_sum(l, r, r - l - k);\r\
    \n  }\r\n  // count i  (l <= i < r), (v[i] < upper)\r\n  int range_freq(int l,\
    \ int r, const T upper) const{\r\n    int res = 0;\r\n    for(int level = maxlog\
    \ - 1; level >= 0; level--){\r\n      bool f = upper >> level & 1;\r\n      if(f)\
    \ res += matrix[level].rank(0, r) - matrix[level].rank(0, l);\r\n      l = succ(f,\
    \ l, level);\r\n      r = succ(f, r, level);\r\n    }\r\n    return res;\r\n \
    \ }\r\n  // count i  (l <= i < r), (lower <= v[i] < upper)\r\n  int range_freq(int\
    \ l, int r, const T lower, const T upper) const{\r\n    assert(0 <= l && l <=\
    \ r && r <= len);\r\n    return range_freq(l, r, upper) - range_freq(l, r, lower);\r\
    \n  }\r\n  // max v[i]  (l <= i < r), (v[i] < upper)\r\n  T prev_value(int l,\
    \ int r, const T upper) const{\r\n    assert(0 <= l && l <= r && r <= len);\r\n\
    \    int cnt = range_freq(l, r, upper);\r\n    return cnt == 0 ? -1 : kth_smallest(l,\
    \ r, cnt - 1);\r\n  }\r\n  // min v[i]  (l <= i < r), (lower <= v[i])\r\n  T next_value(int\
    \ l, int r, const T lower) const{\r\n    assert(0 <= l && l <= r && r <= len);\r\
    \n    int cnt = range_freq(l, r, lower);\r\n    return cnt == r - l ? -1 : kth_smallest(l,\
    \ r, cnt);\r\n  }\r\n};\n#line 2 \"data-structure/wavelet-matrix-comp.hpp\"\n\r\
    \n//----- Compressed Wavelet Matrix -----\r\n\r\ntemplate <class T, int maxlog,\
    \ bool USE_SUM = false>\r\nstruct WaveletMatrixComp {\r\n  int len;\r\n  BitVector\
    \ matrix[maxlog];\r\n  int mid[maxlog];\r\n  vector<T> sum[maxlog];\r\n  vector<T>\
    \ d;\r\n  WaveletMatrixComp(){}\r\n  WaveletMatrixComp(const vector<T> &data)\
    \ : len(data.size()), d(data){\r\n    sort(d.begin(), d.end());\r\n    d.erase(unique(d.begin(),\
    \ d.end()), d.end());\r\n    vector<int> v(len);\r\n    for(int i = 0; i < len;\
    \ i++) v[i] = get_pos(data[i]);\r\n    vector<int> l(len), r(len);\r\n\t\tfill(matrix,\
    \ matrix + maxlog, BitVector(len + 1));\r\n    if(USE_SUM) fill(sum, sum + maxlog,\
    \ vector<T>(len + 1));\r\n    for(int level = maxlog - 1; level >= 0; level--){\r\
    \n      int left = 0, right = 0;\r\n      for(int i = 0; i < len; i++){\r\n  \
    \      if(v[i] >> level & 1){\r\n          matrix[level].set(i);\r\n         \
    \ r[right++] = v[i];\r\n        }else{\r\n          l[left++] = v[i];\r\n    \
    \    }\r\n      }\r\n      mid[level] = left;\r\n      matrix[level].build();\r\
    \n      v.swap(l);\r\n      copy(r.begin(), r.begin() + right, v.begin() + left);\r\
    \n      if(USE_SUM){\r\n        sum[level][0] = 0;\r\n        for(int i = 0; i\
    \ < len; i++){\r\n          sum[level][i + 1] = sum[level][i] + d[v[i]];\r\n \
    \       }\r\n      }\r\n    }\r\n  }\r\n  inline int get_pos(const T x) const{\r\
    \n\t\treturn lower_bound(d.begin(), d.end(), x) - d.begin();\r\n\t}\r\n  inline\
    \ int succ(const int f, const int l, const int level) const{\r\n    return matrix[level].rank(f,\
    \ l) + mid[level] * f;\r\n  }\r\n  //find v[k]\r\n  T access(int k) const{\r\n\
    \    assert(0 <= k && k < len);\r\n    T res = 0;\r\n    for(int level = maxlog\
    \ - 1; level >= 0; level--){\r\n      const bool f = matrix[level][k];\r\n   \
    \   if(f) res |= T(1) << level;\r\n      k = matrix[level].rank(f, k) + mid[level]*f;\r\
    \n    }\r\n    return d[res];\r\n  }\r\n  T operator[](const int k) const{ return\
    \ access(k); }\r\n  // count i  (0 <= i < r) && v[i] == x\r\n  int rank(const\
    \ T x, int r) const{\r\n    assert(0 <= r && r <= len);\r\n    const int pos =\
    \ get_pos(x);\r\n    if(pos >= (int)d.size() || d[pos] != x) return 0;\r\n   \
    \ int l = 0;\r\n    for(int level = maxlog - 1; level >= 0; level--){\r\n    \
    \  l = succ(pos >> level & 1, l, level);\r\n      r = succ(pos >> level & 1, r,\
    \ level);\r\n    }\r\n    return r - l;\r\n  }\r\n  //k-th value v[l,r)\r\n  T\
    \ kth_smallest(int l, int r, int k) const{\r\n    assert(0 <= l && l <= r && r\
    \ <= len);\r\n    assert(0 <= k && k < r - l);\r\n    T res = 0;\r\n    for(int\
    \ level = maxlog - 1; level >= 0; level--){\r\n      int cnt = matrix[level].rank(0,\
    \ r) - matrix[level].rank(0, l);\r\n      bool f = cnt <= k;\r\n      if(f){\r\
    \n        res |= T(1) << level;\r\n        k -= cnt;\r\n      }\r\n      l = succ(f,\
    \ l, level);\r\n      r = succ(f, r, level);\r\n    }\r\n    return d[res];\r\n\
    \  }\r\n  T kth_largest(int l, int r, int k) const{\r\n    return kth_smallest(l,\
    \ r, r-l-k-1);\r\n  }\r\n  // sum of [0,k)th smallest elements([l, r))\r\n  T\
    \ kth_smallest_sum(int l, int r, int k) const{\r\n    assert(0 <= l && l <= r\
    \ && r <= len);\r\n    assert(0 <= k && k <= r - l);\r\n    assert(USE_SUM);\r\
    \n    T res = 0;\r\n    for(int level = maxlog - 1; level >= 0; level--){\r\n\
    \      const int l0 = matrix[level].rank(0, l);\r\n      const int r0 = matrix[level].rank(0,\
    \ r);\r\n      if(k < r0 - l0){\r\n        l = l0, r = r0;\r\n      }else{\r\n\
    \        k -= r0 - l0;\r\n        res += sum[level][r0] - sum[level][l0];\r\n\
    \        l += mid[level] - l0;\r\n        r += mid[level] - r0;\r\n      }\r\n\
    \    }\r\n    if(k) res += sum[0][l + k] - sum[0][l];\r\n    return res;\r\n \
    \ }\r\n  // sum of [0,k)th largest elements([l, r))\r\n  T kth_largest_sum(int\
    \ l, int r, int k) const{\r\n    assert(0 <= l && l <= r && r <= len);\r\n   \
    \ assert(0 <= k && k <= r - l);\r\n    assert(USE_SUM);\r\n    return  kth_smallest_sum(l,\
    \ r, r - l) - kth_smallest_sum(l, r, r - l - k);\r\n  }\r\n  // count i  (l <=\
    \ i < r), (v[i] < upper)\r\n  int range_freq(int l, int r, const T upper) const{\r\
    \n    const int pos = get_pos(upper);\r\n    int res = 0;\r\n    for(int level\
    \ = maxlog - 1; level >= 0; level--){\r\n      bool f = pos >> level & 1;\r\n\
    \      if(f) res += matrix[level].rank(0, r) - matrix[level].rank(0, l);\r\n \
    \     l = succ(f, l, level);\r\n      r = succ(f, r, level);\r\n    }\r\n    return\
    \ d[res];\r\n  }\r\n  // count i  (l <= i < r), (lower <= v[i] < upper)\r\n  int\
    \ range_freq(int l, int r, const T lower, const T upper) const{\r\n    assert(0\
    \ <= l && l <= r && r <= len);\r\n    return range_freq(l, r, upper) - range_freq(l,\
    \ r, lower);\r\n  }\r\n  // max v[i]  (l <= i < r), (v[i] < upper)\r\n  T prev_value(int\
    \ l, int r, const T upper) const{\r\n    assert(0 <= l && l <= r && r <= len);\r\
    \n    int cnt = range_freq(l, r, upper);\r\n    return cnt == 0 ? -1 : kth_smallest(l,\
    \ r, cnt - 1);\r\n  }\r\n  // min v[i]  (l <= i < r), (lower <= v[i])\r\n  T next_value(int\
    \ l, int r, const T lower) const{\r\n    assert(0 <= l && l <= r && r <= len);\r\
    \n    int cnt = range_freq(l, r, lower);\r\n    return cnt == r - l ? -1 : kth_smallest(l,\
    \ r, cnt);\r\n  }\r\n};\n#line 1 \"others/fastIO.hpp\"\nnamespace FastIO {\r\n\
    struct PreCalc {\r\n  char num[10000 * 4];\r\n  constexpr PreCalc() : num(){\r\
    \n    for(int i = 0; i < 10000; i++){\r\n      int t = i;\r\n      for(int j =\
    \ 3; j >= 0; j--){\r\n        num[i*4 + j] = (t % 10) + '0';\r\n        t /= 10;\r\
    \n      }\r\n    }\r\n  }\r\n};\r\nstatic constexpr PreCalc pr;\r\nstruct FastIO\
    \ {\r\n  template <class T>\r\n  using enable_if_integer = enable_if_t<is_integral<T>::value\
    \ || is_same<T, __int128_t>::value || is_same<T, __uint128_t>::value>;\r\n  static\
    \ constexpr int buf_size = 1 << 20;\r\n  static constexpr int rem = 1 << 6;\r\n\
    \  char in_buf[buf_size], *in_cur = in_buf + buf_size;\r\n  char out_buf[buf_size],\
    \ *out_cur = out_buf;\r\n  FastIO(){ load(); }\r\n  ~FastIO(){ flush(); }\r\n\
    \  void load(){\r\n    const int len = in_buf + buf_size - in_cur;\r\n    memmove(in_buf,\
    \ in_cur, len);\r\n    in_cur = in_buf;\r\n    fread(in_buf + len, 1, buf_size\
    \ - len, stdin);\r\n  }\r\n  void flush(){\r\n    fwrite(out_buf, 1, out_cur -\
    \ out_buf, stdout);\r\n    out_cur = out_buf;\r\n  }\r\n  void through(){\r\n\
    \    if(in_cur - in_buf >= buf_size - rem) load();\r\n    while(*in_cur <= ' ')\
    \ in_cur++;\r\n    assert(in_buf <= in_cur && in_cur < in_buf + buf_size);\r\n\
    \  }\r\n  #define gc() (*in_cur++)\r\n  template <class T, enable_if_integer<T>*\
    \ = nullptr>\r\n  inline void read(T &x){\r\n    through();\r\n    bool neg =\
    \ false;\r\n    int c = gc();\r\n    if(c == '-') neg = true, c = gc();\r\n  \
    \  x = c^'0'; c = gc();\r\n    while(c >= '0' && c <= '9') x = x*10 + (c^'0'),\
    \ c = gc();\r\n    if(neg) x = -x;\r\n  }\r\n  inline void read(string &x){\r\n\
    \    through();\r\n    x.clear();\r\n    while(true){\r\n      char *p = in_cur;\r\
    \n      while(*p > ' ' && p - in_buf < buf_size - rem) p++;\r\n      copy(in_cur,\
    \ p, back_inserter(x));\r\n      in_cur = p;\r\n      if(*p <= ' ') break;\r\n\
    \      load();\r\n    }\r\n  }\r\n  inline void read(char &x){\r\n    through();\r\
    \n    x = gc();\r\n  }\r\n  #undef gc\r\n  #define pc(c) *out_cur++ = (c)\r\n\
    \  template <class T, enable_if_integer<T>* = nullptr>\r\n  inline void out(T\
    \ x){\r\n    static constexpr int tmp_size = sizeof(T)*5/2;\r\n    static char\
    \ tmp[tmp_size];\r\n    if(out_cur - out_buf >= buf_size - rem) flush();\r\n \
    \   if(!x){ pc('0'); return; }\r\n    if(x < 0){ pc('-'); x = -x; }\r\n    int\
    \ idx = tmp_size;\r\n    while(x >= 10000){\r\n      idx -= 4;\r\n      memcpy(tmp\
    \ + idx, pr.num + (x % 10000)*4, 4);\r\n      x /= 10000;\r\n    }\r\n    if(x\
    \ < 100){\r\n      if(x < 10){\r\n        pc(x + '0');\r\n      }else{\r\n   \
    \     pc(x/10 + '0');\r\n        pc(x%10 + '0');\r\n      }\r\n    }else{\r\n\
    \      if(x < 1000){\r\n        memcpy(out_cur, pr.num + x*4 + 1, 3);\r\n    \
    \    out_cur += 3;\r\n      }else{\r\n        memcpy(out_cur, pr.num + x*4, 4);\r\
    \n        out_cur += 4;\r\n      }\r\n    }\r\n    memcpy(out_cur, tmp + idx,\
    \ tmp_size - idx);\r\n    out_cur += tmp_size - idx;\r\n  }\r\n  inline void out(const\
    \ string &s){\r\n    flush();\r\n    fwrite(s.c_str(), 1, s.size(), stdout);\r\
    \n  }\r\n  inline void out(const char c){\r\n    if(out_cur - out_buf >= buf_size\
    \ - rem) flush();\r\n    pc(c);\r\n  }\r\n  #undef pc\r\n  template <class T>\r\
    \n  friend FastIO &operator>>(FastIO &io, T &x){\r\n    io.read(x);\r\n    return\
    \ io;\r\n  }\r\n  template <class T>\r\n  friend FastIO &operator<<(FastIO &io,\
    \ const T &x){\r\n    io.out(x);\r\n    return io;\r\n  }\r\n};\r\nFastIO io;\r\
    \n} // namespace FastIO\r\nusing FastIO::io;\r\n#define cin io\r\n#define cout\
    \ io\n#line 7 \"test/yosupo/Data-Structure/Range-Kth-Smallest.test.cpp\"\n\nint\
    \ main(){\n  int n,q;\n  cin >> n >> q;\n  vi a(n);\n  rep(i, n) cin >> a[i];\n\
    \  WaveletMatrixComp<int,19> mat(move(a));\n  int l,r,k;\n  while(q--){\n    cin\
    \ >> l >> r >> k;\n    cout << mat.kth_smallest(l, r, k) << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include \"../../../template/template.hpp\"\n\n#include \"../../../data-structure/wavelet-matrix-comp.hpp\"\
    \n#include \"../../../others/fastIO.hpp\"\n\nint main(){\n  int n,q;\n  cin >>\
    \ n >> q;\n  vi a(n);\n  rep(i, n) cin >> a[i];\n  WaveletMatrixComp<int,19> mat(move(a));\n\
    \  int l,r,k;\n  while(q--){\n    cin >> l >> r >> k;\n    cout << mat.kth_smallest(l,\
    \ r, k) << '\\n';\n  }\n}"
  dependsOn:
  - template/template.hpp
  - data-structure/wavelet-matrix-comp.hpp
  - data-structure/wavelet-matrix.hpp
  - data-structure/bitvector.hpp
  - others/fastIO.hpp
  isVerificationFile: true
  path: test/yosupo/Data-Structure/Range-Kth-Smallest.test.cpp
  requiredBy: []
  timestamp: '2023-11-12 01:15:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Data-Structure/Range-Kth-Smallest.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Data-Structure/Range-Kth-Smallest.test.cpp
- /verify/test/yosupo/Data-Structure/Range-Kth-Smallest.test.cpp.html
title: test/yosupo/Data-Structure/Range-Kth-Smallest.test.cpp
---
