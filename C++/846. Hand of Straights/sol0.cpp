class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if (hand.size() % W) {
            return false;
        }
        
        map<int, int> numberOfCards;
        for (int card : hand) {
            numberOfCards[card]++;
        }
        
        while (!numberOfCards.empty()) {
            int firstCard = (*numberOfCards.begin()).first;
            for (int i = firstCard; i < firstCard + W; i++) {
                if (numberOfCards.count(i) == 0) {
                    return false;
                }
                numberOfCards[i]--;
                if (numberOfCards[i] == 0) {
                    numberOfCards.erase(i);
                }
            }
        }
            
        return true;
    }
};