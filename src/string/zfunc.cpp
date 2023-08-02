void z_func(char s[], int n, int z[]) {
  int mxr=0, pos=0; z[0] = 0;
  for (int i=1; i<n; ++i) {
    z[i] = i<=mxr ? min(z[i-pos], mxr-i+1) : 0;
    while (i+z[i]<n && s[z[i]]==s[i+z[i]]) ++z[i];
    if (chkmx(mxr, i+z[i]-1)) pos=i;
  }
}
