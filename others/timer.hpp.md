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
  bundledCode: "#line 1 \"others/timer.hpp\"\n//chrono\u3092\u4F7F\u3063\u305F\u8A08\
    \u6E2C\r\n#include <chrono>\r\n\r\nstruct Timer {\r\n  chrono::high_resolution_clock::time_point\
    \ st;\r\n  Timer(){ start(); }\r\n  void start(){ st = chrono::high_resolution_clock::now();\
    \ }\r\n  chrono::milliseconds::rep result(){\r\n    auto end = chrono::high_resolution_clock::now();\r\
    \n    return chrono::duration_cast<chrono::milliseconds>(end-st).count();\r\n\
    \  }\r\n};\r\n\r\n\r\n//windows.h\u3092\u4F7F\u3063\u305F\u8A08\u6E2C\r\n#include\
    \ <windows.h>\r\n\r\nstruct Timer {\r\n\tLARGE_INTEGER s, e, freq;\r\n\tTimer(){\r\
    \n\t\tmemset(&e, 0, sizeof(e));\r\n\t\tQueryPerformanceFrequency(&freq);\r\n\t\
    \tstart();\r\n\t}\r\n\tvoid start(){ QueryPerformanceCounter(&s); }\r\n\tvoid\
    \ end(){ QueryPerformanceCounter(&e); }\r\n\tdouble result(){\r\n\t\tdouble time\
    \ = static_cast<double>(e.QuadPart - s.QuadPart) * 1000.0 / freq.QuadPart;\r\n\
    \t\treturn time;\r\n\t}\r\n};\n"
  code: "//chrono\u3092\u4F7F\u3063\u305F\u8A08\u6E2C\r\n#include <chrono>\r\n\r\n\
    struct Timer {\r\n  chrono::high_resolution_clock::time_point st;\r\n  Timer(){\
    \ start(); }\r\n  void start(){ st = chrono::high_resolution_clock::now(); }\r\
    \n  chrono::milliseconds::rep result(){\r\n    auto end = chrono::high_resolution_clock::now();\r\
    \n    return chrono::duration_cast<chrono::milliseconds>(end-st).count();\r\n\
    \  }\r\n};\r\n\r\n\r\n//windows.h\u3092\u4F7F\u3063\u305F\u8A08\u6E2C\r\n#include\
    \ <windows.h>\r\n\r\nstruct Timer {\r\n\tLARGE_INTEGER s, e, freq;\r\n\tTimer(){\r\
    \n\t\tmemset(&e, 0, sizeof(e));\r\n\t\tQueryPerformanceFrequency(&freq);\r\n\t\
    \tstart();\r\n\t}\r\n\tvoid start(){ QueryPerformanceCounter(&s); }\r\n\tvoid\
    \ end(){ QueryPerformanceCounter(&e); }\r\n\tdouble result(){\r\n\t\tdouble time\
    \ = static_cast<double>(e.QuadPart - s.QuadPart) * 1000.0 / freq.QuadPart;\r\n\
    \t\treturn time;\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: others/timer.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/timer.hpp
layout: document
redirect_from:
- /library/others/timer.hpp
- /library/others/timer.hpp.html
title: others/timer.hpp
---
