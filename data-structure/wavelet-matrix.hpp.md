---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/bitvector.hpp
    title: data-structure/bitvector.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: data-structure/wavelet-matrix-comp.hpp
    title: data-structure/wavelet-matrix-comp.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/Data-Structure/Range-Kth-Smallest.test.cpp
    title: test/yosupo/Data-Structure/Range-Kth-Smallest.test.cpp
  - icon: ':x:'
    path: test/yosupo/Data-Structure/Static-Range-Frequency.test.cpp
    title: test/yosupo/Data-Structure/Static-Range-Frequency.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/bitvector.hpp\"\nstruct BitVector {\r\n \
    \ using uint = unsigned int;\r\n  static constexpr int w = 32;\r\n  #define rem(k)\
    \ ((k) & (w - 1))\r\n  int len, blocks;\r\n  vector<uint> bit, sum;\r\n  BitVector(){}\r\
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
    \ r, cnt);\r\n  }\r\n};\n"
  code: "#include \"bitvector.hpp\"\r\n\r\n//----- Wavelet Matrix -----\r\n\r\ntemplate\
    \ <class T, int maxlog, bool USE_SUM = false>\r\nstruct WaveletMatrix {\r\n  int\
    \ len;\r\n  BitVector matrix[maxlog];\r\n  int mid[maxlog];\r\n  vector<T> sum[maxlog];\r\
    \n  WaveletMatrix(){}\r\n  WaveletMatrix(vector<T> v) : len(v.size()){\r\n   \
    \ vector<T> l(len), r(len);\r\n\t\tfill(matrix, matrix + maxlog, BitVector(len\
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
    \ r, cnt);\r\n  }\r\n};"
  dependsOn:
  - data-structure/bitvector.hpp
  isVerificationFile: false
  path: data-structure/wavelet-matrix.hpp
  requiredBy:
  - data-structure/wavelet-matrix-comp.hpp
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/Data-Structure/Range-Kth-Smallest.test.cpp
  - test/yosupo/Data-Structure/Static-Range-Frequency.test.cpp
documentation_of: data-structure/wavelet-matrix.hpp
layout: document
redirect_from:
- /library/data-structure/wavelet-matrix.hpp
- /library/data-structure/wavelet-matrix.hpp.html
title: data-structure/wavelet-matrix.hpp
---
