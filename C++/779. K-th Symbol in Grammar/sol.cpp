class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1) {
            return 0;
        }
        if (K % 2 == 0) {
            return (kthGrammar(N - 1, K / 2) == 0) ? 1 : 0;
        }
        else {
            return (kthGrammar(N - 1, (K + 1) / 2) == 0) ? 0 : 1;
        }
    }
};

/*
             0
         0       1
       0   1   1   0

      (a binary tree)
*/
//https://leetcode.com/explore/learn/card/recursion-i/253/conclusion/1675/discuss/113697/My-3-lines-C++-recursive-solution