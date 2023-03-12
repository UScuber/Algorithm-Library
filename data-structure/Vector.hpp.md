---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/Vector.hpp\"\ntemplate <class T>\r\nstruct\
    \ Vector {\r\n  Vector() : sz(0), n(0){}\r\n  explicit Vector(const int &s, const\
    \ T &v = T()) noexcept : sz(s), n(s){\r\n    assert(0 <= s);assert(s <= 1000000000);\r\
    \n    if(s) d = (T*)malloc(s * sizeof(T));\r\n    std::fill(d, d + sz, v);\r\n\
    \  }\r\n  Vector(const Vector<T> &a) noexcept{ *this = a; }\r\n  Vector(Vector<T>\
    \ &&a) noexcept{ *this = a; }\r\n  template <int s>\r\n  Vector(const T (&a)[s])\
    \ noexcept{\r\n    extention(s);\r\n    n = s;\r\n    memcpy(d, a, s * sizeof(T));\r\
    \n  }\r\n  ~Vector(){ free(d); }\r\n  T &operator[](const int &i) noexcept{\r\n\
    \    assert(0 <= i);assert(i < n);\r\n    return d[i];\r\n  }\r\n  Vector<T> &operator=(const\
    \ Vector<T> &a) noexcept{\r\n    if(!a.sz){ clear(); return *this; }\r\n    extention(a.n);\r\
    \n    n = a.n; sz = a.sz;\r\n    d = (T*)realloc(d, sz * sizeof(T));\r\n    memcpy(d,\
    \ a.d, n * sizeof(T));\r\n    return *this;\r\n  }\r\n  Vector<T> &operator=(Vector<T>\
    \ &&a) noexcept{\r\n    free(d);\r\n    d = a.d; a.d = nullptr;\r\n    n = a.n;\
    \ sz = a.sz;\r\n    return *this;\r\n  }\r\n  void reserve(const int &s){\r\n\
    \    assert(0 <= s);\r\n    extention(s);\r\n    if(s < n) n = s;\r\n  }\r\n \
    \ void assign(const int &s, const T &v){\r\n    assert(0 <= s);\r\n    extention(s);\r\
    \n    std::fill(d, d + s, v);\r\n    n = s;\r\n  }\r\n  void resize(const int\
    \ &s, const T &v = T()){\r\n    assert(0 <= s);\r\n    extention(s);\r\n    if(n\
    \ < s) std::fill(d + n, d + s, v);\r\n    n = s;\r\n  }\r\n  void emplace_back(const\
    \ T &v) noexcept{ pushback(v); }\r\n  void push_back(const T &v) noexcept{\r\n\
    \    if(n == sz) extention(sz);\r\n    d[n++] = v;\r\n  }\r\n  void pop_back()\
    \ noexcept{ assert(n >= 1); n--; }\r\n  T &front() noexcept{ assert(n >= 1); return\
    \ d[0]; }\r\n  T &back() noexcept{ assert(n >= 1); return d[n - 1]; }\r\n  void\
    \ swap(Vector<T> &a) noexcept{ std::swap(n,a.n); std::swap(sz,a.sz); std::swap(d,a.d);\
    \ }\r\n  void clear() noexcept{ free(d); d = nullptr; sz = n = 0; }\r\n  int size()\
    \ const noexcept{ return n; }\r\n  int capacity() const noexcept{ return sz; }\r\
    \n  bool empty() const noexcept{ return !n; }\r\n  T *begin() const noexcept{\
    \ return d; }\r\n  T *end() const noexcept{ return d + n; }\r\n  void erase(const\
    \ int &pos) noexcept{\r\n    assert(0 <= pos && pos < n);\r\n    std::move(d+pos+1,\
    \ d+n, d+pos);\r\n    n--;\r\n  }\r\n  void erase(const int &l, const int &r)\
    \ noexcept{\r\n    assert(0 <= l && l <= r && r <= n);\r\n    std::move(d+r, d+n,\
    \ d+l);\r\n    n -= r - l;\r\n  }\r\n  void erase(const T *p) noexcept{ erase(p\
    \ - d); }\r\n  void erase(const T *lp, const T *rp) noexcept{ erase(lp - d, rp\
    \ - d); }\r\n  void insert(const int &pos, const T &v) noexcept{\r\n    assert(0\
    \ <= pos && pos <= n);\r\n    if(n == sz) extention(sz);\r\n    std::move_backward(d+pos,\
    \ d+n, d+n+1);\r\n    d[pos] = v; n++;\r\n  }\r\n  void insert(const int &pos,\
    \ const T *lp, const T *rp) noexcept{\r\n    assert(0 <= pos && pos <= n && lp\
    \ <= rp);\r\n    const int c = rp - lp;\r\n    extention(n + c);\r\n    std::move_backward(d+pos,\
    \ d+n, d+n+c);\r\n    memcpy(d+pos, lp, c * sizeof(T));\r\n    n += c;\r\n  }\r\
    \n  void insert(const T *pt, const T &v) noexcept{ insert(pt - d, v); }\r\n  void\
    \ insert(T *pt, const T *lp, const T *rp) noexcept{ insert(pt - d, lp, rp); }\r\
    \n  template <int s>\r\n  void insert(T *pt, const T (&a)[s]) noexcept{ insert(pt\
    \ - d, a, a + s); }\r\n  void sort(const bool &rev = false) noexcept{\r\n    if(rev)\
    \ std::sort(d, d + n, [&](const  T &a, const T &b){ return b < a; });\r\n    else\
    \ std::sort(d, d + n, [&](const T &a, const T &b){ return a < b; });\r\n  }\r\n\
    \  private:\r\n  T *d = nullptr;\r\n  int sz, n;\r\n  void extention(const int\
    \ &len) noexcept{\r\n    sz = ceil_pow(len);\r\n    d = (T*)realloc(d, sz * sizeof(T));\r\
    \n  }\r\n  int ceil_pow(const int &v) const noexcept{ return v ? (1 << (32-__builtin_clz(v)))\
    \ : 1; }\r\n};\n"
  code: "template <class T>\r\nstruct Vector {\r\n  Vector() : sz(0), n(0){}\r\n \
    \ explicit Vector(const int &s, const T &v = T()) noexcept : sz(s), n(s){\r\n\
    \    assert(0 <= s);assert(s <= 1000000000);\r\n    if(s) d = (T*)malloc(s * sizeof(T));\r\
    \n    std::fill(d, d + sz, v);\r\n  }\r\n  Vector(const Vector<T> &a) noexcept{\
    \ *this = a; }\r\n  Vector(Vector<T> &&a) noexcept{ *this = a; }\r\n  template\
    \ <int s>\r\n  Vector(const T (&a)[s]) noexcept{\r\n    extention(s);\r\n    n\
    \ = s;\r\n    memcpy(d, a, s * sizeof(T));\r\n  }\r\n  ~Vector(){ free(d); }\r\
    \n  T &operator[](const int &i) noexcept{\r\n    assert(0 <= i);assert(i < n);\r\
    \n    return d[i];\r\n  }\r\n  Vector<T> &operator=(const Vector<T> &a) noexcept{\r\
    \n    if(!a.sz){ clear(); return *this; }\r\n    extention(a.n);\r\n    n = a.n;\
    \ sz = a.sz;\r\n    d = (T*)realloc(d, sz * sizeof(T));\r\n    memcpy(d, a.d,\
    \ n * sizeof(T));\r\n    return *this;\r\n  }\r\n  Vector<T> &operator=(Vector<T>\
    \ &&a) noexcept{\r\n    free(d);\r\n    d = a.d; a.d = nullptr;\r\n    n = a.n;\
    \ sz = a.sz;\r\n    return *this;\r\n  }\r\n  void reserve(const int &s){\r\n\
    \    assert(0 <= s);\r\n    extention(s);\r\n    if(s < n) n = s;\r\n  }\r\n \
    \ void assign(const int &s, const T &v){\r\n    assert(0 <= s);\r\n    extention(s);\r\
    \n    std::fill(d, d + s, v);\r\n    n = s;\r\n  }\r\n  void resize(const int\
    \ &s, const T &v = T()){\r\n    assert(0 <= s);\r\n    extention(s);\r\n    if(n\
    \ < s) std::fill(d + n, d + s, v);\r\n    n = s;\r\n  }\r\n  void emplace_back(const\
    \ T &v) noexcept{ pushback(v); }\r\n  void push_back(const T &v) noexcept{\r\n\
    \    if(n == sz) extention(sz);\r\n    d[n++] = v;\r\n  }\r\n  void pop_back()\
    \ noexcept{ assert(n >= 1); n--; }\r\n  T &front() noexcept{ assert(n >= 1); return\
    \ d[0]; }\r\n  T &back() noexcept{ assert(n >= 1); return d[n - 1]; }\r\n  void\
    \ swap(Vector<T> &a) noexcept{ std::swap(n,a.n); std::swap(sz,a.sz); std::swap(d,a.d);\
    \ }\r\n  void clear() noexcept{ free(d); d = nullptr; sz = n = 0; }\r\n  int size()\
    \ const noexcept{ return n; }\r\n  int capacity() const noexcept{ return sz; }\r\
    \n  bool empty() const noexcept{ return !n; }\r\n  T *begin() const noexcept{\
    \ return d; }\r\n  T *end() const noexcept{ return d + n; }\r\n  void erase(const\
    \ int &pos) noexcept{\r\n    assert(0 <= pos && pos < n);\r\n    std::move(d+pos+1,\
    \ d+n, d+pos);\r\n    n--;\r\n  }\r\n  void erase(const int &l, const int &r)\
    \ noexcept{\r\n    assert(0 <= l && l <= r && r <= n);\r\n    std::move(d+r, d+n,\
    \ d+l);\r\n    n -= r - l;\r\n  }\r\n  void erase(const T *p) noexcept{ erase(p\
    \ - d); }\r\n  void erase(const T *lp, const T *rp) noexcept{ erase(lp - d, rp\
    \ - d); }\r\n  void insert(const int &pos, const T &v) noexcept{\r\n    assert(0\
    \ <= pos && pos <= n);\r\n    if(n == sz) extention(sz);\r\n    std::move_backward(d+pos,\
    \ d+n, d+n+1);\r\n    d[pos] = v; n++;\r\n  }\r\n  void insert(const int &pos,\
    \ const T *lp, const T *rp) noexcept{\r\n    assert(0 <= pos && pos <= n && lp\
    \ <= rp);\r\n    const int c = rp - lp;\r\n    extention(n + c);\r\n    std::move_backward(d+pos,\
    \ d+n, d+n+c);\r\n    memcpy(d+pos, lp, c * sizeof(T));\r\n    n += c;\r\n  }\r\
    \n  void insert(const T *pt, const T &v) noexcept{ insert(pt - d, v); }\r\n  void\
    \ insert(T *pt, const T *lp, const T *rp) noexcept{ insert(pt - d, lp, rp); }\r\
    \n  template <int s>\r\n  void insert(T *pt, const T (&a)[s]) noexcept{ insert(pt\
    \ - d, a, a + s); }\r\n  void sort(const bool &rev = false) noexcept{\r\n    if(rev)\
    \ std::sort(d, d + n, [&](const  T &a, const T &b){ return b < a; });\r\n    else\
    \ std::sort(d, d + n, [&](const T &a, const T &b){ return a < b; });\r\n  }\r\n\
    \  private:\r\n  T *d = nullptr;\r\n  int sz, n;\r\n  void extention(const int\
    \ &len) noexcept{\r\n    sz = ceil_pow(len);\r\n    d = (T*)realloc(d, sz * sizeof(T));\r\
    \n  }\r\n  int ceil_pow(const int &v) const noexcept{ return v ? (1 << (32-__builtin_clz(v)))\
    \ : 1; }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/Vector.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/Vector.hpp
layout: document
redirect_from:
- /library/data-structure/Vector.hpp
- /library/data-structure/Vector.hpp.html
title: data-structure/Vector.hpp
---
