vector<int> manacher(const string &s){
  const int len = s.size();
  vector<int> r(len);
  int i = 0, j = 0;
  while(i < len){
    while(i-j >= 0 && i+j < len && s[i-j] == s[i+j]) j++;
    r[i] = j;
    int k = 1;
    while(i-k >= 0 && k+r[i-k] < j) r[i+k] = r[i-k], k++;
    i += k; j -= k;
  }
  return r;
}