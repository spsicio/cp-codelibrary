void duval(const char s[], int n, int pms[]) {
  int i = 0;
  while (i < n) {
    pms[i] = i;
    int j = i, k = i+1;
    while (k < n && s[j] <= s[k]) {
      if (s[j] < s[k]) {
        pms[k] = i;
        j = i, ++k;
      } else {
        pms[k] = pms[j] + (k - j);
        ++j, ++k;
      }
    }
    while (i <= j) {
      // handle [i, i + (k - j))
      i += k - j;
    }
  }
}
