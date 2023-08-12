void dsu(int u) {
  for (auto &v: e[u]) if (v != fa[u] && v != hson[u]) {
    dsu(v);
    for (int i=dfn[v]; i<=rdfn[v]; ++i) del(dfn[i]);
  }
  if (hson[u]) dfs(hson[u]);
  for (auto &v: e[u]) if (v != fa[u] && v != hson[u]) {
    for (int i=dfn[v]; i<=rdfn[v]; ++i) add(dfn[i]);
  }
}
