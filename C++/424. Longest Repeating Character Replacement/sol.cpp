class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.length();
        int p1 = 0, p2 = 0, result = 0, maxCount = 0;
        vector<int> cnt(26, 0);
        while (p2 < len) {
            maxCount = max(maxCount, ++cnt[s[p2]-'A']);
            while (p2 - p1 + 1 - maxCount > k) {
                cnt[s[p1]-'A']--;
                p1++;
            }
            result = max(result, p2 - p1 + 1);
            p2++;
        }
        return result;
    }
};