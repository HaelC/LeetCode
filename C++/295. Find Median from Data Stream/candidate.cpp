class MedianFinder {
private:
    vector<int> data;
    
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        data.push_back(num);
    }
    
    double findMedian() {
        sort(data.begin(), data.end());
        int n = data.size();
        if (n % 2) {
            return data[n / 2];
        }
        else {
            return (data[n / 2] + data[n / 2 - 1]) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */