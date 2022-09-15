using ll = long long;

template <int mod>
struct Mint {
  ll x;
  constexpr Mint(ll x = 0) : x((x + mod) % mod){}
  static constexpr int get_mod(){ return mod; }
  constexpr Mint operator-() const{ return Mint(-x); }
  constexpr Mint operator+=(const Mint &a){
    if((x += a.x) >= mod) x -= mod;
    return *this;
  }
  constexpr Mint &operator++(){
    if(++x == mod) x = 0;
    return *this;
  }
  constexpr Mint operator++(int){
    Mint temp = *this;
    if(++x == mod) x = 0;
    return temp;
  }
  constexpr Mint &operator-=(const Mint &a){
    if((x -= a.x) < 0) x += mod;
    return *this;
  }
  constexpr Mint &operator--(){
    if(--x < 0) x += mod;
    return *this;
  }
  constexpr Mint operator--(int){
    Mint temp = *this;
    if(--x < 0) x += mod;
    return temp;
  }
  constexpr Mint &operator*=(const Mint &a){
    (x *= a.x) %= mod;
    return *this;
  }
  constexpr Mint operator+(const Mint &a) const{ return Mint(*this) += a; }
  constexpr Mint operator-(const Mint &a) const{ return Mint(*this) -= a; }
  constexpr Mint operator*(const Mint &a) const{ return Mint(*this) *= a; }
  constexpr Mint pow(ll t) const{
    if(!t) return 1;
    Mint res = 1, v = *this;
    while(t){
      if(t & 1) res *= v;
      v *= v;
      t >>= 1;
    }
    return res;
  }
  constexpr Mint inv() const{ return pow(mod - 2); }
  constexpr Mint &operator/=(const Mint &a){ return (*this) *= a.inv(); }
  constexpr Mint operator/(const Mint &a) const{ return Mint(*this) /= a; }
  constexpr bool operator==(const Mint &a) const{ return x == a.x; }
  constexpr bool operator!=(const Mint &a) const{ return x != a.x; }
  constexpr bool operator<(const Mint &a) const{ return x < a.x; }
  constexpr bool operator>(const Mint &a) const{ return x > a.x; }
  friend istream &operator>>(istream &is, Mint &a){ return is >> a.x; }
  friend ostream &operator<<(ostream &os, const Mint &a){ return os << a.x; }
};
using mint = Mint<1000000007>;