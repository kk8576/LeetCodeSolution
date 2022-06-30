#include <vector>

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int size = nums.size();
        int left = -1, right = size - 1;
        int sum = 0;
        int minOp = size + 1;
        
        for (int i = right; i > left; --i)
        {
            if (sum + nums[i] == x)
            {
                sum += nums[i];
                right = i;
                minOp = size - right + left + 1;
                break;
            }
            else if (sum + nums[i] < x)
            {
                sum += nums[i];
                right = i;
            }
            else
            {
                right = i + 1;
                break;
            }
        }
        
        while (true)
        {
            left++;
            
            if (left == right)
                break;
            
            sum += nums[left];
            
            if (sum < x)
                continue;
            else if (sum == x)
            {
                int minOp0 = size - right + left + 1;
                minOp = minOp < minOp0 ? minOp : minOp0;
                continue;
            }
            
            for (int i = right; i < size; ++i)
            {
                if (sum - nums[i] == x)
                {
                    right = i + 1;
                    int minOp0 = size - right + left + 1;
                    minOp = minOp < minOp0 ? minOp : minOp0;
                    sum -= nums[i];
                    break;
                }
                else if (sum - nums[i] > x)
                {
                    sum -= nums[i];
                    right = i;
                }
                else
                {
                    sum -= nums[i];
                    right = i + 1;
                    break;
                }
            }
        }
        
        if (minOp < size + 1)
            return minOp;
        
        return -1;
    }
};
