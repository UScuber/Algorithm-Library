#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

inline ull modmul(ull a, ull b, ull m) noexcept{
	ll ret = a * b - m * ull(1.L / m * a * b);
	return ret + m * (ret < 0) - m * (ret >= (ll)m);
}
inline ull modpow(ull b, ull e, ull m) noexcept{
	ull ans = 1;
	for(; e; b = modmul(b, b, m), e >>= 1)
		if(e & 1) ans = modmul(ans, b, m);
	return ans;
}
bool is_prime(const ull n){
	if(n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	static constexpr ull A[] = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 };
	const ull s = __builtin_ctzll(n - 1), d = n >> s;
	for(ull a : A){   // ^ count trailing zeroes
		ull p = modpow(a % n, d, n), i = s;
		while(p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if(p != n - 1 && i != s) return false;
	}
	return true;
}