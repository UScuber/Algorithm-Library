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
  bundledCode: "#line 1 \"math/frac.cpp\"\n#include <bits/stdc++.h>\nusing ll = long\
    \ long;\nusing namespace std;\n\nstruct frac {\n  ll a,b;\n  frac(const ll a =\
    \ 0, const ll b = 1) : a(a), b(b){}\n  frac &operator*=(const ll &d){\n    a *=\
    \ d;\n    return *this;\n  }\n  frac &operator*=(const frac &d){\n    a *= d.a;\
    \ b *= d.b;\n    reduce();\n    return *this;\n  }\n  frac &operator/=(const frac\
    \ &d){\n    assert(d); //0 division\n    a *= d.b; b *= d.a;\n    reduce();\n\
    \    return *this;\n  }\n  frac &operator+=(const frac &d){\n    ll g = gcd(abs(b),\
    \ abs(d.b));\n    ll t = b / g * d.b; //lcm(abs(a), abs(b))\n    a = a*d.b/g +\
    \ d.a*b/g;\n    b = t;\n    reduce();\n    return *this;\n  }\n  frac &operator-=(const\
    \ frac &d){\n    ll g = gcd(abs(b), abs(d.b));\n    ll t = b / g * d.b; //lcm(abs(a),\
    \ abs(b))\n    a = a*d.b/g - d.a*b/g;\n    b = t;\n    reduce();\n    return *this;\n\
    \  }\n  frac operator*(const frac &d) const{ return frac(*this) *= d; }\n  frac\
    \ operator/(const frac &d) const{ return frac(*this) /= d; }\n  frac operator+(const\
    \ frac &d) const{ return frac(*this) += d; }\n  frac operator-(const frac &d)\
    \ const{ return frac(*this) -= d; }\n  bool operator!(){ return !a; }\n  bool\
    \ operator==(const frac &d) const{ return a == d.a && b == d.b;}\n  bool operator<(const\
    \ frac &d) const{ return (double)a/b < (double)d.a/d.b; }\n  bool operator>(const\
    \ frac &d) const{ return (double)a/b > (double)d.a/d.b; }\n  operator bool() const{\
    \ return !a; }\n  void reduce(){\n    ll g = gcd(abs(a), abs(b));\n    if(a <\
    \ 0 && b < 0) g = -g;\n    a /= g; b /= g;\n  }\n  ll gcd(const ll &a, const ll\
    \ &b){\n    if(!b) return a;\n    return gcd(b, a % b);\n  }\n  void debug(){\
    \ cerr << a << \"/\" << b << \" \"; }\n  friend istream &operator>>(istream &is,\
    \ frac &d){ return is >> d.a; }\n  friend ostream &operator<<(ostream &os, const\
    \ frac &d){\n    printf(\"%lf\", (double)d.a / d.b);\n    /*\n    if(!d.a) os\
    \ << 0;\n    else if(d.b < 0){\n      if(d.b == -1) os << d.a;\n      else os\
    \ << d.a << \"/\" << d.b;\n    }else{\n      if(d.b == 1) os << d.a;\n      else\
    \ os << d.a << \"/\" << d.b;\n    }\n    */\n    return os;\n  }\n};\n"
  code: "#include <bits/stdc++.h>\nusing ll = long long;\nusing namespace std;\n\n\
    struct frac {\n  ll a,b;\n  frac(const ll a = 0, const ll b = 1) : a(a), b(b){}\n\
    \  frac &operator*=(const ll &d){\n    a *= d;\n    return *this;\n  }\n  frac\
    \ &operator*=(const frac &d){\n    a *= d.a; b *= d.b;\n    reduce();\n    return\
    \ *this;\n  }\n  frac &operator/=(const frac &d){\n    assert(d); //0 division\n\
    \    a *= d.b; b *= d.a;\n    reduce();\n    return *this;\n  }\n  frac &operator+=(const\
    \ frac &d){\n    ll g = gcd(abs(b), abs(d.b));\n    ll t = b / g * d.b; //lcm(abs(a),\
    \ abs(b))\n    a = a*d.b/g + d.a*b/g;\n    b = t;\n    reduce();\n    return *this;\n\
    \  }\n  frac &operator-=(const frac &d){\n    ll g = gcd(abs(b), abs(d.b));\n\
    \    ll t = b / g * d.b; //lcm(abs(a), abs(b))\n    a = a*d.b/g - d.a*b/g;\n \
    \   b = t;\n    reduce();\n    return *this;\n  }\n  frac operator*(const frac\
    \ &d) const{ return frac(*this) *= d; }\n  frac operator/(const frac &d) const{\
    \ return frac(*this) /= d; }\n  frac operator+(const frac &d) const{ return frac(*this)\
    \ += d; }\n  frac operator-(const frac &d) const{ return frac(*this) -= d; }\n\
    \  bool operator!(){ return !a; }\n  bool operator==(const frac &d) const{ return\
    \ a == d.a && b == d.b;}\n  bool operator<(const frac &d) const{ return (double)a/b\
    \ < (double)d.a/d.b; }\n  bool operator>(const frac &d) const{ return (double)a/b\
    \ > (double)d.a/d.b; }\n  operator bool() const{ return !a; }\n  void reduce(){\n\
    \    ll g = gcd(abs(a), abs(b));\n    if(a < 0 && b < 0) g = -g;\n    a /= g;\
    \ b /= g;\n  }\n  ll gcd(const ll &a, const ll &b){\n    if(!b) return a;\n  \
    \  return gcd(b, a % b);\n  }\n  void debug(){ cerr << a << \"/\" << b << \" \"\
    ; }\n  friend istream &operator>>(istream &is, frac &d){ return is >> d.a; }\n\
    \  friend ostream &operator<<(ostream &os, const frac &d){\n    printf(\"%lf\"\
    , (double)d.a / d.b);\n    /*\n    if(!d.a) os << 0;\n    else if(d.b < 0){\n\
    \      if(d.b == -1) os << d.a;\n      else os << d.a << \"/\" << d.b;\n    }else{\n\
    \      if(d.b == 1) os << d.a;\n      else os << d.a << \"/\" << d.b;\n    }\n\
    \    */\n    return os;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/frac.cpp
  requiredBy: []
  timestamp: '2022-01-28 17:27:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/frac.cpp
layout: document
redirect_from:
- /library/math/frac.cpp
- /library/math/frac.cpp.html
title: math/frac.cpp
---
