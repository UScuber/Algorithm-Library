---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/Vector.cpp\"\n#include <bits/stdc++.h>\n\n\
    template <class T>\nstruct Vector {\n  Vector() : sz(0), n(0){}\n  explicit Vector(const\
    \ int &s, const T &v = T()) noexcept : sz(s), n(s){\n    assert(0 <= s);assert(s\
    \ <= 1000000000);\n    if(s) d = (T*)malloc(s * sizeof(T));\n    std::fill(d,\
    \ d + sz, v);\n  }\n  Vector(const Vector<T> &a) noexcept{ *this = a; }\n  Vector(Vector<T>\
    \ &&a) noexcept{ *this = a; }\n  template <int s>\n  Vector(const T (&a)[s]) noexcept{\n\
    \    extention(s);\n    n = s;\n    memcpy(d, a, s * sizeof(T));\n  }\n  ~Vector(){\
    \ free(d); }\n  T &operator[](const int &i) noexcept{\n    assert(0 <= i);assert(i\
    \ < n);\n    return d[i];\n  }\n  Vector<T> &operator=(const Vector<T> &a) noexcept{\n\
    \    if(!a.sz){ clear(); return *this; }\n    extention(a.n);\n    n = a.n; sz\
    \ = a.sz;\n    d = (T*)realloc(d, sz * sizeof(T));\n    memcpy(d, a.d, n * sizeof(T));\n\
    \    return *this;\n  }\n  Vector<T> &operator=(Vector<T> &&a) noexcept{\n   \
    \ free(d);\n    d = a.d; a.d = nullptr;\n    n = a.n; sz = a.sz;\n    return *this;\n\
    \  }\n  void reserve(const int &s){\n    assert(0 <= s);\n    extention(s);\n\
    \    if(s < n) n = s;\n  }\n  void assign(const int &s, const T &v){\n    assert(0\
    \ <= s);\n    extention(s);\n    std::fill(d, d + s, v);\n    n = s;\n  }\n  void\
    \ resize(const int &s, const T &v = T()){\n    assert(0 <= s);\n    extention(s);\n\
    \    if(n < s) std::fill(d + n, d + s, v);\n    n = s;\n  }\n  void emplace_back(const\
    \ T &v) noexcept{ pushback(v); }\n  void push_back(const T &v) noexcept{\n   \
    \ if(n == sz) extention(sz);\n    d[n++] = v;\n  }\n  void pop_back() noexcept{\
    \ assert(n >= 1); n--; }\n  T &front() noexcept{ assert(n >= 1); return d[0];\
    \ }\n  T &back() noexcept{ assert(n >= 1); return d[n - 1]; }\n  void swap(Vector<T>\
    \ &a) noexcept{ std::swap(n,a.n); std::swap(sz,a.sz); std::swap(d,a.d); }\n  void\
    \ clear() noexcept{ free(d); d = nullptr; sz = n = 0; }\n  int size() const noexcept{\
    \ return n; }\n  int capacity() const noexcept{ return sz; }\n  bool empty() const\
    \ noexcept{ return !n; }\n  T *begin() const noexcept{ return d; }\n  T *end()\
    \ const noexcept{ return d + n; }\n  void erase(const int &pos) noexcept{\n  \
    \  assert(0 <= pos && pos < n);\n    std::move(d+pos+1, d+n, d+pos);\n    n--;\n\
    \  }\n  void erase(const int &l, const int &r) noexcept{\n    assert(0 <= l &&\
    \ l <= r && r <= n);\n    std::move(d+r, d+n, d+l);\n    n -= r - l;\n  }\n  void\
    \ erase(const T *p) noexcept{ erase(p - d); }\n  void erase(const T *lp, const\
    \ T *rp) noexcept{ erase(lp - d, rp - d); }\n  void insert(const int &pos, const\
    \ T &v) noexcept{\n    assert(0 <= pos && pos <= n);\n    if(n == sz) extention(sz);\n\
    \    std::move_backward(d+pos, d+n, d+n+1);\n    d[pos] = v; n++;\n  }\n  void\
    \ insert(const int &pos, const T *lp, const T *rp) noexcept{\n    assert(0 <=\
    \ pos && pos <= n && lp <= rp);\n    const int c = rp - lp;\n    extention(n +\
    \ c);\n    std::move_backward(d+pos, d+n, d+n+c);\n    memcpy(d+pos, lp, c * sizeof(T));\n\
    \    n += c;\n  }\n  void insert(const T *pt, const T &v) noexcept{ insert(pt\
    \ - d, v); }\n  void insert(T *pt, const T *lp, const T *rp) noexcept{ insert(pt\
    \ - d, lp, rp); }\n  template <int s>\n  void insert(T *pt, const T (&a)[s]) noexcept{\
    \ insert(pt - d, a, a + s); }\n  void sort(const bool &rev = false) noexcept{\n\
    \    if(rev) std::sort(d, d + n, [&](const  T &a, const T &b){ return b < a; });\n\
    \    else std::sort(d, d + n, [&](const T &a, const T &b){ return a < b; });\n\
    \  }\n  private:\n  T *d = nullptr;\n  int sz, n;\n  void extention(const int\
    \ &len) noexcept{\n    sz = ceil_pow(len);\n    d = (T*)realloc(d, sz * sizeof(T));\n\
    \  }\n  int ceil_pow(const int &v) const noexcept{ return v ? (1 << (32-__builtin_clz(v)))\
    \ : 1; }\n};\n"
  code: "#include <bits/stdc++.h>\n\ntemplate <class T>\nstruct Vector {\n  Vector()\
    \ : sz(0), n(0){}\n  explicit Vector(const int &s, const T &v = T()) noexcept\
    \ : sz(s), n(s){\n    assert(0 <= s);assert(s <= 1000000000);\n    if(s) d = (T*)malloc(s\
    \ * sizeof(T));\n    std::fill(d, d + sz, v);\n  }\n  Vector(const Vector<T> &a)\
    \ noexcept{ *this = a; }\n  Vector(Vector<T> &&a) noexcept{ *this = a; }\n  template\
    \ <int s>\n  Vector(const T (&a)[s]) noexcept{\n    extention(s);\n    n = s;\n\
    \    memcpy(d, a, s * sizeof(T));\n  }\n  ~Vector(){ free(d); }\n  T &operator[](const\
    \ int &i) noexcept{\n    assert(0 <= i);assert(i < n);\n    return d[i];\n  }\n\
    \  Vector<T> &operator=(const Vector<T> &a) noexcept{\n    if(!a.sz){ clear();\
    \ return *this; }\n    extention(a.n);\n    n = a.n; sz = a.sz;\n    d = (T*)realloc(d,\
    \ sz * sizeof(T));\n    memcpy(d, a.d, n * sizeof(T));\n    return *this;\n  }\n\
    \  Vector<T> &operator=(Vector<T> &&a) noexcept{\n    free(d);\n    d = a.d; a.d\
    \ = nullptr;\n    n = a.n; sz = a.sz;\n    return *this;\n  }\n  void reserve(const\
    \ int &s){\n    assert(0 <= s);\n    extention(s);\n    if(s < n) n = s;\n  }\n\
    \  void assign(const int &s, const T &v){\n    assert(0 <= s);\n    extention(s);\n\
    \    std::fill(d, d + s, v);\n    n = s;\n  }\n  void resize(const int &s, const\
    \ T &v = T()){\n    assert(0 <= s);\n    extention(s);\n    if(n < s) std::fill(d\
    \ + n, d + s, v);\n    n = s;\n  }\n  void emplace_back(const T &v) noexcept{\
    \ pushback(v); }\n  void push_back(const T &v) noexcept{\n    if(n == sz) extention(sz);\n\
    \    d[n++] = v;\n  }\n  void pop_back() noexcept{ assert(n >= 1); n--; }\n  T\
    \ &front() noexcept{ assert(n >= 1); return d[0]; }\n  T &back() noexcept{ assert(n\
    \ >= 1); return d[n - 1]; }\n  void swap(Vector<T> &a) noexcept{ std::swap(n,a.n);\
    \ std::swap(sz,a.sz); std::swap(d,a.d); }\n  void clear() noexcept{ free(d); d\
    \ = nullptr; sz = n = 0; }\n  int size() const noexcept{ return n; }\n  int capacity()\
    \ const noexcept{ return sz; }\n  bool empty() const noexcept{ return !n; }\n\
    \  T *begin() const noexcept{ return d; }\n  T *end() const noexcept{ return d\
    \ + n; }\n  void erase(const int &pos) noexcept{\n    assert(0 <= pos && pos <\
    \ n);\n    std::move(d+pos+1, d+n, d+pos);\n    n--;\n  }\n  void erase(const\
    \ int &l, const int &r) noexcept{\n    assert(0 <= l && l <= r && r <= n);\n \
    \   std::move(d+r, d+n, d+l);\n    n -= r - l;\n  }\n  void erase(const T *p)\
    \ noexcept{ erase(p - d); }\n  void erase(const T *lp, const T *rp) noexcept{\
    \ erase(lp - d, rp - d); }\n  void insert(const int &pos, const T &v) noexcept{\n\
    \    assert(0 <= pos && pos <= n);\n    if(n == sz) extention(sz);\n    std::move_backward(d+pos,\
    \ d+n, d+n+1);\n    d[pos] = v; n++;\n  }\n  void insert(const int &pos, const\
    \ T *lp, const T *rp) noexcept{\n    assert(0 <= pos && pos <= n && lp <= rp);\n\
    \    const int c = rp - lp;\n    extention(n + c);\n    std::move_backward(d+pos,\
    \ d+n, d+n+c);\n    memcpy(d+pos, lp, c * sizeof(T));\n    n += c;\n  }\n  void\
    \ insert(const T *pt, const T &v) noexcept{ insert(pt - d, v); }\n  void insert(T\
    \ *pt, const T *lp, const T *rp) noexcept{ insert(pt - d, lp, rp); }\n  template\
    \ <int s>\n  void insert(T *pt, const T (&a)[s]) noexcept{ insert(pt - d, a, a\
    \ + s); }\n  void sort(const bool &rev = false) noexcept{\n    if(rev) std::sort(d,\
    \ d + n, [&](const  T &a, const T &b){ return b < a; });\n    else std::sort(d,\
    \ d + n, [&](const T &a, const T &b){ return a < b; });\n  }\n  private:\n  T\
    \ *d = nullptr;\n  int sz, n;\n  void extention(const int &len) noexcept{\n  \
    \  sz = ceil_pow(len);\n    d = (T*)realloc(d, sz * sizeof(T));\n  }\n  int ceil_pow(const\
    \ int &v) const noexcept{ return v ? (1 << (32-__builtin_clz(v))) : 1; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/Vector.cpp
  requiredBy: []
  timestamp: '2022-03-03 19:36:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/Vector.cpp
layout: document
redirect_from:
- /library/data-structure/Vector.cpp
- /library/data-structure/Vector.cpp.html
title: data-structure/Vector.cpp
---
