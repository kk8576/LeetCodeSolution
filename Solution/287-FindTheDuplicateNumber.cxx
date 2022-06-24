class Solution {
public:
    //    1 3 4 2 2
    // => -1 3 4 2 2
    // => -1 -3 4 2 2
    // => -1 -3 4 -2 2
    // => -1 -3 -4 -2 2
    // => -1 -3 {-4} -2 2 ==> 2
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        int id = 0;
        while (true)
        {
            if (nums[id] < 0)
                return id;
            
            nums[id] = -nums[id];
            id = -nums[id];
        }
        
        for (int i = 0; i < n; ++i)
            nums[i] = abs(nums[i]);
        
        return -1;
    }
};
