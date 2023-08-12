struct rot_xor {
  int seed = 0x95abcfad;
  inline unsigned int operator()() {
    return seed = (seed << 1) ^ ((seed >> 31) & 0xa53a9be9);
  }
};
