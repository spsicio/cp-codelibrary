namespace LeftistHeap {
int val[MAX_N], dist[MAX_N];
int lc[MAX_N], rc[MAX_N];

void push_up(int x) {
  if (dist[lc[x]] < dist[rc[x]]) swap(lc[x], rc[x]);
  dist[x] = dist[rc[x]] + 1; 
}
int merge(int x, int y) {
  if (!x || !y) return x | y;
  if (val[x] > val[y]) swap(x, y);
  rc[x] = merge(rc[x], y);
  push_up(x); return x;
}
}  // namespace LeftistHeap
