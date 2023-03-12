using lll = __int128;
ostream &operator<<(ostream &os, lll x){
  #define pc(c) os.put(c)
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
  #define gc(c) is.get(c)
  bool neg = false;
  char c;
  gc(c);
  while((c < '0' || c > '9') && c != '-') gc(c);
  if(c == '-') neg = true, gc(c);
  x = c^'0'; gc(c);
  while(c >= '0' && c <= '9') x = x*10 + (c^'0'), gc(c);
  if(neg) x = -x;
  return is;
  #undef gc
}