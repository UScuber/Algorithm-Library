namespace FastIO {
struct PreCalc {
  char num[10000 * 4];
  constexpr PreCalc() : num(){
    for(int i = 0; i < 10000; i++){
      int t = i;
      for(int j = 3; j >= 0; j--){
        num[i*4 + j] = (t % 10) + '0';
        t /= 10;
      }
    }
  }
};
static constexpr PreCalc pr;
struct FastIO {
  template <class T>
  using enable_if_integer = enable_if_t<is_integral<T>::value || is_same<T, __int128_t>::value || is_same<T, __uint128_t>::value>;
  static constexpr int buf_size = 1 << 26;
  char in_buf[buf_size], *in_cur = in_buf;
  char out_buf[buf_size], *out_cur = out_buf;
  #define gc() (*in_cur++)
  FastIO(){
    fread(in_buf, 1, buf_size, stdin);
  }
  ~FastIO(){
    fwrite(out_buf, 1, out_cur - out_buf, stdout);
  }
  void through(){
    while(*in_cur <= ' ') in_cur++;
  }
  template <class T, enable_if_integer<T>* = nullptr>
  inline void read(T &x){
    through();
    bool neg = false;
    int c = gc();
    if(c == '-') neg = true, c = gc();
    x = c^'0'; c = gc();
    while(c >= '0' && c <= '9') x = x*10 + (c^'0'), c = gc();
    if(neg) x = -x;
  }
  inline void read(string &x){
    through();
    char *p = in_cur;
    while(*p > ' ') p++;
    x = string(in_cur, p);
    in_cur = p;
  }
  inline void read(char &x){
    through();
    x = gc();
  }
  #undef gc
  #define pc(c) *out_cur++ = (c)
  template <class T, enable_if_integer<T>* = nullptr>
  inline void out(T x){
    static constexpr int tmp_size = sizeof(T)*5/2;
    static char tmp[tmp_size];
    if(!x){ pc('0'); return; }
    if(x < 0){ pc('-'); x = -x; }
    int idx = tmp_size;
    while(x >= 10000){
      idx -= 4;
      memcpy(tmp + idx, pr.num + (x % 10000)*4, 4);
      x /= 10000;
    }
    if(x < 100){
      if(x < 10){
        pc(x + '0');
      }else{
        pc(x/10 + '0');
        pc(x%10 + '0');
      }
    }else{
      if(x < 1000){
        memcpy(out_cur, pr.num + x*4 + 1, 3);
        out_cur += 3;
      }else{
        memcpy(out_cur, pr.num + x*4, 4);
        out_cur += 4;
      }
    }
    memcpy(out_cur, tmp + idx, tmp_size - idx);
    out_cur += tmp_size - idx;
  }
  inline void out(const string &s){
    copy(s.begin(), s.end(), out_cur);
    out_cur += s.size();
  }
  inline void out(const char c){ pc(c); }
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
} // namespace FastIO
using FastIO::io;
#define cin io
#define cout io