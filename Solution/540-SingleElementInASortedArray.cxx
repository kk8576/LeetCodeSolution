#include <vector>

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int size = nums.size();
        if (size == 1)
            return nums[0];
        
        int left = 0, right = size - 1;
        int mid;
        
        while (true)
        {   
            int half = (right - left) / 2;
            bool isOdd = half % 2 == 1;
            
            mid = left + half;
            
            if (nums[mid - 1] != nums[mid] && nums[mid + 1] != nums[mid])
                return nums[mid];
            
            if (nums[mid - 1] == nums[mid] && isOdd)
                left = mid + 1;
            else if (nums[mid + 1] == nums[mid] && isOdd)
                right = mid - 1;
            else if (nums[mid - 1] == nums[mid] && !isOdd)
                right = mid;
            else if (nums[mid + 1] == nums[mid] && !isOdd)
                left = mid;
            
            if (left == right)
                break;
        }
        
        return nums[left];
    }
};
