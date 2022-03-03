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
    assert(0 <= s);
    extention(s);
    std::fill(d, d + s, v);
    n = s;
  }
  void resize(const int &s, const T &v = T()){
    assert(0 <= s);
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
  void erase(const int &pos) noexcept{
    assert(0 <= pos && pos < n);
    std::move(d+pos+1, d+n, d+pos);
    n--;
  }
  void erase(const int &l, const int &r) noexcept{
    assert(0 <= l && l <= r && r <= n);
    std::move(d+r, d+n, d+l);
    n -= r - l;
  }
  void erase(const T *p) noexcept{ erase(p - d); }
  void erase(const T *lp, const T *rp) noexcept{ erase(lp - d, rp - d); }
  void insert(const int &pos, const T &v) noexcept{
    assert(0 <= pos && pos <= n);
    if(n == sz) extention(sz);
    std::rotate(d+pos, d+n, d+n+1);
    d[pos] = v; n++;
  }
  void insert(const int &pos, const T *lp, const T *rp) noexcept{
    assert(0 <= pos && pos <= n && lp <= rp);
    const int c = rp - lp;
    extention(n + c);
    std::rotate(d+pos, d+n, d+n+c);
    memcpy(d+pos, lp, c * sizeof(T));
    n += c;
  }
  void insert(const T *pt, const T &v) noexcept{ insert(pt - d, v); }
  void insert(T *pt, const T *lp, const T *rp) noexcept{ insert(pt - d, lp, rp); }
  template <int s>
  void insert(T *pt, const T (&a)[s]) noexcept{ insert(pt - d, a, a + s); }
  void sort(const bool &rev = false) noexcept{
    if(rev) std::sort(d, d + n, [&](const  T &a, const T &b){ return b < a; });
    else std::sort(d, d + n, [&](const T &a, const T &b){ return a < b; });
  }
  private:
  T *d = nullptr;
  int sz, n;
  void extention(const int &len) noexcept{
    sz = ceil_pow(len);
    d = (T*)realloc(d, sz * sizeof(T));
  }
  int ceil_pow(const int &v) const noexcept{ return v ? (1 << (32-__builtin_clz(v))) : 1; }
};