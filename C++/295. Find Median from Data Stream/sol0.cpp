class MedianFinder {
private:
    vector<int> sortedData;
    
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (sortedData.empty()) {
            sortedData.push_back(num);
        }
        else {
            sortedData.insert(lower_bound(sortedData.begin(), sortedData.end(), num), num);
        }
    }
    
    double findMedian() {
        int n = sortedData.size();
        if (n % 2) {
            return sortedData[n / 2];
        }
        else {
            return (sortedData[n / 2] + sortedData[n / 2 - 1]) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */