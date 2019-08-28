class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // if x is less than or equal the minimum element, then just return the first k elements
        if (x <= arr[0]) {
            auto start = arr.begin();
            auto end = arr.begin() + k;
            vector<int> result(start, end);
            return result;
        }
        // similarly, if x is greater than or equal the maximum element, then just return the last k elements
        else if (x > arr[arr.size() - 1]) {
            auto end = arr.end();
            auto start = arr.end() - k;
            vector<int> result(start, end);
            return result;
        }
        // 
        else {
            int left = 0, right = arr.size() - 1;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (arr[mid] >= x)
                    right = mid;
                else
                    left = mid + 1;
            }
            //cout << left << endl;
            int leftBoundry = max(left - k - 1, 0);
            int rightBoundry = min(left + k - 1, int(arr.size() - 1));
            while (rightBoundry - leftBoundry > k - 1) {
                if (x - arr[leftBoundry] <= arr[rightBoundry] - x)
                    rightBoundry--;
                else
                    leftBoundry++;
            }
            auto start = arr.begin() + leftBoundry;
            auto end = arr.begin() + leftBoundry + k;
            vector<int> result(start, end);
            return result;
        }
    }
};