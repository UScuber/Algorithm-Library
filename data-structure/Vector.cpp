#include <cassert>
#include <string>

template <class T>
struct Vector {
  Vector() : sz(0), n(0){}
  explicit Vector(const int &s, const T &v = T()) noexcept : sz(s), n(s){
    assert(0 <= s);assert(s <= 1000000000);
    if(s) d = (T*)malloc(s * sizeof(T));
    std::fill(d, d + sz, v);
  }
  Vector(const Vector<T> &a) noexcept{ *this = a; }
  Vector(Vector<T> &&a) noexcept{ *this = a; }
  template <int s>
  Vector(const T (&a)[s]) noexcept{
    extention(s);
    n = s;
    memcpy(d, a, s * sizeof(T));
  }
  ~Vector(){ free(d); }
  T &operator[](const int &i) noexcept{
    assert(0 <= i);assert(i < n);
    return d[i];
  }
  Vector<T> &operator=(const Vector<T> &a) noexcept{
    if(!a.sz){ clear(); return *this; }
    extention(a.n);
    n = a.n; sz = a.sz;
    d = (T*)realloc(d, sz * sizeof(T));
    memcpy(d, a.d, n * sizeof(T));
    return *this;
  }
  Vector<T> &operator=(Vector<T> &&a) noexcept{
    free(d);
    d = a.d; a.d = nullptr;
    n = a.n; sz = a.sz;
    return *this;
  }
  void reserve(const int &s){
    assert(0 <= s);
    extention(s);
    if(s < n) n = s;
  }
  void assign(const int &s, const T &v){
    extention(s);
    std::fill(d, d + sz, v);
    n = s;
  }
  void resize(const int &s, const T &v = T()){
    extention(s);
    if(n < s) std::fill(d + n, d + s, v);
    n = s;
  }
  void emplace_back(const T &v) noexcept{ pushback(v); }
  void push_back(const T &v) noexcept{
    if(n == sz) extention(sz);
    d[n++] = v;
  }
  void pop_back() noexcept{ assert(n >= 1); n--; }
  T &front() noexcept{ assert(n >= 1); return d[0]; }
  T &back() noexcept{ assert(n >= 1); return d[n - 1]; }
  void swap(Vector<T> &a) noexcept{ std::swap(n,a.n); std::swap(sz,a.sz); std::swap(d,a.d); }
  void clear() noexcept{ free(d); d = nullptr; sz = n = 0; }
  int size() const noexcept{ return n; }
  int capacity() const noexcept{ return sz; }
  bool empty() const noexcept{ return !n; }
  T *begin() const noexcept{ return d; }
  T *end() const noexcept{ return d + n; }
  void erase(T *p) noexcept{
    assert(d <= p && p < d+n);
    n--;
    for(; p < d+n; p++) *p = move(*(p+1));
  }
  void erase(T *lp, const T *rp) noexcept{
    assert(d <= lp && lp <= rp && rp <= d+n);
    const int c = rp - lp;
    n -= c;
    for(; lp < d+n; lp++) *lp = move(*(lp+c));
  }
  void insert(T *pt, const T &v) noexcept{
    assert(d <= pt && pt <= d+n);
    if(n == sz) extention(sz);
    for(T *p = d+n; p != pt; p--) *p = move(*(p-1));
    *pt = v; n++;
  }
  void insert(T *pt, const T *lp, const T *rp) noexcept{
    assert(d <= pt && pt <= d+n);
    const int c = rp - lp;
    extention(n + c);
    for(T *p = d+n; p-- != pt;) *(p+c) = move(*p);
    memcpy(pt, lp, c * sizeof(T));
    n += c;
  }
  template <int s>
  void insert(T *pt, const T (&a)[s]) noexcept{ insert(pt, a, a + s); }
  private:
  T *d = nullptr;
  int sz; //配列dの長さ
  int n; //代入されているところまでの長さ
  void extention(const int &len) noexcept{
    sz = ceil_pow(len);
    d = (T*)realloc(d, sz * sizeof(T));
  }
  int ceil_pow(const int &v) const noexcept{ return v ? (1 << (32-__builtin_clz(v))) : 1; }
};