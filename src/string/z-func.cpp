void z_func(char s[], int n, int z[]) {
  int l = 0, r = 0; z[0] = 0;
  for (int i=1; i<n; ++i) {
    z[i] = i < r ? min(z[i-l], r-i) : 0;
    while (i+z[i] < n && s[i+z[i]] == s[z[i]]) ++z[i];
    if (chkmx(r, i+z[i])) l = i;
  }
}
