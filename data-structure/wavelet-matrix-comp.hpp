#include "wavelet-matrix.hpp"

//----- Compressed Wavelet Matrix -----

template <class T, int maxlog, bool USE_SUM = false>
struct WaveletMatrixComp {
  int len;
  BitVector matrix[maxlog];
  int mid[maxlog];
  vector<T> sum[maxlog];
  vector<T> d;
  WaveletMatrixComp(){}
  WaveletMatrixComp(const vector<T> &data) : len(data.size()), d(data){
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    vector<int> v(len);
    for(int i = 0; i < len; i++) v[i] = get_pos(data[i]);
    vector<int> l(len), r(len);
		fill(matrix, matrix + maxlog, BitVector(len + 1));
    if(USE_SUM) fill(sum, sum + maxlog, vector<T>(len + 1));
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
      if(USE_SUM){
        sum[level][0] = 0;
        for(int i = 0; i < len; i++){
          sum[level][i + 1] = sum[level][i] + d[v[i]];
        }
      }
    }
  }
  inline int get_pos(const T x) const{
		return lower_bound(d.begin(), d.end(), x) - d.begin();
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
    return d[res];
  }
  T operator[](const int k) const{ return access(k); }
  // count i  (0 <= i < r) && v[i] == x
  int rank(const T x, int r) const{
    assert(0 <= r && r <= len);
    const int pos = get_pos(x);
    if(pos >= (int)d.size() || d[pos] != x) return 0;
    int l = 0;
    for(int level = maxlog - 1; level >= 0; level--){
      l = succ(pos >> level & 1, l, level);
      r = succ(pos >> level & 1, r, level);
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
    return d[res];
  }
  T kth_largest(int l, int r, int k) const{
    return kth_smallest(l, r, r-l-k-1);
  }
  // sum of [0,k)th smallest elements([l, r))
  T kth_smallest_sum(int l, int r, int k) const{
    assert(0 <= l && l <= r && r <= len);
    assert(0 <= k && k <= r - l);
    assert(USE_SUM);
    T res = 0;
    for(int level = maxlog - 1; level >= 0; level--){
      const int l0 = matrix[level].rank(0, l);
      const int r0 = matrix[level].rank(0, r);
      if(k < r0 - l0){
        l = l0, r = r0;
      }else{
        k -= r0 - l0;
        res += sum[level][r0] - sum[level][l0];
        l += mid[level] - l0;
        r += mid[level] - r0;
      }
    }
    if(k) res += sum[0][l + k] - sum[0][l];
    return res;
  }
  // sum of [0,k)th largest elements([l, r))
  T kth_largest_sum(int l, int r, int k) const{
    assert(0 <= l && l <= r && r <= len);
    assert(0 <= k && k <= r - l);
    assert(USE_SUM);
    return  kth_smallest_sum(l, r, r - l) - kth_smallest_sum(l, r, r - l - k);
  }
  // count i  (l <= i < r), (v[i] < upper)
  int range_freq(int l, int r, const T upper) const{
    const int pos = get_pos(upper);
    int res = 0;
    for(int level = maxlog - 1; level >= 0; level--){
      bool f = pos >> level & 1;
      if(f) res += matrix[level].rank(0, r) - matrix[level].rank(0, l);
      l = succ(f, l, level);
      r = succ(f, r, level);
    }
    return d[res];
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