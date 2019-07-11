class Solution:
    def reverseWords(self, s: str) -> str:
        l = s.split()
        l = [i[::-1] for i in l]
        return ' '.join(l)