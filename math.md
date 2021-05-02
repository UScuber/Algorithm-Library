# Math
## 1. gcd
```cpp
T gcd(T a, T b)
```
- aとbの最大公約数を求める

- 計算量は O(log max(a,b))


## 2. lcm
```cpp
T lcm(T a, T b)
```
- aとbの最小公倍数を求める

- 計算量は O(log max(a,b))


## 3. modPow
```cpp
ll modPow(ll a, ll n, ll p)
```
- a^n mod p を求める
- 計算量は O(log n)


## 4. ext_gcd
```cpp
ll ext_gcd(ll a, ll b, ll &x, ll &y)
```
- ax + by = gcd(a,b) が成り立つ x, y を求める
- 計算量は O(log max(a,b))


## 5. crt(中国剰余定理)
```cpp
pair<ll,ll> crt(ll b1, ll m1, ll b2, ll m2)
```
- 下の二つが成り立つ最小の x を求める
  - x ≡ b1 (mod m1)
  - x ≡ b2 (mod m2)
- 戻り値は x と lcm(m1, m2)
- x が存在しない場合は -1 を返す
- 計算量は O(log max(m1,m2))


## 5. complex(複素数)
```cpp
complex(double re = 0, double img = 0)
```
- 実数部を re 虚数部を img として複素数を定義

### 演算
```cpp
complex a,b;
a + b;
a - b;
a * b;
a / b;

a += b;
a -= b;
a *= b;
a /= b;
```

### inv
```cpp
complex(x).inv()
```
- x * y = 1 となる y を求める
