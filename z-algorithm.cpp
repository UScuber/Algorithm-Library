vector<int> z_algo(const string &s){
  int n = s.size();
  vector<int> z(n);
  z[0] = n;
  int i = 1, j = 0;
  while(i < n){
    while(i + j < n && s[j] == s[i + j]) j++;
    z[i] = j;
    if(!j){
      i++;
      continue;
    }
    int k = 1;
    while(k < j && z[k] + k < j) z[i + k++] = z[k];
    i += k;
    j -= k;
  }
  return z;
}