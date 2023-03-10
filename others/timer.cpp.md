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
  bundledCode: "#line 1 \"others/timer.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n//chrono\u3092\u4F7F\u3063\u305F\u8A08\u6E2C\n#line 6 \"others/timer.cpp\"\
    \nstruct Timer {\n  chrono::high_resolution_clock::time_point st;\n  Timer(){\
    \ start(); }\n  void start(){ st = chrono::high_resolution_clock::now(); }\n \
    \ chrono::milliseconds::rep result(){\n    auto end = chrono::high_resolution_clock::now();\n\
    \    return chrono::duration_cast<chrono::milliseconds>(end-st).count();\n  }\n\
    };\n\n\n//windows.h\u3092\u4F7F\u3063\u305F\u8A08\u6E2C\n#include <windows.h>\n\
    struct Timer {\n\tLARGE_INTEGER s, e, freq;\n\tTimer(){\n\t\tmemset(&e, 0, sizeof(e));\n\
    \t\tQueryPerformanceFrequency(&freq);\n\t\tstart();\n\t}\n\tvoid start(){ QueryPerformanceCounter(&s);\
    \ }\n\tvoid end(){ QueryPerformanceCounter(&e); }\n\tdouble result(){\n\t\tdouble\
    \ time = static_cast<double>(e.QuadPart - s.QuadPart) * 1000.0 / freq.QuadPart;\n\
    \t\treturn time;\n\t}\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n//chrono\u3092\u4F7F\u3063\
    \u305F\u8A08\u6E2C\n#include <chrono>\nstruct Timer {\n  chrono::high_resolution_clock::time_point\
    \ st;\n  Timer(){ start(); }\n  void start(){ st = chrono::high_resolution_clock::now();\
    \ }\n  chrono::milliseconds::rep result(){\n    auto end = chrono::high_resolution_clock::now();\n\
    \    return chrono::duration_cast<chrono::milliseconds>(end-st).count();\n  }\n\
    };\n\n\n//windows.h\u3092\u4F7F\u3063\u305F\u8A08\u6E2C\n#include <windows.h>\n\
    struct Timer {\n\tLARGE_INTEGER s, e, freq;\n\tTimer(){\n\t\tmemset(&e, 0, sizeof(e));\n\
    \t\tQueryPerformanceFrequency(&freq);\n\t\tstart();\n\t}\n\tvoid start(){ QueryPerformanceCounter(&s);\
    \ }\n\tvoid end(){ QueryPerformanceCounter(&e); }\n\tdouble result(){\n\t\tdouble\
    \ time = static_cast<double>(e.QuadPart - s.QuadPart) * 1000.0 / freq.QuadPart;\n\
    \t\treturn time;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: others/timer.cpp
  requiredBy: []
  timestamp: '2022-02-21 14:42:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/timer.cpp
layout: document
redirect_from:
- /library/others/timer.cpp
- /library/others/timer.cpp.html
title: others/timer.cpp
---
