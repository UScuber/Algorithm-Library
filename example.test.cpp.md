---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B
  bundledCode: "#line 1 \"example.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B\"\
    \n#include <algorithm>\n#include <iostream>\n#include <vector>\n#define rep(i,\
    \ n) for (int i = 0; i < (n); i++)\n#define ALL(x) std::begin(x), std::end(x)\n\
    using namespace std;\n\nint main(){\n    int n;\n    cin >> n;\n    vector<int>\
    \ s(n);\n    rep(i, n) cin >> s[i];\n    int q;\n    cin >> q;\n    int cnt =\
    \ 0;\n    while(q--){\n        int t; cin >> t;\n        cnt += binary_search(ALL(s),\
    \ t);\n    }\n    cout << cnt << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B\"\
    \n#include <algorithm>\n#include <iostream>\n#include <vector>\n#define rep(i,\
    \ n) for (int i = 0; i < (n); i++)\n#define ALL(x) std::begin(x), std::end(x)\n\
    using namespace std;\n\nint main(){\n    int n;\n    cin >> n;\n    vector<int>\
    \ s(n);\n    rep(i, n) cin >> s[i];\n    int q;\n    cin >> q;\n    int cnt =\
    \ 0;\n    while(q--){\n        int t; cin >> t;\n        cnt += binary_search(ALL(s),\
    \ t);\n    }\n    cout << cnt << \"\\n\";\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: example.test.cpp
  requiredBy: []
  timestamp: '2023-03-10 18:43:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: example.test.cpp
layout: document
redirect_from:
- /verify/example.test.cpp
- /verify/example.test.cpp.html
title: example.test.cpp
---
