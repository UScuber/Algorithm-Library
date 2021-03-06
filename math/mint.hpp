#define mod 1000000007
using ll = long long;

struct mint{
  ll x;
  mint(ll x = 0) : x((x + mod) % mod){}
  mint operator-() const{ return mint(-x); }
  mint operator+=(const mint &a){
    if((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint &operator++(){
    if(++x == mod) x = 0;
    return *this;
  }
  mint operator++(int){
    mint temp = *this;
    if(++x == mod) x = 0;
    return temp;
  }
  mint &operator-=(const mint &a){
    if((x -= a.x) < 0) x += mod;
    return *this;
  }
  mint &operator--(){
    if(--x < 0) x += mod;
    return *this;
  }
  mint operator--(int){
    mint temp = *this;
    if(--x < 0) x += mod;
    return temp;
  }
  mint &operator*=(const mint &a){
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint &a) const{ return mint(*this) += a; }
  mint operator-(const mint &a) const{ return mint(*this) -= a; }
  mint operator*(const mint &a) const{ return mint(*this) *= a; }
  mint pow(ll t) const{
    if(!t) return 1;
    mint res = 1, v = *this;
    while(t){
      if(t & 1) res *= v;
      v *= v;
      t >>= 1;
    }
    return res;
  }
  mint inv() const{ return pow(mod - 2); }
  mint &operator/=(const mint &a){ return (*this) *= a.inv(); }
  mint operator/(const mint &a) const{ return mint(*this) /= a; }
  bool operator==(const mint &a) const{ return x == a.x; }
  bool operator<(const mint &a) const{ return x < a.x; }
  bool operator>(const mint &a) const{ return x > a.x; }
  bool operator<=(const mint &a) const{ return x <= a.x; }
  bool operator>=(const mint &a) const{ return x >= a.x; }
  friend istream &operator>>(istream &is, mint &a){ return is >> a.x; }
  friend ostream &operator<<(ostream &os, const mint &a){ return os << a.x; }
};