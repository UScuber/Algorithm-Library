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
  bundledCode: "#line 1 \"math/frac.hpp\"\nstruct frac {\r\n  ll a,b;\r\n  frac(const\
    \ ll a = 0, const ll b = 1) : a(a), b(b){}\r\n  frac &operator*=(const ll &d){\r\
    \n    a *= d;\r\n    return *this;\r\n  }\r\n  frac &operator*=(const frac &d){\r\
    \n    a *= d.a; b *= d.b;\r\n    reduce();\r\n    return *this;\r\n  }\r\n  frac\
    \ &operator/=(const frac &d){\r\n    assert(d); //0 division\r\n    a *= d.b;\
    \ b *= d.a;\r\n    reduce();\r\n    return *this;\r\n  }\r\n  frac &operator+=(const\
    \ frac &d){\r\n    ll g = gcd(abs(b), abs(d.b));\r\n    ll t = b / g * d.b; //lcm(abs(a),\
    \ abs(b))\r\n    a = a*d.b/g + d.a*b/g;\r\n    b = t;\r\n    reduce();\r\n   \
    \ return *this;\r\n  }\r\n  frac &operator-=(const frac &d){\r\n    ll g = gcd(abs(b),\
    \ abs(d.b));\r\n    ll t = b / g * d.b; //lcm(abs(a), abs(b))\r\n    a = a*d.b/g\
    \ - d.a*b/g;\r\n    b = t;\r\n    reduce();\r\n    return *this;\r\n  }\r\n  frac\
    \ operator*(const frac &d) const{ return frac(*this) *= d; }\r\n  frac operator/(const\
    \ frac &d) const{ return frac(*this) /= d; }\r\n  frac operator+(const frac &d)\
    \ const{ return frac(*this) += d; }\r\n  frac operator-(const frac &d) const{\
    \ return frac(*this) -= d; }\r\n  bool operator!(){ return !a; }\r\n  bool operator==(const\
    \ frac &d) const{ return a == d.a && b == d.b;}\r\n  bool operator<(const frac\
    \ &d) const{ return (double)a/b < (double)d.a/d.b; }\r\n  bool operator>(const\
    \ frac &d) const{ return (double)a/b > (double)d.a/d.b; }\r\n  operator bool()\
    \ const{ return !a; }\r\n  void reduce(){\r\n    ll g = gcd(abs(a), abs(b));\r\
    \n    if(a < 0 && b < 0) g = -g;\r\n    a /= g; b /= g;\r\n  }\r\n  ll gcd(const\
    \ ll &a, const ll &b){\r\n    if(!b) return a;\r\n    return gcd(b, a % b);\r\n\
    \  }\r\n  void debug(){ cerr << a << \"/\" << b << \" \"; }\r\n  friend istream\
    \ &operator>>(istream &is, frac &d){ return is >> d.a; }\r\n  friend ostream &operator<<(ostream\
    \ &os, const frac &d){\r\n    printf(\"%lf\", (double)d.a / d.b);\r\n    /*\r\n\
    \    if(!d.a) os << 0;\r\n    else if(d.b < 0){\r\n      if(d.b == -1) os << d.a;\r\
    \n      else os << d.a << \"/\" << d.b;\r\n    }else{\r\n      if(d.b == 1) os\
    \ << d.a;\r\n      else os << d.a << \"/\" << d.b;\r\n    }\r\n    */\r\n    return\
    \ os;\r\n  }\r\n};\n"
  code: "struct frac {\r\n  ll a,b;\r\n  frac(const ll a = 0, const ll b = 1) : a(a),\
    \ b(b){}\r\n  frac &operator*=(const ll &d){\r\n    a *= d;\r\n    return *this;\r\
    \n  }\r\n  frac &operator*=(const frac &d){\r\n    a *= d.a; b *= d.b;\r\n   \
    \ reduce();\r\n    return *this;\r\n  }\r\n  frac &operator/=(const frac &d){\r\
    \n    assert(d); //0 division\r\n    a *= d.b; b *= d.a;\r\n    reduce();\r\n\
    \    return *this;\r\n  }\r\n  frac &operator+=(const frac &d){\r\n    ll g =\
    \ gcd(abs(b), abs(d.b));\r\n    ll t = b / g * d.b; //lcm(abs(a), abs(b))\r\n\
    \    a = a*d.b/g + d.a*b/g;\r\n    b = t;\r\n    reduce();\r\n    return *this;\r\
    \n  }\r\n  frac &operator-=(const frac &d){\r\n    ll g = gcd(abs(b), abs(d.b));\r\
    \n    ll t = b / g * d.b; //lcm(abs(a), abs(b))\r\n    a = a*d.b/g - d.a*b/g;\r\
    \n    b = t;\r\n    reduce();\r\n    return *this;\r\n  }\r\n  frac operator*(const\
    \ frac &d) const{ return frac(*this) *= d; }\r\n  frac operator/(const frac &d)\
    \ const{ return frac(*this) /= d; }\r\n  frac operator+(const frac &d) const{\
    \ return frac(*this) += d; }\r\n  frac operator-(const frac &d) const{ return\
    \ frac(*this) -= d; }\r\n  bool operator!(){ return !a; }\r\n  bool operator==(const\
    \ frac &d) const{ return a == d.a && b == d.b;}\r\n  bool operator<(const frac\
    \ &d) const{ return (double)a/b < (double)d.a/d.b; }\r\n  bool operator>(const\
    \ frac &d) const{ return (double)a/b > (double)d.a/d.b; }\r\n  operator bool()\
    \ const{ return !a; }\r\n  void reduce(){\r\n    ll g = gcd(abs(a), abs(b));\r\
    \n    if(a < 0 && b < 0) g = -g;\r\n    a /= g; b /= g;\r\n  }\r\n  ll gcd(const\
    \ ll &a, const ll &b){\r\n    if(!b) return a;\r\n    return gcd(b, a % b);\r\n\
    \  }\r\n  void debug(){ cerr << a << \"/\" << b << \" \"; }\r\n  friend istream\
    \ &operator>>(istream &is, frac &d){ return is >> d.a; }\r\n  friend ostream &operator<<(ostream\
    \ &os, const frac &d){\r\n    printf(\"%lf\", (double)d.a / d.b);\r\n    /*\r\n\
    \    if(!d.a) os << 0;\r\n    else if(d.b < 0){\r\n      if(d.b == -1) os << d.a;\r\
    \n      else os << d.a << \"/\" << d.b;\r\n    }else{\r\n      if(d.b == 1) os\
    \ << d.a;\r\n      else os << d.a << \"/\" << d.b;\r\n    }\r\n    */\r\n    return\
    \ os;\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/frac.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/frac.hpp
layout: document
redirect_from:
- /library/math/frac.hpp
- /library/math/frac.hpp.html
title: math/frac.hpp
---
