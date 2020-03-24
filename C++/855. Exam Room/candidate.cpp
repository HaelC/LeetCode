class ExamRoom {
private:
    vector<bool> seats;
    int n;
    
public:
    ExamRoom(int N) {
        n = N;
        seats = vector<bool>(n, false);
    }
    
    int seat() {
        int left = -1, right = -1, leftMaxDist = -1, rightMaxDist = -1, maxDist = 0;
        for (int i = 0; i < n; i++) {
            if (seats[i]) {
                if (left == -1) {
                    left = i;
                    maxDist = i;
                }
                else if (right == -1) {
                    right = i;
                    // leftMaxDist = left;
                    // rightMaxDist = right;
                    if ((right - left) / 2 > maxDist) {
                        rightMaxDist = right;
                        leftMaxDist = left;
                        maxDist = (right - left) / 2;
                    }
                }
                else {
                    left = right;
                    right = i;
                    if ((right - left) / 2 > maxDist) {
                        rightMaxDist = right;
                        leftMaxDist = left;
                        maxDist = (right - left) / 2;
                    }
                }
            }
            else if (maxDist == 0) {
                maxDist = 1;
                rightMaxDist = i;
                leftMaxDist = i;
            }
        }
        int index = -1;
        if (left == -1) {
            index = 0;
        }
        else if (right == -1) {
            index = left >= (n + 1) / 2 ? 0 : n - 1;
        }
        else {
            index = (rightMaxDist + leftMaxDist) / 2;
        }
        seats[index] = true;
        return index;
    }
    
    void leave(int p) {
        seats[p] = false;
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */