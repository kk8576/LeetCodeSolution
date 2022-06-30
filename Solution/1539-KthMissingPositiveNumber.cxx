#include <vector>

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> missingNum;
        int size = arr.size();
        for (int i = 0; i < size; ++i)
        {
            missingNum.push_back(arr[i] - i - 1);
        }
        
        if (k > missingNum[size - 1])
            return arr[size - 1] + k - missingNum[size - 1];
        else if (k <= missingNum[0])
            return k;
        
        // k <= right && k > left
        int left = 0, right = arr.size() - 1;
        int mid;
        while (true)
        {
            mid = left + (right - left) / 2;
            if (missingNum[mid] >= k)
                right = mid;
            else
                left = mid;
            
            if (left >= right - 1)
                break;
        }
        
        return arr[left] + k - missingNum[left];
    }
};
