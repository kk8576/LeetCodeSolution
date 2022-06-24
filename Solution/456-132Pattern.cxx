class Solution {
public:
    //   nums:   6 12 3 4 6 11 20
    //   mins:   6 6  3 3 3 3  3
    //
    //   stack
    //   loop the array from back to front:
    //      if num == min
    //        continue
    //
    //      if stack.empty:
    //        stack.push(num)
    //      else
    //        if stack.top > num
    //          push(num)
    //        else if stack.top == num
    //          continue
    //        else
    //          while !stack.empty
    //            if stack.top > min
    //              return true
    //            else
    //              stack.pop
    //   return false
    bool find132pattern(vector<int>& nums) {
        int size = nums.size();
        if (size < 3)
            return false;
        
        vector<int> min(size);
        min[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] >= min[i - 1])
            {
                min[i] = min[i - 1];
            }
            else
            {
                min[i] = nums[i];
            }
        }
        
        stack<int> st;
        
        for (int i = size - 1; i >= 0; --i)
        {
            if (nums[i] == min[i])
                continue;
            else
            {
                if (st.empty())
                    st.push(nums[i]);
                else
                {
                    if (st.top() > nums[i])
                        st.push(nums[i]);
                    else if (st.top() == nums[i])
                        continue;
                    else 
                    {
                        while (!st.empty())
                        {
                            if (st.top() > min[i])
                                return true;
                            else
                                st.pop();
                        }
                    }
                }
            }
        }
        
        return false;
    }
};
