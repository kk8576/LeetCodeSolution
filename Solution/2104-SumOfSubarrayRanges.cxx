class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long max = sumMaxOrMin(nums, [](int a1, int a2) {return a1 > a2;});
        long long min = sumMaxOrMin(nums, [](int a1, int a2) {return a1 < a2;});
        
        return max - min;
    }
    
    long long sumMaxOrMin(vector<int>& nums, bool (*comp)(int, int))
    {
        stack<int> st;
        int size = nums.size();
        vector<int> left(size, -1), right(size, size);
        
        for (int i = 0; i < size; ++i)
        {
            if (st.empty() || comp(nums[st.top()], nums[i]))
            {
                left[i] = i - 1;
            }
            else
            {
                while (true)
                {
                    int id = st.top();
                    right[id] = i;
                    st.pop();
                    
                    if (st.empty() || comp(nums[st.top()], nums[i]))
                        break;
                }
                
                if (!st.empty())
                {
                    left[i] = st.top();
                }
            }
            
            st.push(i);
        }
        
        long long sum = 0;
        for (int i = 0; i < size; ++i)
        {
            sum += (long long)(i - left[i]) * (right[i] - i) * nums[i];
        }
        
        return sum;
    }
};
