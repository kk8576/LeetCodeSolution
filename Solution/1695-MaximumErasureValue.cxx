class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)
            return 0;
        
        int maxSum = 0, sum = 0;
        int front = 0;
        unordered_set<int> numsInSub;
        
        for (int i = 0; i < size; ++i)
        {
            if (numsInSub.find(nums[i]) != numsInSub.end())
            {
                maxSum = maxSum > sum ? maxSum : sum;
                
                while (front != i)
                {
                    numsInSub.erase(nums[front]);
                    sum -= nums[front];
                    front++;
                    
                    if (nums[front - 1] == nums[i])
                    {
                        break;
                    }
                }
            }  
            
            numsInSub.insert(nums[i]);
            sum += nums[i];
        }
        maxSum = maxSum > sum ? maxSum : sum;

        return maxSum;
    }
};
