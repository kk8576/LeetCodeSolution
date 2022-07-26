class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)
            return 0;
        
        vector<int> ones(32, 0);
        for (int i = 0; i < size; ++i)
        {
            int j = 0;
            int num = nums[i];
            while (num != 0)
            {
                bool flag = num & 1; 
                if (flag)
                {
                    ones[j]++;
                }
                
                num >>= 1;
                j++;
            }
        }
        
        int sum = 0;
        for (int i = 0; i < ones.size(); ++i)
        {
            sum += (size - ones[i]) * ones[i];
        }
        
        return sum;
    }
};
