#include "../template/template.hpp"

using Real = double;

constexpr Real EPS = 1e-10;
constexpr Real PI = 3.141592653589793238462643383279L;
constexpr Real INF = 1e18;

inline constexpr bool eq(const Real &a, const Real &b){
  return fabs(b - a) < EPS;
}

struct Point {
  constexpr Point(const Real &_x=0, const Real &_y=0) : x(_x), y(_y){}
  constexpr Real &real(){ return x; }
  constexpr Real &imag(){ return y; }
  constexpr Real real() const{ return x; }
  constexpr Real imag() const{ return y; }
  constexpr Point operator-() const{ return Point(-x, -y); }
  constexpr Point &operator+=(const Point &p){ x += p.real(); y += p.imag(); return *this; }
  constexpr Point &operator-=(const Point &p){ x -= p.real(); y -= p.imag(); return *this; }
  constexpr Point &operator*=(const Real &a){ x *= a; y *= a; return *this; }
  constexpr Point &operator*=(const Point &p){ return *this = *this * p; }
  constexpr Point &operator/=(const Real &a){ assert(!eq(a, 0.0)); x /= a; y /= a; return *this; }
  constexpr Point operator+(const Point &p) const{ return Point(*this) += p; }
  constexpr Point operator-(const Point &p) const{ return Point(*this) -= p; }
  constexpr Point operator*(const Real &p) const{ return Point(*this) *= p; }
  constexpr Point operator*(const Point &p) const{ return Point(x*p.x - y*p.y, y*p.x + x*p.y); }
  constexpr Point operator/(const Real &p) const{ return Point(*this) /= p; }
  constexpr bool operator==(const Point &p) const{ return eq(x, p.real()) && eq(y, p.imag()); }
  constexpr bool operator!=(const Point &p) const{ return !(*this == p); }
  constexpr bool operator<(const Point &p) const{
    if(x != p.real()) return x < p.real();
    return y < p.imag();
  }
  constexpr bool operator>(const Point &p) const{
    if(x != p.real()) return x > p.real();
    return y > p.imag();
  }
  constexpr Real norm() const{ return x*x + y*y; }
  constexpr Real abs() const{ return sqrt(norm()); }
  constexpr Point conj() const{ return Point(x, -y); }
  constexpr Real arg() const{ return atan2(y, x); }
  friend istream &operator>>(istream &is, Point &p){ return is >> p.real() >> p.imag(); }
  friend ostream &operator<<(ostream &os, const Point &p){ return os << p.real() << " " << p.imag(); }
private:
  Real x,y;
};

Point polar(const Real &r, const Real &theta){
  return Point(r*cos(theta), r*sin(theta));
}
constexpr Real real(const Point &p){ return p.real(); }
constexpr Real imag(const Point &p){ return p.imag(); }
constexpr Real norm(const Point &p){ return p.norm(); }
constexpr Real abs(const Point &p){ return p.abs(); }
constexpr Point conj(const Point &p){ return p.conj(); }
constexpr Real arg(const Point &p){ return p.arg(); }
inline constexpr Real cross(const Point &a, const Point &b){
  return a.real() * b.imag() - a.imag() * b.real();
}
inline constexpr Real dot(const Point &a, const Point &b){
  return a.real() * b.real() + a.imag() * b.imag();
}
constexpr Point rotate(const Point &p, const Real &theta){
  return Point(cos(theta)*p.real() - sin(theta)*p.imag(), sin(theta)*p.real() + cos(theta)*p.imag());
}
constexpr Real rad2deg(const Real &theta){ return theta*180.0/PI; }
constexpr Real deg2rad(const Real &theta){ return theta*PI/180.0; }

// calc <ABC
constexpr Real get_angle(const Point &a, const Point &b, const Point &c){
  Real alpha = arg(b - a), beta = arg(c - b);
  if(alpha > beta) swap(alpha, beta);
  const Real theta = beta - alpha;
  return min(theta, PI*2 - theta);
}
constexpr int type(const Point &a){
  if(eq(a.real(), 0) && eq(a.imag(), 0)) return 0;
  if(a.imag() > -EPS || (eq(a.imag(), 0) && a.real() < EPS)) return 1;
  return -1;
}

