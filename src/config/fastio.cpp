struct FastIS {
  static const int LEN = 1<<21|1;
  char buf[LEN], *l, *r, c, *t; bool neof, neg;
  FastIS() : l(buf), r(buf), neof(1) {}
  inline operator bool() { return neof; }
  inline char gc() {
    return
      !neof || (l==r && (r = (l=buf) + fread(buf, 1, LEN, stdin), l==r)) ?
      neof=0, -1 : *l++;
  }
  FastIS& operator>>(char &c) {
    for (c=gc(); isspace(c); c=gc()) {} return *this;
  }
  FastIS& operator>>(char *s) {
    for (c=gc(); isspace(c); c=gc()) {}
    for (t=s; ~c and !isspace(c); c=gc()) *t++=c;
    *t='\0'; return *this;
  }
  template<typename T> FastIS& operator>>(T &x) {
    for (c=gc(); ~c and !isdigit(c); c=gc()) neg ^= c == '-';
    for (x=0; isdigit(c); c=gc()) x = 10*x+c-'0';
    if (neg) { x=-x, neg=0; } return *this;
  }
} fast_in;

struct FastOS {
  static const int LEN=1<<21|1, W=21;
  char buf[LEN], *l, *r, *t, stk[W]; int top;
  FastOS() : l(buf), r(buf+LEN) {}
  inline void flush() { fwrite(buf, 1, l-buf, stdout); l=buf; }
  FastOS& operator<<(char c) { *l++=c; if (l==r) flush(); return *this; }
  FastOS& operator<<(char *s) { 
    for (t=s; *t!='\0'; ++t) { *this<<*t; } return *this;
  }
  FastOS& operator<<(const char *s) { return *this<<(char*)s; }
  template<typename T> FastOS& operator<<(T x) {
    if (!x) *this<<'0'; else if (x<0) *this<<'-', x=-x;
    for (top=0; x; x/=10) stk[++top] = x%10+'0';
    while (top) { *this<<stk[top--]; } return *this;
  }
  ~FastOS() { flush(); }
} fast_out;
