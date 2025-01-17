class Solution {
 public:
 //KNK
  bool doesValidArrayExist(vector<int>& derived) {
    return accumulate(derived.begin(), derived.end(), 0, bit_xor<>()) == 0;
  }
};