struct Line {
  Point a,b;
  constexpr Line(){}
  constexpr Line(const Point &_a, const Point &_b) : a(_a), b(_b){}
  constexpr Line(const Real &A, const Real &B, const Real &C){
    if(eq(A, 0)) a = Point(0, C/B), b = Point(1, C/B);
    else if(eq(B, 0)) a = Point(C/A, 0), b = Point(C/A, 1);
    else a = Point(0, C/B), b = Point(C/A, 0);
  }
  friend istream &operator>>(istream &is, Line &l){ return is >> l.a >> l.b; }
  friend ostream &operator<<(ostream &os, const Line &l){ return os << l.a << " to " << l.b; }
};

struct Segment {
  Point a,b;
  constexpr Segment(){}
  constexpr Segment(const Point &_a, const Point &_b) : a(_a), b(_b){}
  friend istream &operator>>(istream &is, Segment &l){ return is >> l.a >> l.b; }
  friend ostream &operator<<(ostream &os, const Segment &l){ return os << l.a << " to " << l.b; }
};

struct Circle {
  Point p;
  Real r;
  Circle(){}
  constexpr Circle(const Point &_p, const Real &_r) : p(_p), r(_r){}
};

using Points = vector<Point>;
using Lines = vector<Line>;
using Segments = vector<Segment>;
using Polygon = vector<Point>;

// 点の回転方向
constexpr int ccw(const Point &a, Point b, Point c){
  b -= a, c -= a;
  if(cross(b, c) > EPS) return +1;  // "a → b で 反時計方向におれて c"
  if(cross(b, c) < -EPS) return -1; // "a → b で 時計方向におれて c"
  if(dot(b, c) < 0) return +2;      // "c -- a -- bで一直線上"
  if(norm(b) < norm(c)) return -2;  // "a -- b -- cで一直線上"
  return 0;                         // "a -- c -- bで一直線上"
}
// 偏角
constexpr bool is_large(const Point &a, const Point &b){
  if(type(a) != type(b)) return type(a) < type(b);
  return cross(a, b) > 0;
}
// 平行
constexpr bool parallel(const Line &a, const Line &b){
  return eq(cross(a.b - a.a, b.b - b.a), 0);
}
// 垂直
constexpr bool orthogonal(const Line &a, const Line &b){ 
  return eq(dot(a.a - a.b, b.a - b.b), 0);
}
// 直線 l に p から垂線を引いた交点を求める
constexpr Point projection(const Line &l, const Point &p){
  const Real t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
  return l.a + (l.a - l.b) * t;
}
constexpr Point projection(const Segment &s, const Point &p){
  const Real t = dot(p - s.a, s.a - s.b) / norm(s.a - s.b);
  return s.a + (s.a - s.b) * t;
}
// 直線 l を対称軸として点 p と線対称にある点を求める
constexpr Point reflection(const Line &l, const Point &p){
  return p + (projection(l, p) - p) * 2;
}
constexpr Point projection(const Point &p, const Line &l){ return projection(l, p); }
constexpr Point projection(const Point &p, const Segment &s){ return projection(s, p); }
constexpr Point reflection(const Point &p, const Line &l){ return projection(l, p); }

// 交差判定
constexpr bool intersect(const Line &l, const Point &p){
  return abs(ccw(l.a, l.b, p)) != 1;
}
constexpr bool intersect(const Line &l, const Line &m){
  return abs(cross(l.b - l.a, m.b - m.a)) > EPS || abs(cross(l.b - l.a, m.b - l.a)) < EPS;
}
constexpr bool intersect(const Segment &s, const Point &p){
  return ccw(s.a, s.b, p) == 0;
}
constexpr bool intersect(const Line &l, const Segment &s){
  return cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < EPS;
}

constexpr Real distance(const Line &l, const Point &p);
constexpr bool intersect(const Circle &c, const Line &l){
  return distance(l, c.p) <= c.r + EPS;
}
constexpr bool intersect(const Circle &c, const Point &p){
  return abs(abs(p - c.p) - c.r) < EPS;
}
constexpr bool intersect(const Segment &s, const Segment &t){
  return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}
