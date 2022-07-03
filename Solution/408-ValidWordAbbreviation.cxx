#include <string>

using namespace std;

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int wordIdx = 0, wordSize = word.size();
        int abbrIdx = 0, abbrSize = abbr.size();
        
        int sum = 0;
        for (int i = 0; i < abbrSize; ++i)
        {
            char c = abbr[i];
            
            // if it is a number
            int num = c - '0';
            if (num >= 0 && num <= 9)
            {
                if (sum == 0 && num == 0)
                    return false;
                
                sum = sum * 10 + num;
                continue;
            }
            else
            {
                // if previous char is a number
                if (sum != 0)
                {
                    wordIdx += sum;
                    sum = 0;
                }
                
                if (wordIdx >= wordSize)
                {
                    return false;
                }
                // compar c and word[wordIdx]
                else if (c == word[wordIdx])
                {
                    wordIdx++;
                }
                else
                {
                    return false;
                }
            }
        }
        
        wordIdx += sum;
        if (wordIdx != wordSize)
            return false;

        return true;
    }
    
};
