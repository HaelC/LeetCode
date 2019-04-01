class Solution:
    def longestCommonPrefix(self, strs):
        pre = ''
        if not strs:                            # in case the list is empty
            return pre
        min_len = min([len(i) for i in strs])
        for i in range(min_len):
            temp_pre = strs[0][:i+1]
            for s in strs:
                if s[:i+1] != temp_pre:
                    return pre
            pre = temp_pre
        return pre