constexpr bool intersect(const Point &p, const Line &l){ return intersect(l, p); }
constexpr bool intersect(const Point &p, const Segment &s){ return intersect(s, p); }
constexpr bool intersect(const Segment &s, const Line &l){ return intersect(l, s); }
constexpr bool intersect(const Line &l, const Circle &c){ return intersect(c, l); }
constexpr bool intersect(const Point &p, const Circle &c){ return intersect(c, p); }

constexpr Real distance(const Point &a, const Point &b){
  return abs(a - b);
}
constexpr Real distance(const Line &l, const Point &p){
  return abs(cross(l.b-l.a, p-l.a) / abs(l.b - l.a));
}
constexpr Real distance(const Line &l, const Line &m){
  return intersect(l, m) ? 0 : distance(l, m.a);
}
constexpr Real distance(const Segment &s, const Point &p){
  if(dot(s.b-s.a, p-s.a) < 0) return abs(p - s.a);
  if(dot(s.a-s.b, p-s.b) < 0) return abs(p - s.b);
  return distance(Line(s.a, s.b), p);
}
constexpr Real distance(const Segment &a, const Segment &b){
  if(intersect(a, b)) return 0;
  return min({ distance(a, b.a), distance(a, b.b), distance(b, a.a), distance(b, a.b) });
}
constexpr Real distance(const Line &l, const Segment &s){
  if(intersect(l, s)) return 0;
  return min(distance(l, s.a), distance(l, s.b));
}
constexpr Real distance(const Point &p, const Line &l){ return distance(l, p); }
constexpr Real distance(const Point &p, const Segment &s){ return distance(s, p); }
constexpr Real distance(const Segment &s, const Line &l){ return distance(l, s); }

// 交差する数
constexpr int intersect(const Circle &c, const Segment &s){
  if(norm(projection(s, c.p) - c.p) - c.r*c.r > EPS) return 0;
  const Real d1 = abs(c.p - s.a), d2 = abs(c.p - s.b);
  if(d1 < c.r + EPS && d2 < c.r + EPS) return 0;
  if((d1 < c.r - EPS && d2 > c.r + EPS) || (d1 > c.r + EPS && d2 < c.r - EPS)) return 1;
  const Point h = projection(s, c.p);
  if(dot(s.a - h, s.b - h) < 0) return 2;
  return 0;
}
constexpr int intersect(const Segment &s, const Circle &c){ return intersect(c, s); }
//共通接線の数
constexpr int intersect(Circle c1, Circle c2){
  if(c1.r < c2.r) swap(c1, c2);
  const Real d = abs(c1.p - c2.p);
  if(c1.r + c2.r < d) return 4; //離れている
  if(eq(c1.r + c2.r, d)) return 3; //外接
  if(c1.r - c2.r < d) return 2; //2点で交わる
  if(eq(c1.r - c2.r, d)) return 1; //内接
  return 0; //内包
}

//交点の座標
constexpr Point crosspoint(const Line &l, const Line &m){
  const Real A = cross(l.b - l.a, m.b - m.a);
  const Real B = cross(l.b - l.a, l.b - m.a);
  if(eq(abs(A), 0.0) && eq(abs(B), 0.0)) return m.a;
  if(eq(abs(A), 0.0)) throw "no crosspoint";
  return m.a + (m.b - m.a) * (B/A);
}
constexpr Point crosspoint(const Segment &l, const Segment &m){
  if(!intersect(l, m)) throw "no crosspoint";
  return crosspoint(Line(l.a, l.b), Line(m.a, m.b));
}
///////////
Points crosspoint(const Circle &c, const Line &l){
  const Point pr = projection(l, c.p);
  const Real d = distance(l, c.p) - c.r;
  if(d > 0) return {};
  if(eq(d, 0)) return { pr };
  const Point e = (l.b - l.a) / abs(l.b - l.a);
  const Real base = sqrt(c.r*c.r - norm(pr - c.p));
  return { pr - e*base, pr + e*base };
}
///////////
Points crosspoint(const Circle &c, const Segment &s){
  const Line aa(s.a, s.b);
  const Points res = crosspoint(c, aa);
  if(res.empty() || intersect(c, s) == 2) return res;
  if(dot(s.a - res[0], s.b - res[0]) < 0) return { res[0] };
  return { res.back() };
}

