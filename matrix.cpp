#include <bits/stdc++.h>
using namespace std;

template<class T> struct matrix{
  matrix(int n = 0, T m = numeric_limits<T>::max()) : n(n), Mod(m), a(n, vector<T>(n)){}
  vector<T> &operator[](const int &m){ return a[m]; }
  matrix &operator*=(const matrix &b){
    vector<vector<T>> c(n, vector<T>(n));
    rep(i, n) rep(j, b.n) rep(k, n){
      c[i][j] = (c[i][j] + a[i][k] * b.a[k][j]) % Mod;
    }
    a = c;
    return *this;
  }
  matrix &operator+=(const matrix &b){
    rep(i, n) rep(j, n){
      a[i][j] += b.a[i][j];
      if(a[i][j] >= Mod) a[i][j] -= Mod;
    }
    return *this;
  }
  matrix &operator-=(const matrix &b){
    rep(i, n) rep(j, n){
      a[i][j] -= b.a[i][j];
      if(a[i][j] <= -Mod) a[i][j] += Mod;
    }
    return *this;
  }
  matrix operator*(const matrix &b) const{ return matrix(*this) *= b; }
  matrix operator+(const matrix &b) const{ return matrix(*this) += b; }
  matrix operator-(const matrix &b) const{ return matrix(*this) -= b; }
  matrix pow(ll t) const{
    matrix<T> b(n, Mod), c = *this;
    rep(i, n) b[i][i] = 1;
    while(t > 0){
      if(t & 1) b *= c;
      c *= c;
      t /= 2;
    }
    return b;
  }
  int n;
  private:
  T Mod;
  vector<vector<T>> a;
};