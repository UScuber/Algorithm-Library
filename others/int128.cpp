#include <bits/stdc++.h>
using namespace std;

using lll = __int128_t;
ostream &operator<<(ostream &os, lll x){
  #define pc(c) (os << c)
  char tmp_s[40];
  if(!x){ pc('0'); return os; }
  if(x < 0){ pc('-'); x = -x; }
  char *t = tmp_s;
  while(x){
    const lll y = x / 10;
    *(t++) = (x - y*10) + '0';
    x = y;
  }
  while(t != tmp_s) pc(*(--t));
  return os;
  #undef pc
}
istream &operator>>(istream &is, lll &x){
  string s; is >> s; x = 0;
  for(const char &c : s) x = x*10 + c-'0';
  return is;
}