///////////
//中心は異なる座標,一つの交点の場合は同じ座標を二つ出力する
pair<Point,Point> crosspoint(const Circle &c1, const Circle &c2){
  const Real d = abs(c1.p - c2.p);
  const Real a = acos((c1.r*c1.r + d*d - c2.r*c2.r) / (c1.r*d*2));
  const Real t = arg(c2.p - c1.p);
  const Point p1 = c1.p + polar(c1.r, t + a);
  const Point p2 = c1.p + polar(c1.r, t - a);
  return { p1, p2 };
}
//点 p を通る円 c の接線, 点は円の内部,円上にない
pair<Point,Point> tangent(const Circle &c1, const Point &p2){
  return crosspoint(c1, Circle(p2, sqrt(norm(c1.p - p2) - c1.r*c1.r)));
}
// 円 c1, c2 の共通接線
Lines tangent(Circle c1, Circle c2){
  Lines res;
  if(c1.r < c2.r) swap(c1, c2);
  const Real g = norm(c1.p - c2.p);
  if(eq(g, 0)) return res;
  const Point u = (c2.p - c1.p) / sqrt(g);
  const Point v = rotate(u, PI * 0.5);
  for(const int s : { -1,1 }){
    const Real h = (c1.r + s*c2.r) / sqrt(g);
    if(eq(1 - h*h, 0)){
      res.emplace_back(c1.p + u*c1.r, c1.p + (u + v)*c1.r);
    }else if(1 - h*h > 0){
      const Point uu = u*h, vv = v*sqrt(1 - h*h);
      res.emplace_back(c1.p + (uu + vv)*c1.r, c2.p - (uu + vv)*c2.r*s);
      res.emplace_back(c1.p + (uu - vv)*c1.r, c2.p - (uu - vv)*c2.r*s);
    }
  }
  return res;
}

bool is_convex(const Polygon &p){
  const int n = p.size();
  for(int i = 0; i < n; i++){
    if(ccw(p[i ? i-1 : n-1], p[i], p[i < n-1 ? i+1 : 0]) == -1) return false;
  }
  return true;
}
// 凸包
Polygon convex_hull(Polygon &p){
  const int n = p.size();
  int k = 0;
  if(n <= 2) return p;
  sort(p.begin(), p.end());
  Points ch(n*2);
  for(int i = 0; i < n; ch[k++] = p[i++]){
    while(k >= 2 && cross(ch[k-1] - ch[k-2], p[i] - ch[k-1]) < EPS) k--;
  }
  for(int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--]){
    while(k >= t && cross(ch[k-1] - ch[k-2], p[i] - ch[k-1]) < EPS) k--;
  }
  ch.resize(k - 1);
  return ch;
}

// 多角形と点の包含判定
enum {
  OUT, ON, IN
};
int contains(const Polygon &Q, const Point &p){
  const int n = Q.size();
  bool in = false;
  for(int i = 0; i < n; i++){
    Point a = Q[i] - p, b = Q[i < n-1 ? i+1 : 0] - p;
    if(a.imag() > b.imag()) swap(a, b);
    if(a.imag() <= 0 && 0 < b.imag() && cross(a, b) < 0) in = !in;
    if(cross(a, b) == 0 && dot(a, b) <= 0) return ON;
  }
  return in ? IN : OUT;
}

// 直線 l.a-l.b で切断しその左側にできる凸多角形を返す
Polygon convex_cut(const Polygon &U, const Line &l){
  const int n = U.size();
  Polygon res;
  for(int i = 0; i < n; i++){
    const Point now = U[i], nxt = U[i < n-1 ? i+1 : 0];
    if(ccw(l.a, l.b, now) != -1) res.push_back(now);
    if(ccw(l.a, l.b, now) * ccw(l.a, l.b, nxt) < 0){
      res.push_back(crosspoint(Line(now, nxt), l));
    }
  }
  return res;
}

// 多角形の面積
Real area(const Polygon &p){
  const int n = p.size();
  Real A = 0;
  for(int i = 0; i < n; i++){
    A += cross(p[i], p[i < n-1 ? i+1 : 0]);
  }
  return A * 0.5;
}

