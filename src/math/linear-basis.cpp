template<int w> struct LinearBasis {
  bitset<w> base[w]; int dim;
  LinearBasis() : dim(0) { for (int i=0; i<w; ++i) base[i].reset(); }
  int insert(bitset<w> x) {
    for (int i=w-1; i>=0; --i) if (x[i]) {
      if (base[i][i]) {
        x ^= base[i];
      } else {
        // qry_kth requires this:
        for (int j=i-1; j>=0; --j) if (x[j] && base[j][j]) x ^= base[j];
        for (int j=i+1; j<w; ++j) if (base[j][i]) base[j] ^= x;
        base[i] = x;
        ++dim; return i;
      }
    }
    return -1;
  }
  bitset<w> qry_kth(bitset<w> k) {
    bitset<w> res;
    for (int i=0; i<w; ++i) if (base[i][i]) {
      if (k[0]) res ^= base[i];
      k >>= 1;
    } return res;
  }
  bitset<w> qry_rnk(bitset<w> x, bool &eq) {
    int df = dim;
    bitset<w> res, cur;
    for (int i=w-1; i>=0; --i) {
      if (base[i][i]) --df;
      if (x[i] && (!cur[i] || base[i][i])) res.set(df);
      if (x[i] != cur[i]) {
        if (base[i][i]) cur ^= base[i];
        else break;
      }
    }
    eq = cur == x;
    return res;
  }
};
