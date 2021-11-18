# math

## 1. gcd, lcm
- 最大公約数、最大公倍数を求める
```cpp
T gcd(T a, T b)
T lcm(T a, T b)
```

## 2. modPow
- $a^n$ mod p を求める
```cpp
ll modPow(ll a, ll n, ll p)
```

## 3. ext_gcd
- $gcd(a,b)$と、$ax+by=gcd(a,b)$を満たす整数$x,y$を求める
```cpp
ll ext_gcd(ll a, ll b, ll &x, ll &y)
```

## 4. crt
- Chinese Remainder Theorem(中国剰余定理)
- $x \equiv b_1 \mod m_1$
- $x \equiv b_2 \mod m_2$
- が成り立つ最小の$x$を求める
- 存在しない場合は{0, -1}を返す
```cpp
pair<ll, ll> crt(ll b1, ll m1, ll b2, ll m2)
```

## 5. euler
- オイラー関数
- $\varphi(n)$を求める
- $O(\sqrt n)$
```cpp
ll euler(ll n)
```

## 6. matrix
- 行列の計算を行う
- $n \times n$行列または、$n \times m$行列を生成
```cpp
matrix(int n)
matrix(int n, int m)
```
- $A^t$を求める
```cpp
matrix matrix::pow(ll t)
```
- 行列式を求める
```cpp
matrix matrix::det()
```
- 逆行列を求める
- 存在しない場合は、空の配列が返される
```cpp
matrix matrix::inv()
```

## 7. mint
- 計算途中でmodをとってくれる型
```cpp
mint(ll x = 0)
```
- 逆元をとる
```cpp
mint mint::inv()
```
- $x^t \mod p$を求める
```cpp
mint mint::pow(ll t)
```

## 8. range_factorization
- 区間$[L,R)$の素因数分解をする
- $O((R-L)logR)$
```cpp
range_factorization(ll L, ll R)
```
- 素因数の配列を返す
```cpp
vector<ll> range_factorization::factor(ll n)
```

## 9. range_eratosthenes
- 区間$[L,R)$の素数判定を行う
- $O((R-L)log log R)$
```cpp
range_eratosthenes(ll L, ll R)
```
- 素数判定
```cpp
bool range_eratosthenes::is_prime(const ll &n)
```

## 10. frac
- 分数での計算を行う
```cpp
frac(const ll a = 0, const ll b = 1)
```