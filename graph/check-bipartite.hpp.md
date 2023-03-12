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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: UnionFind.hpp:\
    \ line -1: no such header\n"
  code: "#include \"template.hpp\"\r\n#include \"UnionFind.hpp\"\r\n\r\ntemplate <class\
    \ T>\r\nbool is_bipartite(const Graph<T> &g){\r\n  const int n = g.size();\r\n\
    \  UnionFind tree(n * 2);\r\n  for(int i = 0; i < n; i++) for(const auto &x :\
    \ g[i]){\r\n    tree.unite(x.from, x.to+n);\r\n    tree.unite(x.from+n, x.to);\r\
    \n  }\r\n  for(int i = 0; i < n; i++) for(const auto &x : g[i]){\r\n    if(tree.same(x.from,\
    \ x.to+n)) return false;\r\n  }\r\n  return true;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/check-bipartite.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/check-bipartite.hpp
layout: document
redirect_from:
- /library/graph/check-bipartite.hpp
- /library/graph/check-bipartite.hpp.html
title: graph/check-bipartite.hpp
---
