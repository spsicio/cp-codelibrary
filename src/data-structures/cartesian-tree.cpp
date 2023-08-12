static int stk[MAX_N];
int top = 0;
for (int i=1; i<=n; ++i) {
  int x = i, y = 0;
  while (top && h[i] < h[stk[top]]) y = stk[top--];
  lc[x] = y;
  rc[stk[top]] = x;
  stk[++top] = x;
}
return rc[0];
