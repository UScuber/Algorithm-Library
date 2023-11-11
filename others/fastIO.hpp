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
  using enable_if_integer = enable_if_t<is_integral<T>::value || is_same<T, __int128_t> || is_same<T, __uint128_t>::value>;
  static constexpr int buf_size = 1 << 20;
  static constexpr int rem = 1 << 6;
  char in_buf[buf_size], *in_cur = in_buf;
  char out_buf[buf_size], *out_cur = out_buf;
  FastIO(){
    fread(in_buf, 1, buf_size, stdin);
  }
  ~FastIO(){
    fwrite(out_buf, 1, out_cur - out_buf, stdout);
  }
  void load(){
    const int len = in_buf + buf_size - in_cur;
    memmove(in_buf, in_cur, len);
    in_cur = in_buf;
    fread(in_buf + len, 1, buf_size - len, stdin);
  }
  void flush(){
    fwrite(out_buf, 1, out_cur - out_buf, stdout);
    out_cur = out_buf;
  }
  void through(){
    if(in_cur - in_buf >= buf_size - rem) load();
    while(*in_cur <= ' ') in_cur++;
    assert(in_buf <= in_cur && in_cur < in_buf + buf_size);
  }
  #define gc() (*in_cur++)
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
    x.clear();
    while(true){
      char *p = in_cur;
      while(*p > ' ' && p - in_buf < buf_size - rem) p++;
      copy(in_cur, p, back_inserter(x));
      in_cur = p;
      if(*p <= ' ') break;
      load();
    }
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
    if(out_cur - out_buf >= buf_size - rem) flush();
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
    flush();
    fwrite(s.c_str(), 1, s.size(), stdout);
  }
  inline void out(const char c){
    if(out_cur - out_buf >= buf_size - rem) flush();
    pc(c);
  }
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