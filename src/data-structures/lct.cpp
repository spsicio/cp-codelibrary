namespace LCT {
#define lc(x) (ch[(x)][0])
#define rc(x) (ch[(x)][1])
#define isrc(x) (rc(fa[(x)]) == (x))
#define nroot(x) (lc(fa[(x)]) == (x) || rc(fa[(x)]) == (x))
int fa[MAX_N], ch[MAX_N][2];
bool rev_tag[MAX_N];

void push_rev(int x);
void push_dn(int x);
void push_up(int x);
void rotate(int x) {
  int y = fa[x], z = fa[y], k = isrc(x), w = ch[x][!k];
  if (nroot(y)) { ch[z][isrc(y)] = x; } ch[x][!k] = y; ch[y][k] = w;
  if (w) { fa[w] = y; } fa[y] = x; fa[x] = z;
  push_up(y);
}
void splay(int x) {
  static int stk[MAX_N], top;
  for (int y = stk[top = 1] = x; nroot(y); stk[++top] = (y = fa[y]));
  while (top) push_dn(stk[top--]);
  for (int y; y = fa[x], nroot(x); rotate(x))
    if (nroot(y)) rotate(isrc(x)^isrc(y) ? x : y);
  push_up(x);
}

int access(int x) {
  int y = 0;
  for(; x; x = fa[y=x]) splay(x), rc(x) = y, push_up(x);
  return y;
}
void evert(int x) { push_rev(access(x)); }
int split(int x,int y) { evert(x); return access(y); }
int find(int x) {
  for (x = access(x); lc(x); x = lc(x)) push_dn(x);
  return splay(x), x;
}
void link(int x,int y) { evert(x), splay(x); fa[x] = y; }
void cut(int x,int y) { split(x,y), splay(x); rc(x) = fa[y] = 0; push_up(x); }
bool chk_link(int x,int y) { evert(x); return find(y) != x ? fa[x] = y : 0; }
bool chk_cut(int x,int y){
  evert(x);
  if (find(y)!=x || fa[y]!=x || ch[y][0]) return 0;	
  rc(x) = fa[y]=0; push_up(x); return 1;
}
#undef lc
#undef rc
#undef isrc
#undef nroot
}  // namespace LCT
