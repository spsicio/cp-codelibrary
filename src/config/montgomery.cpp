using u64 = unsigned long long;
using u32 = unsigned int;
using i64 = long long;

struct u128 {
  u64 h, l;
  static u128 mul(const u64 &x, const u64 &y) {
    u32 xh = x>>32, yh = y>>32, xl = x, yl = y;
    u64 hh = static_cast<u64>(xh) * yh, ll = static_cast<u64>(xl) * yl;
    u64 hl = static_cast<u64>(xh) * yl, lh = static_cast<u64>(xl) * yh;
    u64 c = (hl<<32>>32) + (lh<<32>>32) + (ll>>32);
    u64 h = hh + (hl>>32) + (lh>>32) + (c>>32);
    u64 l = (hl<<32) + (lh<<32) + ll;
    return {h, l};
  }
};

struct Montgomery {
  u64 mod, inv, r2;
  u64 reduce(u128 x) {
    u64 q = x.l * inv;                 // q === x / n  (mod r)
    i64 a = x.h - u128::mul(q, mod).h; // x - qn === 0 (mod r)
    return a<0 ? a+=mod : a;
  }
  u64 mul(u64 x, u64 y) { return reduce(u128::mul(x, y)); }
  Montgomery(u64 mod) : mod(mod), inv(1), r2(-mod % mod) {
    // 2 ^ (2 ^ 6)     = 2 ^ 64
    for (int i=0; i<6; ++i) inv *= 2 - mod * inv;
    // 2 ^ (4 * 2 ^ 4) = 2 ^ 64
    for (int i=0; i<4; ++i) if ((r2 <<= 1) >= mod) r2 -= mod;
    for (int i=0; i<4; ++i) r2 = mul(r2, r2);
  }
  inline u64 init(u64 x) { return mul(x, r2); }
  inline u64 reduce(u64 x) { return reduce({0, x}); }
};
