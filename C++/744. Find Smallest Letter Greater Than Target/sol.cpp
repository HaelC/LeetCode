class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int size = letters.size();
        if (target < letters[0] || target >= letters[size - 1])
            return letters[0];
        else {
            int left = 0, right = size - 1;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (letters[mid] <= target)
                    left = mid + 1;
                else
                    right = mid;
            }
            return letters[left];
        }
    }
};