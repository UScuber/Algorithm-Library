#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct FastIO {
  char tmp_s[20];
  constexpr static int prec = 5;
  #define gc getchar
  template <class T>
  inline void read(T &x){
    bool neg = false;
    int c = gc();
    while((c < '0' || c > '9') && c != '-') c = gc();
    if(c == '-') neg = true, c = gc();
    x = c^'0'; c = gc();
    while(c >= '0' && c <= '9') x = x*10 + (c^'0'), c = gc();
    if(neg) x = -x;
  }
  inline void read(double &x){
    bool neg = false;
    int c = gc();
    while((c < '0' || c > '9') && c != '-') c = gc();
    if(c == '-') neg = true, c = gc();
    x = c^'0'; c = gc();
    while(c >= '0' && c <= '9') x = x*10 + (c^'0'), c = gc();
    if(c == '.'){
      c = gc();
      double dig = 1;
      while(c >= '0' && c <= '9') x += (c^'0')*(dig/=10), c = gc();
    }
    if(neg) x = -x;
  }
  inline void read(string &x){
    char c = gc();
    while(c < '!' || '~' < c) c = gc();
    while(c >= '!' && '~' >= c) x += c, c = gc();
  }
  inline void read(char &x){
    x = gc();
    while(x < '!' || '~' < x) x = gc();
  }
  #undef gc
  #define pc putchar
  inline void out(int x){
    if(!x){ pc('0'); return; }
    if(x < 0){ pc('-'); x = -x; }
    char *t = tmp_s;
    while(x){
      int y = x / 10;
      *(t++) = (x - y*10) + '0';
      x = y;
    }
    while(t != tmp_s) pc(*(--t));
  }
  inline void out(ll x){
    if(!x){ pc('0'); return; }
    if(x < 0){ pc('-'); x = -x; }
    char *t = tmp_s;
    while(x){
      ll y = x / 10;
      *(t++) = (x - y*10) + '0';
      x = y;
    }
    while(t != tmp_s) pc(*(--t));
  }
  inline void out(double x){
    if(x == 0){ pc('0'); return; }
    if(x < 0){ pc('-'); x = -x; }
    out(ll(x));
    x -= ll(x);
    pc('.');
    for(int i = 0; i < prec; i++){
      x *= 10;
      pc(int(x) + '0');
      x -= int(x);
    }
  }
  inline void out(const string &s){
    for(const char &c : s) pc(c);
  }
  inline void out(const char &c){ pc(c); }
  #undef pc
  template <class T>
  friend FastIO &operator>>(FastIO &io, T &x){
    io.read(x);
    return io;
  }
  template <class T>
  friend FastIO &operator<<(FastIO &io, const T &x){
    io.out(x);
    return io;
  }
};
FastIO io;
#define cin io
#define cout io