#include <bits/stdc++.h>
#include "bitvector.hpp"
using namespace std;

//----- Wavelet Matrix -----

template <class T, int maxlog>
struct WaveletMatrix {
  int len;
  BitVector matrix[maxlog];
  int mid[maxlog];
	WaveletMatrix(){}
  WaveletMatrix(vector<T> v) : len(v.size()){
    vector<T> l(len), r(len);
		fill(matrix, matrix + maxlog, BitVector(len + 1));
    for(int level = maxlog - 1; level >= 0; level--){
      int left = 0, right = 0;
      for(int i = 0; i < len; i++){
        if(v[i] >> level & 1){
          matrix[level].set(i);
          r[right++] = v[i];
        }else{
          l[left++] = v[i];
        }
      }
      mid[level] = left;
      matrix[level].build();
      v.swap(l);
      copy(r.begin(), r.begin() + right, v.begin() + left);
    }
  }
  inline int succ(const int f, const int l, const int level) const{
    return matrix[level].rank(f, l) + mid[level] * f;
  }
  //find v[k]
  T access(int k) const{
    assert(0 <= k && k < len);
    T res = 0;
    for(int level = maxlog - 1; level >= 0; level--){
      const bool f = matrix[level][k];
      if(f) res |= T(1) << level;
      k = matrix[level].rank(f, k) + mid[level]*f;
    }
    return res;
  }
  T operator[](const int k) const{ return access(k); }
  // count i  (0 <= i < r) && v[i] == x
  int rank(const T x, int r) const{
    assert(0 <= r && r <= len);
    int l = 0;
    for(int level = maxlog - 1; level >= 0; level--){
      l = succ(x >> level & 1, l, level);
      r = succ(x >> level & 1, r, level);
    }
    return r - l;
  }
  //k-th value v[l,r)
  T kth_smallest(int l, int r, int k) const{
    assert(0 <= l && l <= r && r <= len);
    assert(0 <= k && k < r - l);
    T res = 0;
    for(int level = maxlog - 1; level >= 0; level--){
      int cnt = matrix[level].rank(0, r) - matrix[level].rank(0, l);
      bool f = cnt <= k;
      if(f){
        res |= T(1) << level;
        k -= cnt;
      }
      l = succ(f, l, level);
      r = succ(f, r, level);
    }
    return res;
  }
  T kth_largest(int l, int r, int k) const{
    return kth_smallest(l, r, r-l-k-1);
  }
  // count i  (l <= i < r), (v[i] < upper)
  int range_freq(int l, int r, const T upper) const{
    int res = 0;
    for(int level = maxlog - 1; level >= 0; level--){
      bool f = upper >> level & 1;
      if(f) res += matrix[level].rank(0, r) - matrix[level].rank(0, l);
      l = succ(f, l, level);
      r = succ(f, r, level);
    }
    return res;
  }
  // count i  (l <= i < r), (lower <= v[i] < upper)
  int range_freq(int l, int r, const T lower, const T upper) const{
    assert(0 <= l && l <= r && r <= len);
    return range_freq(l, r, upper) - range_freq(l, r, lower);
  }
  // max v[i]  (l <= i < r), (v[i] < upper)
  T prev_value(int l, int r, const T upper) const{
    assert(0 <= l && l <= r && r <= len);
    int cnt = range_freq(l, r, upper);
    return cnt == 0 ? -1 : kth_smallest(l, r, cnt - 1);
  }
  // min v[i]  (l <= i < r), (lower <= v[i])
  T next_value(int l, int r, const T lower) const{
    assert(0 <= l && l <= r && r <= len);
    int cnt = range_freq(l, r, lower);
    return cnt == r - l ? -1 : kth_smallest(l, r, cnt);
  }
};


//----- Compressed Wavelet Matrix -----

template <class T, int maxlog>
struct CompWaveletMatrix {
	WaveletMatrix<T, maxlog> mat;
	vector<T> d;
	CompWaveletMatrix(const vector<T> &v) : d(v){
		sort(d.begin(), d.end());
		d.erase(unique(d.begin(), d.end()), d.end());
		vector<int> t(v.size());
		for(int i = 0; i < v.size(); i++) t[i] = get_pos(v[i]);
		mat = WaveletMatrix<int, maxlog>(move(t));
	}
	inline int get_pos(const T x) const{
		return lower_bound(d.begin(), d.end(), x) - d.begin();
	}
	T access(const int k) const{ return d[mat.access(k)]; }
  T operator[](const int k) const{ return access(k); }
  int rank(const T x, const int r) const{
    int pos = get_pos(x);
    if(pos == d.size() || d[pos] != x) return 0;
    return mat.rank(pos, r);
  }
  T kth_smallest(const int l, const int r, const int k) const{
    return d[mat.kth_smallest(l, r, k)];
  }
  T kth_largest(const int l, const int r, const int k) const{
    return d[mat.kth_largest(l, r, k)];
  }
  int range_freq(int l, int r, T upper) const{
    return mat.range_freq(l, r, get_pos(upper));
  }
  int range_freq(int l, int r, T lower, T upper) const{
    return mat.range_freq(l, r, get_pos(lower), get_pos(upper));
  }
  T prev_value(int l, int r, T upper) const{
    auto ret = mat.prev_value(l, r, get_pos(upper));
    return ret == -1 ? -1 : d[ret];
  }
  T next_value(int l, int r, T lower) const{
    auto ret = mat.next_value(l, r, get_pos(lower));
    return ret == -1 ? -1 : d[ret];
  }
};