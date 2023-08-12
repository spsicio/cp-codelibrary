namespace FHQTreap {
int rnd[MAX_N], val[MAX_N];
int siz[MAX_N], fa[MAX_N];
int lc[MAX_N], rc[MAX_N];
int indx, root;

int new_node(int v);
void push_up(int p);
void split(int p, int k, int &x, int &y) {
  if (!p) { x = 0; y = 0; }
  if (int t = siz[p] - siz[rc[p]]; t <= k) {
    x = p; split(rc[x], k-t, rc[x], y);
    fa[rc[x]] = x;
  } else {
    y = p; split(lc[y], k, x, lc[y]);
    fa[lc[y]] = y;
  } push_up(p);
}
int merge(int x, int y) {
  if (!x || !y) return x | y;
  if (rnd[x] < rnd[y]) {
    rc[x] = merge(rc[x], y);
    push_up(x); return fa[rc[x]] = x;
  } else {
    lc[y] = merge(x, lc[y]);
    push_up(y); return fa[lc[y]] = y;
  }
}
}  // namespace FHQTreap
