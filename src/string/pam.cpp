namespace PAM {
  int len[MAX_N], ch[MAX_N][26], fail[MAX_N];
  int diff[MAX_N], slink[MAX_N];
  int trans[MAX_N];
  int indx, last;
  char s[MAX_N];
  
  int new_node(int l) {
    ++indx; len[indx] = l; memset(ch[indx], 0, sizeof(ch[indx]));
    return indx;
  }
  void init() {
    indx = -1; new_node(0); new_node(-1);
    s[0] = '#'; fail[0] = 1; diff[0] = 0; last = 0;
  }
  int getfail(int p, int i) {
    while (s[i-len[p]-1] != s[i]) p = fail[p];
    return p;
  }
  void insert(int i) {
    int p = getfail(last, i);
    if (!ch[p][s[i]-'a']) {
      int q = new_node(len[p]+2);
      fail[q] = ch[getfail(fail[p], i)][s[i]-'a'];
      diff[q] = len[q]-len[fail[q]];
      slink[q] = (diff[q]==diff[fail[q]] ? slink[fail[q]] : fail[q]);
      if (len[q] <= 2) {
        trans[q] = fail[q];
      } else {
        int r = trans[p];
        while (s[i-len[r]-1] != s[i] || (len[r]+2)*2 > len[q]) r = fail[r];
        trans[q] = ch[r][s[i]-'a'];
      }
      ch[p][s[i]-'a'] = q;
    }
    last = ch[p][s[i]-'a'];
  }
}