// 円と多角形の共通部分の面積
Real area(const Polygon &p, const Circle &c){
  const int n = p.size();
  if(n < 3) return 0;
  function<Real(Circle, Point, Point)> cross_area = [&](const Circle &c, const Point &a, const Point &b){
    const Point va = c.p - a, vb = c.p - b;
    const Real f = cross(va, vb);
    Real res = 0;
    if(eq(f, 0)) return res;
    if(max(abs(va), abs(vb)) < c.r + EPS) return f;
    if(distance(Segment(a, b), c.p) > c.r - EPS) return c.r*c.r * arg(vb*conj(va));
    const Points u = crosspoint(c, Segment(a, b));
    assert(!u.empty());
    Points tot{ a, u.front(), u.back(), b };
    for(int i = 0; i + 1 < (int)tot.size(); i++){
      res += cross_area(c, tot[i], tot[i + 1]);
    }
    return res;
  };
  Real A = 0;
  for(int i = 0; i < n; i++){
    A += cross_area(c, p[i], p[i < n-1 ? i+1 : 0]);
  }
  return A * 0.5;
}
Real area(const Circle &a, const Circle &b){
  Real d = abs(a.p - b.p);
  if(d + EPS >= a.r + b.r) return 0;
  if(d <= abs(a.r - b.r)) return PI * min(a.r,b.r)*min(a.r,b.r);
  d *= d;
  const Real p1 = a.r*a.r - b.r*b.r + d;
  const Real p2 = b.r*b.r - a.r*a.r + d;
  const Real temp = sqrt(4*d*a.r*a.r - p1*p1);
  const Real s1 = a.r*a.r * atan2(temp, p1);
  const Real s2 = b.r*b.r * atan2(sqrt(d * b.r*b.r*4 - p2*p2), p2);
  return s1 + s2 - temp * 0.5;
}

// 凸多角形の直径(最遠頂点対間距離)
Real convex_diameter(const Polygon &p){
  const int n = p.size();
  int is = 0, js = 0;
  for(int i = 1; i < n; i++){
    if(p[i].imag() > p[is].imag()) is = i;
    if(p[i].imag() < p[js].imag()) js = i;
  }
  Real maxdis = norm(p[is] - p[js]);
  int maxi = is, maxj = js, i = is, j = js;
  do {
    if(cross(p[i < n-1 ? i+1 : 0] - p[i], p[j < n-1 ? j+1 : 0] - p[j]) >= 0){
      if(++j >= n) j = 0;
    }else{
      if(++i >= n) i = 0;
    }
    if(norm(p[i] - p[j]) > maxdis){
      maxdis = norm(p[i] - p[j]);
      maxi = i;
      maxj = j;
    }
  } while(i != is || j != js);
  return sqrt(maxdis);
}

// 最近点対
Real closest_pair(Points ps){
  if(ps.size() <= 1) throw 0;
  sort(ps.begin(), ps.end());
  auto compare_y = [&](const Point &a, const Point &b){
    return imag(a) < imag(b);
  };
  vector<Point> beet(ps.size());
  function<Real(int,int)> rec = [&](int left, int right){
    if(right - left <= 1) return INF;
    const int mid = (left + right) / 2;
    const Real x = real(ps[mid]);
    Real res = min(rec(left, mid), rec(mid, right));
    inplace_merge(ps.begin()+left, ps.begin()+mid, ps.begin()+right, compare_y);
    int ptr = 0;
    for(int i = left; i < right; i++){
      if(abs(real(ps[i]) - x) >= res) continue;
      for(int j = 0; j < ptr; j++){
        const Point luz = ps[i] - beet[ptr - j - 1];
        if(imag(luz) >= res) break;
        res = min(res, abs(luz));
      }
      beet[ptr++] = ps[i];
    }
    return res;
  };
  return rec(0, (int)ps.size());
}

//a==bの判定 O(n^3logn)
bool equal(Points a, Points b){
  const int n = a.size();
  if(n != (int)b.size()) return false;
  if(n == 1) return true;
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
    if(i == j) continue;
    if(norm(a[1]-a[0]) != norm(b[j]-b[i])) continue;
    auto move = [&](Points p, const Point &o, const Point &r){
      for(int i = 0; i < n; i++){
        p[i] -= o;
        p[i] *= r;
      }
      sort(p.begin(), p.end());
      return p;
    };
    vector<Point> res_a = move(a, a[0], b[j]-b[i]);
    vector<Point> res_b = move(b, b[i], a[1]-a[0]);
    if(res_a == res_b) return true;
  }
  return false;
}