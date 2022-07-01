class Solution {
public:
    bool validPalindrome(string s)
    {
        return validPalindrome(s, 0, s.size() - 1, false);
    }
    
    bool validPalindrome(string s, int st, int e, bool deleted) {
        int left, right = e;
        int halfSize = st + (e - st + 1) / 2;
        
        for (left = st; left <= halfSize; ++left)
        {
            if (s[left] == s[right])
            {
                right--;
            }
            else
            {
                if (deleted)
                    return false;
                
                
                
                bool succ;
                succ = validPalindrome(s, left + 1, right, true);
                
                if (succ)
                    return true;
                
                succ = validPalindrome(s, left, right - 1, true);
                
                if (succ)
                    return true;
                
                return false;
            }
        }
        
        return true;
    }
};
