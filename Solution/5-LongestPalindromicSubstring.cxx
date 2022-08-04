class Solution {
public:
    string longestPalindrome(string s) {
        int start, end;
        int maxLen = 0;
        
        for (int i = 0; i < s.size(); ++i)
        {            
            findLongest(s, i, i, start, end, maxLen);
            findLongest(s, i, i+1, start, end, maxLen);
        }
        
        return string(s, start, end - start + 1);
    }
    
    void findLongest(string &s, int start0, int end0, int &start, int &end, int &maxLen)
    {
        int size = s.size();
        int len = 0;
        while (true)
        {
           if (start0 < 0 || end0 >= size)
               break;
            
            if (s[start0] == s[end0])
            {
                if (start0 == end0)
                    len++;
                else
                    len += 2;
                start0--;
                end0++;
            }
            else
                break;
        }
        
        if (maxLen < len)
        {
            start = start0 + 1;
            end = end0 - 1;
            maxLen = len;
        }
    }
};
