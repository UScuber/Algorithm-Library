struct frac {
  ll a,b;
  frac(const ll a = 0, const ll b = 1) : a(a), b(b){}
  frac &operator*=(const ll &d){
    a *= d;
    return *this;
  }
  frac &operator*=(const frac &d){
    a *= d.a; b *= d.b;
    reduce();
    return *this;
  }
  frac &operator/=(const frac &d){
    assert(d); //0 division
    a *= d.b; b *= d.a;
    reduce();
    return *this;
  }
  frac &operator+=(const frac &d){
    ll g = gcd(abs(b), abs(d.b));
    ll t = b / g * d.b; //lcm(abs(a), abs(b))
    a = a*d.b/g + d.a*b/g;
    b = t;
    reduce();
    return *this;
  }
  frac &operator-=(const frac &d){
    ll g = gcd(abs(b), abs(d.b));
    ll t = b / g * d.b; //lcm(abs(a), abs(b))
    a = a*d.b/g - d.a*b/g;
    b = t;
    reduce();
    return *this;
  }
  frac operator*(const frac &d) const{ return frac(*this) *= d; }
  frac operator/(const frac &d) const{ return frac(*this) /= d; }
  frac operator+(const frac &d) const{ return frac(*this) += d; }
  frac operator-(const frac &d) const{ return frac(*this) -= d; }
  bool operator!(){ return !a; }
  bool operator==(const frac &d) const{ return a == d.a && b == d.b;}
  bool operator<(const frac &d) const{ return (double)a/b < (double)d.a/d.b; }
  bool operator>(const frac &d) const{ return (double)a/b > (double)d.a/d.b; }
  operator bool() const{ return !a; }
  void reduce(){
    ll g = gcd(abs(a), abs(b));
    if(a < 0 && b < 0) g = -g;
    a /= g; b /= g;
  }
  ll gcd(const ll &a, const ll &b){
    if(!b) return a;
    return gcd(b, a % b);
  }
  void debug(){ cerr << a << "/" << b << " "; }
  friend istream &operator>>(istream &is, frac &d){ return is >> d.a; }
  friend ostream &operator<<(ostream &os, const frac &d){
    printf("%lf", (double)d.a / d.b);
    /*
    if(!d.a) os << 0;
    else if(d.b < 0){
      if(d.b == -1) os << d.a;
      else os << d.a << "/" << d.b;
    }else{
      if(d.b == 1) os << d.a;
      else os << d.a << "/" << d.b;
    }
    */
    return os;
  }
};