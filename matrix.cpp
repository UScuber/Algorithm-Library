#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

template<class T> struct matrix {
  matrix(int n = 0) : n(n), a(n, vector<T>(n)){}
  vector<T> &operator[](const int &m){ return a[m]; }
  matrix &operator*=(const matrix &b){
    vector<vector<T>> c(n, vector<T>(n));
    rep(i, n) rep(j, b.n) rep(k, n){
      c[i][j] += a[i][k] * b.a[k][j];
    }
    a = c;
    return *this;
  }
  matrix &operator+=(const matrix &b){
    rep(i, n) rep(j, n)
      a[i][j] += b.a[i][j];
    return *this;
  }
  matrix &operator-=(const matrix &b){
    rep(i, n) rep(j, n)
      a[i][j] -= b.a[i][j];
    return *this;
  }
  matrix operator*(const matrix &b) const{ return matrix(*this) *= b; }
  matrix operator+(const matrix &b) const{ return matrix(*this) += b; }
  matrix operator-(const matrix &b) const{ return matrix(*this) -= b; }
  matrix pow(ll t) const{
    matrix<T> b(n), c = *this;
    rep(i, n) b[i][i] = 1;
    while(t > 0){
      if(t & 1) b *= c;
      c *= c;
      t /= 2;
    }
    return b;
  }
  T det() const{
    T res = 0;
    rep(i, n){
      T p = 1, m = 1;
      rep(j, n){
        p *= a[(i+j) % n][j];
        m *= a[(j+j) % n][n-j-1];
      }
      res += p - m;
    }
    return res;
  }
  matrix inv(){
    if(!det()) return matrix();
    matrix b(n), c = *this;
    rep(i, n) b[i][i] = 1;
    rep(i, n){
      T v = c[i][i];
      rep(j, n) b[j][i] /= v, c[j][i] /= v;
      rep(j, n){
        if(i == j) continue;
        T v = c[j][i];
        rep(k, n){
          c[j][k] -= c[i][k] * v;
          b[j][k] -= b[i][k] * v;
        }
      }
    }
    return b;
  }
  void debug(){
    rep(i, n){
      rep(j, n) cerr << a[i][j] << " ";
      cerr << "\n";
    }
  }
  int n;
  private:
  vector<vector<T>> a;
};