#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        
        bool asc = true;
        int pos = 0;
        for (int i = nums.size() - 1; i > 0; --i)
        {
            if (nums[i] > nums[i - 1])
            {
                pos = i;
                break;
            }
            else if (nums[i] == nums[i - 1])
                continue;
            else
            {
                asc = false;
            }
        }
        
        if (asc)
        {
            if (pos > 0)
            {
                int tmp = nums[pos];
                nums[pos] = nums[pos - 1];
                nums[pos - 1] = tmp;
            }
        }
        else
        {
            if (pos > 0)
            {
                int minPos = nums.size() - 1;
                while (true)
                {
                    if (minPos == pos - 1)
                        break;
                    
                    if (nums[minPos] > nums[pos - 1])
                    {
                        int tmp = nums[minPos];
                        nums[minPos] = nums[pos - 1];
                        nums[pos - 1] = tmp;
                        break;
                    }
                    
                    minPos--;
                }
            }
            sort(nums.begin() + pos, nums.end());

        }
    }
};
