/*You are given an array of n strings strs, all of the same length.

The strings can be arranged such that there is one on each line, making a grid. For example, strs = ["abc", "bce", "cae"] can be arranged as:

abc
bce
cae
You want to delete the columns that are not sorted lexicographically. In the above example (0-indexed),
 columns 0 ('a', 'b', 'c') and 2 ('c', 'e', 'e') are sorted while column 1
  ('b', 'c', 'a') is not, so you would delete column 1.
  */

class Solution {
 public:
  int minDeletionSize(vector<string>& A) {
    const int n = A[0].length();
    int ans = 0;

    for (int j = 0; j < n; ++j)
      for (int i = 0; i + 1 < A.size(); ++i)
        if (A[i][j] > A[i + 1][j]) {
          ++ans;
          break;
        }

    return ans;
  }
};