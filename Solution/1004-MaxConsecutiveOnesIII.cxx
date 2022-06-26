class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int numZero = 0;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 1)
            {
                // move right
                if (numZero <= k)
                {
                    right++;
                }
                // move both left and right
                else // numZeros >= k
                {
                    numZero -= 1 - nums[left];
                    left++;
                    right++;
                }
            }
            else // nums[i] == 0
            {
                // increase zero and move right
                if (numZero < k)
                {
                    numZero++;
                    right++;
                }
                else // numZero >= k
                {
                    numZero -= 1 - nums[left];
                    left++;
                    right++;
                    numZero++;
                }
            }
        }
        
        return right - left;
    }
};
