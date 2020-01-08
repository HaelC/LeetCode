class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int remaining = candies, current = 1, index = 0;
        vector<int> distribution(num_people, 0);
        
        while (current <= remaining) {
            distribution[index] += current;
            remaining -=current;
            current++;
            index = (index + 1) % num_people;
        }
        distribution[index] += remaining;
        
        return distribution;
    }
};