class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        if (size == 1)
            return 0;
        
        int left = 0, right = size - 1;
        int mid = (right + left) / 2;
        
        while (true)
        {
            if (left == right - 1)
            {
                if (nums[left] < nums[right])
                {
                    mid = right;
                    break;
                }
                else
                {
                    mid = left;
                    break;
                }
            }
            
            if (nums[mid] > nums[mid + 1])
            {
                right = mid;
                mid = (left + mid) / 2;
            }
            else if (nums[mid] < nums[mid + 1])
            {
                left = mid;
                mid = (mid + right) / 2;
            }
            
            if (mid == size - 1)
            {
                if (nums[mid] > nums[mid - 1])  
                    break;
            }
            else if (mid == 0)
            {
                if (nums[mid] > nums[mid + 1])
                    break;
            }
            else
            {
                if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
                {
                    break;
                }
            }
        }
    
        return mid;
    }
};
