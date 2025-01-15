class Solution {
 public:
 //KNK
  int minimizeXor(unsigned num1, unsigned num2) {
    constexpr int kMaxBit = 30;
    int bits = popcount(num2);

    if (popcount(num1) == bits)
      return num1;
    int ans = 0;
    for (int i = kMaxBit; i >= 0; --i)
      if (num1 >> i & 1) {
        ans |= 1 << i;
        if (--bits == 0)
          return ans;
      }

    for (int i = 0; i < kMaxBit; ++i)
      if ((num1 >> i & 1) == 0) {
        ans |= 1 << i;
        if (--bits == 0)
          return ans;
      }

    return ans;
  }
};