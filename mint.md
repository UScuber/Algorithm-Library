# mint(modint)

## コンストラクタ
```cpp
mint(ll x = 0)
```

## 基本的な演算
```cpp
mint a,b;
++a;
--a;
a++;
a--;
-a;
a + b;
a - b;
a * b;
a / b;

a += b;
a -= b;
a *= b;
a /= b;

a = b;
```

## pow
```cpp
mint(x).pow(ll n)
```
- x^n % mod を返す

## inv
```cpp
mint(x).inv()
```
- x の逆元(x*y % mod == 1となる y)を返す

## 出入力
### 入力
```cpp
mint x;
std::cin >> x;
```

### 出力
```cpp
mint x;
std::cout << x;
```
