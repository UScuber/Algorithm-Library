inline unsigned int randxor32() noexcept{
  static unsigned int y = 2463534242;
  y = y ^ (y << 13); y = y ^ (y >> 17);
  return y = y ^ (y << 5);
}
// returns random [l, r)
inline int rnd(const int l, const int r) noexcept{
  return randxor32() % (r - l) + l;
}

unsigned long long randxor64(){
  static unsigned long long x = 88172645463325252ULL;
  x = x ^ (x << 7);
  return x = x ^ (x >> 9);
}
// returns random [l, r)
inline long long rnd(const ll l, const ll r) noexcept{
  return randxor64() % (r - l) + l;
}