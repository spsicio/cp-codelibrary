namespace SAM {
int len[MAX_2N], ch[MAX_2N][26], fail[MAX_2N];
int cnt[MAX_2N];
int indx, last;

int new_node(int l) {
  len[indx] = l; cnt[indx] = 1;
  memset(ch[indx], -1, sizeof(ch[indx])); return indx++;
}
int copy_node(int q, int l) {
  len[indx] = l; cnt[indx] = 0; fail[indx] = fail[q];
  memcpy(ch[indx], ch[q], sizeof(ch[q])); return indx++;
}
void init() {
  indx = 0; new_node(0);
  fail[0] = -1; last = 0;
}
void insert(int w) {
  int cur = new_node(len[last] + 1);
  int p = last;
  for (; ~p && ch[p][w] == -1; p = fail[p]) ch[p][w] = cur;
  if (p == -1) {
    fail[cur] = 0;
  } else if (int q = ch[p][w]; len[q] == len[p] + 1) {
    fail[cur] = q;
  } else {
    int r = copy_node(q, len[p] + 1);
    for (; ~p && ch[p][w] == q; p = fail[p]) ch[p][w] = r;
    fail[cur] = fail[q] = r;
  }
  last = cur;
}
}  // namespace SAM
