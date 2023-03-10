# math

## 1. gcd, lcm
- 最大公約数、最大公倍数を求める
```cpp
T gcd(T a, T b)
T lcm(T a, T b)
```

## 2. modPow
- a^n mod.pを求める
```cpp
ll modPow(ll a, ll n, ll p)
```
- verified: https://atcoder.jp/contests/abc228/submissions/27797359

## 3. ext_gcd
- gcd(a,b)と、ax+by=gcd(a,b)を満たす整数x,yを求める
```cpp
ll ext_gcd(ll a, ll b, ll &x, ll &y)
```
- verified: https://atcoder.jp/contests/abc186/submissions/25334469

## 4. crt
- Chinese Remainder Theorem(中国剰余定理)
- x ≡ b_i mod.m_i (0 <= i < n)
- が成り立つ最小のxを求める
- 存在しない場合は{ 0, 0 }を返す
```cpp
pair<ll, ll> crt(const vector<ll> &r, const vector<ll> &m)
```
- verified: https://atcoder.jp/contests/abc193/submissions/25333960

## 5. euler
- オイラー関数
- φ(n)を求める
- O(sqrt(n))
```cpp
ll euler(ll n)
```
- verified: https://atcoder.jp/contests/abc212/submissions/24730963

## 6. matrix
- 行列の計算を行う
- n×n行列または、n×m行列を生成
```cpp
matrix(int n)
matrix(int n, int m)
```
- A^tを求める
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
- verified(product): https://judge.yosupo.jp/submission/67877
- verified(determinant): https://judge.yosupo.jp/submission/67882

## 7. mint
- 計算途中でmodをとってくれる型
```cpp
mint(ll x = 0)
```
- 逆元をとる
```cpp
mint mint::inv()
```
- x^t mod.pを求める
```cpp
mint mint::pow(ll t)
```

## 8. combination
- nCr, nPr, nHr の計算をする
- lenの値でnの上限を設定し、プログラム開始時に前計算を行う
- 前計算: O(N), nCr: O(1)
```cpp
```
- nCrを求める
```cpp
mint C(int n, int r)
```
- nPrを求める
```cpp
mint C(int n, int r)
```
- nHrを求める
```cpp
mint H(int n, int r)
```

## 9. nCr mod P
- nCr mod P を求める(Pは素数)
- lenの値でnの上限を設定し、プログラム開始時に前計算を行う
- 前計算: O(min(max(n,r),P)), nCr: O(log_P max(n,r))
```cpp
```
- nCrを求める
```cpp
mint C(int n, int r)
```
- nHrを求める
```cpp
mint H(int n, int r)
```

## 10. range_factorization
- 区間[L,R)の素因数分解をする
- O((R-L)logR)
```cpp
range_factorization(ll L, ll R)
```
- 素因数の配列を返す
```cpp
vector<ll> range_factorization::factor(ll n)
```
- verified: https://atcoder.jp/contests/abc227/submissions/27264629

## 11. range_eratosthenes
- 区間[L,R)の素数判定を行う
- O((R-L)log(logR))
```cpp
range_eratosthenes(ll L, ll R)
```
- 素数判定
```cpp
bool range_eratosthenes::is_prime(const ll &n)
```

## 12. frac
- 分数での計算を行う
```cpp
frac(const ll a = 0, const ll b = 1)
```
