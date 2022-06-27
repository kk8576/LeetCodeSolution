#include <vector>

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        
        if (m == 0)
            return false;
        
        int n = matrix[0].size();
        
        int left = 0, right = m * n - 1;
        int mid;
        int idx, idy;
        while (true)
        {
            mid = left + (right - left) / 2;
            
            idx = mid / n;
            idy = mid % n;
            
            if (matrix[idx][idy] == target)
                return true;
            
            if (matrix[idx][idy] > target)
                right = mid - 1;
            else
                left = mid + 1;
            
            if (left >= right)
                break;
        }
        
        right = right >= 0 ? right : 0;
        idx = right / n;
        idy = right % n;
        
        return matrix[idx][idy] == target;
    }
};
