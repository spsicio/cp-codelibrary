int manacher_init(char in[], int n, char out[]) {
  int m = (n+1)<<1;
  out[0] = out[1] = '#'; out[m+1] = '@';
  for (int i=1; i<=n; ++i) out[i<<1] = in[i-1], out[i<<1|1] = '#';
  return m;
}
void manacher_work(char s[], int n, int p[]) {
  int mid = 0, r = 0; p[0] = 1;
  for (int i=1; i<n; ++i) {
    p[i] = i < r ? min(p[2*pos-i], r-i) : 1; 
    while (s[i-p[i]] == s[i+p[i]]) ++p[i];
    if (chkmx(r, i+p[i])) mid = i;
  }
}
