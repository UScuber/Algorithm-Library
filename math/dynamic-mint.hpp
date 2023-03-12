using ull = unsigned long long;

unsigned int mod;
ull bar;

struct mint {
  using uint = unsigned int;
  uint x;
  mint(const uint &x = 0) : x((x+mod)%mod){}
  mint operator-() const{ return mint(mod - x); }
  mint operator+=(const mint &a){
    if((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint &operator++(){
    if(++x == mod) x = 0;
    return *this;
  }
  mint operator++(int){
    mint res = *this;
    ++*this;
    return res;
  }
  mint &operator-=(const mint &a){
    if(x >= a.x) x -= a.x;
    else x += mod - a.x;
    return *this;
  }
  mint &operator--(){
    if(!x) x = mod - 1;
    else x--;
    return *this;
  }
  mint operator--(int){
    mint res = *this;
    --*this;
    return res;
  }
  mint &operator*=(const mint &a){
    ull z = (ull)x * a.x;
    ull t = (ull)(((unsigned __int128)z * bar) >> 64);
    x = (uint)(z - t*mod);
    if(mod <= x) x += mod;
    return *this;
  }
  mint operator+(const mint &a) const{ return mint(*this) += a; }
  mint operator-(const mint &a) const{ return mint(*this) -= a; }
  mint operator*(const mint &a) const{ return mint(*this) *= a; }
  mint pow(ull t) const{
    if(!t) return 1;
    mint res = 1, v = *this;
    while(t){
      if(t & 1) res *= v;
      v *= v;
      t >>= 1;
    }
    return res;
  }
  mint &operator/=(const mint &a){ x /= a.x; return *this; }
  mint operator/(const mint &a) const{ return mint(*this) /= a; }
  bool operator==(const mint &a) const{ return x == a.x; }
  bool operator!=(const mint &a) const{ return x != a.x; }
  bool operator<(const mint &a) const{ return x < a.x; }
  bool operator>(const mint &a) const{ return x > a.x; }
  friend istream &operator>>(istream &is, mint &a){ return is >> a.x; }
  friend ostream &operator<<(ostream &os, const mint &a){ return os << a.x; }
};
void init(){
  bar = (ull)-1 / mod + 1;
}