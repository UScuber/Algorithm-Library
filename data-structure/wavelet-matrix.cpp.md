---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data-structure/bitvector.hpp
    title: data-structure/bitvector.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/wavelet-matrix.cpp\"\n#include <bits/stdc++.h>\n\
    #line 2 \"data-structure/bitvector.hpp\"\nusing namespace std;\n\nstruct BitVector\
    \ {\n  using uint = unsigned int;\n  static constexpr int w = 32;\n  #define rem(k)\
    \ ((k) & (w - 1))\n  int len, blocks;\n  vector<uint> bit, sum;\n  BitVector(){}\n\
    \  BitVector(const int len) : len(len), blocks((len+w-1)/w){\n    bit.assign(blocks,\
    \ 0);\n    sum.assign(blocks, 0);\n  }\n  inline void set(const int k, const int\
    \ b = 1) noexcept{\n    if(b) bit[k / w] |= 1U << rem(k);\n    else bit[k / w]\
    \ &= ~(1U << rem(k));\n  }\n  void build(){\n    sum[0] = 0;\n    for(int i =\
    \ 1; i < blocks; i++){\n      sum[i] = sum[i - 1] + __builtin_popcount(bit[i -\
    \ 1]);\n    }\n  }\n  int operator[](const int k) const{\n    return bit[k / w]\
    \ >> rem(k) & 1;\n  }\n  inline int rank(const int k) const noexcept{\n    return\
    \ sum[k / w] + __builtin_popcount(bit[k / w] & ((1U << rem(k)) - 1));\n  }\n \
    \ inline int rank(const int val, const int k) const noexcept{\n    return val\
    \ ? rank(k) : k - rank(k);\n  }\n  #undef rem\n};\n#line 3 \"data-structure/wavelet-matrix.cpp\"\
    \nusing namespace std;\n\n//----- Wavelet Matrix -----\n\ntemplate <class T, int\
    \ maxlog, bool USE_SUM = false>\nstruct WaveletMatrix {\n  int len;\n  BitVector\
    \ matrix[maxlog];\n  int mid[maxlog];\n  vector<T> sum[maxlog];\n  WaveletMatrix(){}\n\
    \  WaveletMatrix(vector<T> v) : len(v.size()){\n    vector<T> l(len), r(len);\n\
    \t\tfill(matrix, matrix + maxlog, BitVector(len + 1));\n    if(USE_SUM) fill(sum,\
    \ sum + maxlog, vector<T>(len + 1));\n    for(int level = maxlog - 1; level >=\
    \ 0; level--){\n      int left = 0, right = 0;\n      for(int i = 0; i < len;\
    \ i++){\n        if(v[i] >> level & 1){\n          matrix[level].set(i);\n   \
    \       r[right++] = v[i];\n        }else{\n          l[left++] = v[i];\n    \
    \    }\n      }\n      mid[level] = left;\n      matrix[level].build();\n    \
    \  v.swap(l);\n      copy(r.begin(), r.begin() + right, v.begin() + left);\n \
    \     if(USE_SUM){\n        sum[level][0] = 0;\n        for(int i = 0; i < len;\
    \ i++){\n          sum[level][i + 1] = sum[level][i] + v[i];\n        }\n    \
    \  }\n    }\n  }\n  inline int succ(const int f, const int l, const int level)\
    \ const{\n    return matrix[level].rank(f, l) + mid[level] * f;\n  }\n  //find\
    \ v[k]\n  T access(int k) const{\n    assert(0 <= k && k < len);\n    T res =\
    \ 0;\n    for(int level = maxlog - 1; level >= 0; level--){\n      const bool\
    \ f = matrix[level][k];\n      if(f) res |= T(1) << level;\n      k = matrix[level].rank(f,\
    \ k) + mid[level]*f;\n    }\n    return res;\n  }\n  T operator[](const int k)\
    \ const{ return access(k); }\n  // count i  (0 <= i < r) && v[i] == x\n  int rank(const\
    \ T x, int r) const{\n    assert(0 <= r && r <= len);\n    int l = 0;\n    for(int\
    \ level = maxlog - 1; level >= 0; level--){\n      l = succ(x >> level & 1, l,\
    \ level);\n      r = succ(x >> level & 1, r, level);\n    }\n    return r - l;\n\
    \  }\n  //k-th value v[l,r)\n  T kth_smallest(int l, int r, int k) const{\n  \
    \  assert(0 <= l && l <= r && r <= len);\n    assert(0 <= k && k < r - l);\n \
    \   T res = 0;\n    for(int level = maxlog - 1; level >= 0; level--){\n      int\
    \ cnt = matrix[level].rank(0, r) - matrix[level].rank(0, l);\n      bool f = cnt\
    \ <= k;\n      if(f){\n        res |= T(1) << level;\n        k -= cnt;\n    \
    \  }\n      l = succ(f, l, level);\n      r = succ(f, r, level);\n    }\n    return\
    \ res;\n  }\n  T kth_largest(int l, int r, int k) const{\n    return kth_smallest(l,\
    \ r, r-l-k-1);\n  }\n  // sum of [0,k)th smallest elements([l, r))\n  T kth_smallest_sum(int\
    \ l, int r, int k) const{\n    assert(0 <= l && l <= r && r <= len);\n    assert(0\
    \ <= k && k <= r - l);\n    assert(USE_SUM);\n    T res = 0;\n    for(int level\
    \ = maxlog - 1; level >= 0; level--){\n      const int l0 = matrix[level].rank(0,\
    \ l);\n      const int r0 = matrix[level].rank(0, r);\n      if(k < r0 - l0){\n\
    \        l = l0, r = r0;\n      }else{\n        k -= r0 - l0;\n        res +=\
    \ sum[level][r0] - sum[level][l0];\n        l += mid[level] - l0;\n        r +=\
    \ mid[level] - r0;\n      }\n    }\n    if(k) res += sum[0][l + k] - sum[0][l];\n\
    \    return res;\n  }\n  // sum of [0,k)th largest elements([l, r))\n  T kth_largest_sum(int\
    \ l, int r, int k) const{\n    assert(0 <= l && l <= r && r <= len);\n    assert(0\
    \ <= k && k <= r - l);\n    assert(USE_SUM);\n    return  kth_smallest_sum(l,\
    \ r, r - l) - kth_smallest_sum(l, r, r - l - k);\n  }\n  // count i  (l <= i <\
    \ r), (v[i] < upper)\n  int range_freq(int l, int r, const T upper) const{\n \
    \   int res = 0;\n    for(int level = maxlog - 1; level >= 0; level--){\n    \
    \  bool f = upper >> level & 1;\n      if(f) res += matrix[level].rank(0, r) -\
    \ matrix[level].rank(0, l);\n      l = succ(f, l, level);\n      r = succ(f, r,\
    \ level);\n    }\n    return res;\n  }\n  // count i  (l <= i < r), (lower <=\
    \ v[i] < upper)\n  int range_freq(int l, int r, const T lower, const T upper)\
    \ const{\n    assert(0 <= l && l <= r && r <= len);\n    return range_freq(l,\
    \ r, upper) - range_freq(l, r, lower);\n  }\n  // max v[i]  (l <= i < r), (v[i]\
    \ < upper)\n  T prev_value(int l, int r, const T upper) const{\n    assert(0 <=\
    \ l && l <= r && r <= len);\n    int cnt = range_freq(l, r, upper);\n    return\
    \ cnt == 0 ? -1 : kth_smallest(l, r, cnt - 1);\n  }\n  // min v[i]  (l <= i <\
    \ r), (lower <= v[i])\n  T next_value(int l, int r, const T lower) const{\n  \
    \  assert(0 <= l && l <= r && r <= len);\n    int cnt = range_freq(l, r, lower);\n\
    \    return cnt == r - l ? -1 : kth_smallest(l, r, cnt);\n  }\n};\n\n\n//-----\
    \ Compressed Wavelet Matrix -----\n\ntemplate <class T, int maxlog, bool USE_SUM\
    \ = false>\nstruct WaveletMatrixComp {\n  int len;\n  BitVector matrix[maxlog];\n\
    \  int mid[maxlog];\n  vector<T> sum[maxlog];\n  vector<T> d;\n  WaveletMatrixComp(){}\n\
    \  WaveletMatrixComp(const vector<T> &data) : len(data.size()), d(data){\n   \
    \ sort(d.begin(), d.end());\n    d.erase(unique(d.begin(), d.end()), d.end());\n\
    \    vector<int> v(len);\n    for(int i = 0; i < len; i++) v[i] = get_pos(data[i]);\n\
    \    vector<int> l(len), r(len);\n\t\tfill(matrix, matrix + maxlog, BitVector(len\
    \ + 1));\n    if(USE_SUM) fill(sum, sum + maxlog, vector<T>(len + 1));\n    for(int\
    \ level = maxlog - 1; level >= 0; level--){\n      int left = 0, right = 0;\n\
    \      for(int i = 0; i < len; i++){\n        if(v[i] >> level & 1){\n       \
    \   matrix[level].set(i);\n          r[right++] = v[i];\n        }else{\n    \
    \      l[left++] = v[i];\n        }\n      }\n      mid[level] = left;\n     \
    \ matrix[level].build();\n      v.swap(l);\n      copy(r.begin(), r.begin() +\
    \ right, v.begin() + left);\n      if(USE_SUM){\n        sum[level][0] = 0;\n\
    \        for(int i = 0; i < len; i++){\n          sum[level][i + 1] = sum[level][i]\
    \ + d[v[i]];\n        }\n      }\n    }\n  }\n  inline int get_pos(const T x)\
    \ const{\n\t\treturn lower_bound(d.begin(), d.end(), x) - d.begin();\n\t}\n  inline\
    \ int succ(const int f, const int l, const int level) const{\n    return matrix[level].rank(f,\
    \ l) + mid[level] * f;\n  }\n  //find v[k]\n  T access(int k) const{\n    assert(0\
    \ <= k && k < len);\n    T res = 0;\n    for(int level = maxlog - 1; level >=\
    \ 0; level--){\n      const bool f = matrix[level][k];\n      if(f) res |= T(1)\
    \ << level;\n      k = matrix[level].rank(f, k) + mid[level]*f;\n    }\n    return\
    \ d[res];\n  }\n  T operator[](const int k) const{ return access(k); }\n  // count\
    \ i  (0 <= i < r) && v[i] == x\n  int rank(const T x, int r) const{\n    assert(0\
    \ <= r && r <= len);\n    const int pos = get_pos(x);\n    if(pos >= (int)d.size()\
    \ || d[pos] != x) return 0;\n    int l = 0;\n    for(int level = maxlog - 1; level\
    \ >= 0; level--){\n      l = succ(pos >> level & 1, l, level);\n      r = succ(pos\
    \ >> level & 1, r, level);\n    }\n    return r - l;\n  }\n  //k-th value v[l,r)\n\
    \  T kth_smallest(int l, int r, int k) const{\n    assert(0 <= l && l <= r &&\
    \ r <= len);\n    assert(0 <= k && k < r - l);\n    T res = 0;\n    for(int level\
    \ = maxlog - 1; level >= 0; level--){\n      int cnt = matrix[level].rank(0, r)\
    \ - matrix[level].rank(0, l);\n      bool f = cnt <= k;\n      if(f){\n      \
    \  res |= T(1) << level;\n        k -= cnt;\n      }\n      l = succ(f, l, level);\n\
    \      r = succ(f, r, level);\n    }\n    return d[res];\n  }\n  T kth_largest(int\
    \ l, int r, int k) const{\n    return kth_smallest(l, r, r-l-k-1);\n  }\n  //\
    \ sum of [0,k)th smallest elements([l, r))\n  T kth_smallest_sum(int l, int r,\
    \ int k) const{\n    assert(0 <= l && l <= r && r <= len);\n    assert(0 <= k\
    \ && k <= r - l);\n    assert(USE_SUM);\n    T res = 0;\n    for(int level = maxlog\
    \ - 1; level >= 0; level--){\n      const int l0 = matrix[level].rank(0, l);\n\
    \      const int r0 = matrix[level].rank(0, r);\n      if(k < r0 - l0){\n    \
    \    l = l0, r = r0;\n      }else{\n        k -= r0 - l0;\n        res += sum[level][r0]\
    \ - sum[level][l0];\n        l += mid[level] - l0;\n        r += mid[level] -\
    \ r0;\n      }\n    }\n    if(k) res += sum[0][l + k] - sum[0][l];\n    return\
    \ res;\n  }\n  // sum of [0,k)th largest elements([l, r))\n  T kth_largest_sum(int\
    \ l, int r, int k) const{\n    assert(0 <= l && l <= r && r <= len);\n    assert(0\
    \ <= k && k <= r - l);\n    assert(USE_SUM);\n    return  kth_smallest_sum(l,\
    \ r, r - l) - kth_smallest_sum(l, r, r - l - k);\n  }\n  // count i  (l <= i <\
    \ r), (v[i] < upper)\n  int range_freq(int l, int r, const T upper) const{\n \
    \   const int pos = get_pos(upper);\n    int res = 0;\n    for(int level = maxlog\
    \ - 1; level >= 0; level--){\n      bool f = pos >> level & 1;\n      if(f) res\
    \ += matrix[level].rank(0, r) - matrix[level].rank(0, l);\n      l = succ(f, l,\
    \ level);\n      r = succ(f, r, level);\n    }\n    return d[res];\n  }\n  //\
    \ count i  (l <= i < r), (lower <= v[i] < upper)\n  int range_freq(int l, int\
    \ r, const T lower, const T upper) const{\n    assert(0 <= l && l <= r && r <=\
    \ len);\n    return range_freq(l, r, upper) - range_freq(l, r, lower);\n  }\n\
    \  // max v[i]  (l <= i < r), (v[i] < upper)\n  T prev_value(int l, int r, const\
    \ T upper) const{\n    assert(0 <= l && l <= r && r <= len);\n    int cnt = range_freq(l,\
    \ r, upper);\n    return cnt == 0 ? -1 : kth_smallest(l, r, cnt - 1);\n  }\n \
    \ // min v[i]  (l <= i < r), (lower <= v[i])\n  T next_value(int l, int r, const\
    \ T lower) const{\n    assert(0 <= l && l <= r && r <= len);\n    int cnt = range_freq(l,\
    \ r, lower);\n    return cnt == r - l ? -1 : kth_smallest(l, r, cnt);\n  }\n};\n"
  code: "#include <bits/stdc++.h>\n#include \"bitvector.hpp\"\nusing namespace std;\n\
    \n//----- Wavelet Matrix -----\n\ntemplate <class T, int maxlog, bool USE_SUM\
    \ = false>\nstruct WaveletMatrix {\n  int len;\n  BitVector matrix[maxlog];\n\
    \  int mid[maxlog];\n  vector<T> sum[maxlog];\n  WaveletMatrix(){}\n  WaveletMatrix(vector<T>\
    \ v) : len(v.size()){\n    vector<T> l(len), r(len);\n\t\tfill(matrix, matrix\
    \ + maxlog, BitVector(len + 1));\n    if(USE_SUM) fill(sum, sum + maxlog, vector<T>(len\
    \ + 1));\n    for(int level = maxlog - 1; level >= 0; level--){\n      int left\
    \ = 0, right = 0;\n      for(int i = 0; i < len; i++){\n        if(v[i] >> level\
    \ & 1){\n          matrix[level].set(i);\n          r[right++] = v[i];\n     \
    \   }else{\n          l[left++] = v[i];\n        }\n      }\n      mid[level]\
    \ = left;\n      matrix[level].build();\n      v.swap(l);\n      copy(r.begin(),\
    \ r.begin() + right, v.begin() + left);\n      if(USE_SUM){\n        sum[level][0]\
    \ = 0;\n        for(int i = 0; i < len; i++){\n          sum[level][i + 1] = sum[level][i]\
    \ + v[i];\n        }\n      }\n    }\n  }\n  inline int succ(const int f, const\
    \ int l, const int level) const{\n    return matrix[level].rank(f, l) + mid[level]\
    \ * f;\n  }\n  //find v[k]\n  T access(int k) const{\n    assert(0 <= k && k <\
    \ len);\n    T res = 0;\n    for(int level = maxlog - 1; level >= 0; level--){\n\
    \      const bool f = matrix[level][k];\n      if(f) res |= T(1) << level;\n \
    \     k = matrix[level].rank(f, k) + mid[level]*f;\n    }\n    return res;\n \
    \ }\n  T operator[](const int k) const{ return access(k); }\n  // count i  (0\
    \ <= i < r) && v[i] == x\n  int rank(const T x, int r) const{\n    assert(0 <=\
    \ r && r <= len);\n    int l = 0;\n    for(int level = maxlog - 1; level >= 0;\
    \ level--){\n      l = succ(x >> level & 1, l, level);\n      r = succ(x >> level\
    \ & 1, r, level);\n    }\n    return r - l;\n  }\n  //k-th value v[l,r)\n  T kth_smallest(int\
    \ l, int r, int k) const{\n    assert(0 <= l && l <= r && r <= len);\n    assert(0\
    \ <= k && k < r - l);\n    T res = 0;\n    for(int level = maxlog - 1; level >=\
    \ 0; level--){\n      int cnt = matrix[level].rank(0, r) - matrix[level].rank(0,\
    \ l);\n      bool f = cnt <= k;\n      if(f){\n        res |= T(1) << level;\n\
    \        k -= cnt;\n      }\n      l = succ(f, l, level);\n      r = succ(f, r,\
    \ level);\n    }\n    return res;\n  }\n  T kth_largest(int l, int r, int k) const{\n\
    \    return kth_smallest(l, r, r-l-k-1);\n  }\n  // sum of [0,k)th smallest elements([l,\
    \ r))\n  T kth_smallest_sum(int l, int r, int k) const{\n    assert(0 <= l &&\
    \ l <= r && r <= len);\n    assert(0 <= k && k <= r - l);\n    assert(USE_SUM);\n\
    \    T res = 0;\n    for(int level = maxlog - 1; level >= 0; level--){\n     \
    \ const int l0 = matrix[level].rank(0, l);\n      const int r0 = matrix[level].rank(0,\
    \ r);\n      if(k < r0 - l0){\n        l = l0, r = r0;\n      }else{\n       \
    \ k -= r0 - l0;\n        res += sum[level][r0] - sum[level][l0];\n        l +=\
    \ mid[level] - l0;\n        r += mid[level] - r0;\n      }\n    }\n    if(k) res\
    \ += sum[0][l + k] - sum[0][l];\n    return res;\n  }\n  // sum of [0,k)th largest\
    \ elements([l, r))\n  T kth_largest_sum(int l, int r, int k) const{\n    assert(0\
    \ <= l && l <= r && r <= len);\n    assert(0 <= k && k <= r - l);\n    assert(USE_SUM);\n\
    \    return  kth_smallest_sum(l, r, r - l) - kth_smallest_sum(l, r, r - l - k);\n\
    \  }\n  // count i  (l <= i < r), (v[i] < upper)\n  int range_freq(int l, int\
    \ r, const T upper) const{\n    int res = 0;\n    for(int level = maxlog - 1;\
    \ level >= 0; level--){\n      bool f = upper >> level & 1;\n      if(f) res +=\
    \ matrix[level].rank(0, r) - matrix[level].rank(0, l);\n      l = succ(f, l, level);\n\
    \      r = succ(f, r, level);\n    }\n    return res;\n  }\n  // count i  (l <=\
    \ i < r), (lower <= v[i] < upper)\n  int range_freq(int l, int r, const T lower,\
    \ const T upper) const{\n    assert(0 <= l && l <= r && r <= len);\n    return\
    \ range_freq(l, r, upper) - range_freq(l, r, lower);\n  }\n  // max v[i]  (l <=\
    \ i < r), (v[i] < upper)\n  T prev_value(int l, int r, const T upper) const{\n\
    \    assert(0 <= l && l <= r && r <= len);\n    int cnt = range_freq(l, r, upper);\n\
    \    return cnt == 0 ? -1 : kth_smallest(l, r, cnt - 1);\n  }\n  // min v[i] \
    \ (l <= i < r), (lower <= v[i])\n  T next_value(int l, int r, const T lower) const{\n\
    \    assert(0 <= l && l <= r && r <= len);\n    int cnt = range_freq(l, r, lower);\n\
    \    return cnt == r - l ? -1 : kth_smallest(l, r, cnt);\n  }\n};\n\n\n//-----\
    \ Compressed Wavelet Matrix -----\n\ntemplate <class T, int maxlog, bool USE_SUM\
    \ = false>\nstruct WaveletMatrixComp {\n  int len;\n  BitVector matrix[maxlog];\n\
    \  int mid[maxlog];\n  vector<T> sum[maxlog];\n  vector<T> d;\n  WaveletMatrixComp(){}\n\
    \  WaveletMatrixComp(const vector<T> &data) : len(data.size()), d(data){\n   \
    \ sort(d.begin(), d.end());\n    d.erase(unique(d.begin(), d.end()), d.end());\n\
    \    vector<int> v(len);\n    for(int i = 0; i < len; i++) v[i] = get_pos(data[i]);\n\
    \    vector<int> l(len), r(len);\n\t\tfill(matrix, matrix + maxlog, BitVector(len\
    \ + 1));\n    if(USE_SUM) fill(sum, sum + maxlog, vector<T>(len + 1));\n    for(int\
    \ level = maxlog - 1; level >= 0; level--){\n      int left = 0, right = 0;\n\
    \      for(int i = 0; i < len; i++){\n        if(v[i] >> level & 1){\n       \
    \   matrix[level].set(i);\n          r[right++] = v[i];\n        }else{\n    \
    \      l[left++] = v[i];\n        }\n      }\n      mid[level] = left;\n     \
    \ matrix[level].build();\n      v.swap(l);\n      copy(r.begin(), r.begin() +\
    \ right, v.begin() + left);\n      if(USE_SUM){\n        sum[level][0] = 0;\n\
    \        for(int i = 0; i < len; i++){\n          sum[level][i + 1] = sum[level][i]\
    \ + d[v[i]];\n        }\n      }\n    }\n  }\n  inline int get_pos(const T x)\
    \ const{\n\t\treturn lower_bound(d.begin(), d.end(), x) - d.begin();\n\t}\n  inline\
    \ int succ(const int f, const int l, const int level) const{\n    return matrix[level].rank(f,\
    \ l) + mid[level] * f;\n  }\n  //find v[k]\n  T access(int k) const{\n    assert(0\
    \ <= k && k < len);\n    T res = 0;\n    for(int level = maxlog - 1; level >=\
    \ 0; level--){\n      const bool f = matrix[level][k];\n      if(f) res |= T(1)\
    \ << level;\n      k = matrix[level].rank(f, k) + mid[level]*f;\n    }\n    return\
    \ d[res];\n  }\n  T operator[](const int k) const{ return access(k); }\n  // count\
    \ i  (0 <= i < r) && v[i] == x\n  int rank(const T x, int r) const{\n    assert(0\
    \ <= r && r <= len);\n    const int pos = get_pos(x);\n    if(pos >= (int)d.size()\
    \ || d[pos] != x) return 0;\n    int l = 0;\n    for(int level = maxlog - 1; level\
    \ >= 0; level--){\n      l = succ(pos >> level & 1, l, level);\n      r = succ(pos\
    \ >> level & 1, r, level);\n    }\n    return r - l;\n  }\n  //k-th value v[l,r)\n\
    \  T kth_smallest(int l, int r, int k) const{\n    assert(0 <= l && l <= r &&\
    \ r <= len);\n    assert(0 <= k && k < r - l);\n    T res = 0;\n    for(int level\
    \ = maxlog - 1; level >= 0; level--){\n      int cnt = matrix[level].rank(0, r)\
    \ - matrix[level].rank(0, l);\n      bool f = cnt <= k;\n      if(f){\n      \
    \  res |= T(1) << level;\n        k -= cnt;\n      }\n      l = succ(f, l, level);\n\
    \      r = succ(f, r, level);\n    }\n    return d[res];\n  }\n  T kth_largest(int\
    \ l, int r, int k) const{\n    return kth_smallest(l, r, r-l-k-1);\n  }\n  //\
    \ sum of [0,k)th smallest elements([l, r))\n  T kth_smallest_sum(int l, int r,\
    \ int k) const{\n    assert(0 <= l && l <= r && r <= len);\n    assert(0 <= k\
    \ && k <= r - l);\n    assert(USE_SUM);\n    T res = 0;\n    for(int level = maxlog\
    \ - 1; level >= 0; level--){\n      const int l0 = matrix[level].rank(0, l);\n\
    \      const int r0 = matrix[level].rank(0, r);\n      if(k < r0 - l0){\n    \
    \    l = l0, r = r0;\n      }else{\n        k -= r0 - l0;\n        res += sum[level][r0]\
    \ - sum[level][l0];\n        l += mid[level] - l0;\n        r += mid[level] -\
    \ r0;\n      }\n    }\n    if(k) res += sum[0][l + k] - sum[0][l];\n    return\
    \ res;\n  }\n  // sum of [0,k)th largest elements([l, r))\n  T kth_largest_sum(int\
    \ l, int r, int k) const{\n    assert(0 <= l && l <= r && r <= len);\n    assert(0\
    \ <= k && k <= r - l);\n    assert(USE_SUM);\n    return  kth_smallest_sum(l,\
    \ r, r - l) - kth_smallest_sum(l, r, r - l - k);\n  }\n  // count i  (l <= i <\
    \ r), (v[i] < upper)\n  int range_freq(int l, int r, const T upper) const{\n \
    \   const int pos = get_pos(upper);\n    int res = 0;\n    for(int level = maxlog\
    \ - 1; level >= 0; level--){\n      bool f = pos >> level & 1;\n      if(f) res\
    \ += matrix[level].rank(0, r) - matrix[level].rank(0, l);\n      l = succ(f, l,\
    \ level);\n      r = succ(f, r, level);\n    }\n    return d[res];\n  }\n  //\
    \ count i  (l <= i < r), (lower <= v[i] < upper)\n  int range_freq(int l, int\
    \ r, const T lower, const T upper) const{\n    assert(0 <= l && l <= r && r <=\
    \ len);\n    return range_freq(l, r, upper) - range_freq(l, r, lower);\n  }\n\
    \  // max v[i]  (l <= i < r), (v[i] < upper)\n  T prev_value(int l, int r, const\
    \ T upper) const{\n    assert(0 <= l && l <= r && r <= len);\n    int cnt = range_freq(l,\
    \ r, upper);\n    return cnt == 0 ? -1 : kth_smallest(l, r, cnt - 1);\n  }\n \
    \ // min v[i]  (l <= i < r), (lower <= v[i])\n  T next_value(int l, int r, const\
    \ T lower) const{\n    assert(0 <= l && l <= r && r <= len);\n    int cnt = range_freq(l,\
    \ r, lower);\n    return cnt == r - l ? -1 : kth_smallest(l, r, cnt);\n  }\n};"
  dependsOn:
  - data-structure/bitvector.hpp
  isVerificationFile: false
  path: data-structure/wavelet-matrix.cpp
  requiredBy: []
  timestamp: '2022-12-24 01:13:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/wavelet-matrix.cpp
layout: document
redirect_from:
- /library/data-structure/wavelet-matrix.cpp
- /library/data-structure/wavelet-matrix.cpp.html
title: data-structure/wavelet-matrix.cpp
---
