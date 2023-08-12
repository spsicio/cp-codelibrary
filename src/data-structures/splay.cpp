namespace Splay {
#define lc(x) (ch[(x)][0])
#define rc(x) (ch[(x)][1])
#define isrc(x) (rc(fa[(x)]) == (x))
int val[MAX_N], cnt[MAX_N], siz[MAX_N];
int fa[MAX_N], ch[MAX_N][2];
int indx, root;

int new_node(int v);
void push_up(int x);
void rotate(int x) {
  int y = fa[x], z = fa[y], k = isrc(x), w = ch[x][!k];
  if (y) { ch[z][isrc(y)] = x; } ch[x][!k] = y; ch[y][k] = w;
  if (w) { fa[w] = y; } fa[y] = x; fa[x] = z;
  push_up(y);
}
void splay(int x) {
  for (int y; y = fa[x], x; rotate(x))
    if (y) rotate(isrc(x)^isrc(y) ? x : y);
  push_up(x);
  root = x;
}

void upd_ins(int v) {
  if (!root) return root = new_node(v);
  int p = root;
  while (1) {
    if (val[p] == v) {
      ++cnt[p]; return splay(p);
    } else {
      int k = v > val[p];
      if (!ch[p][k]) {
        int q = new_node(v);
        ch[p][k] = q; fa[q] = p;
        return splay(q);
      } else p = ch[p][k];
    }
  }
}
int qry_find(int v);
int qry_pre(int x);
void upd_del(int v) {
  int p = qry_find(v);
  if (!p) return;
  if (cnt[p] > 1) --cnt[p], --siz[p];
  else if (!lc(p) && !rc(p)) root = 0;
  else if (!lc(p) || !rc(p)) fa[root = lc(p) | rc(p)] = 0;
  else {
    fa[lc(p)] = 0;
    qry_pre(p);
    fa[rc(root) = rc(p)] = root;
    push_up(root);
  }
}
#undef lc
#undef rc
#undef isrc
}  // namespace Splay
