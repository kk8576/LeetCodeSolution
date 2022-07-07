#include <vector>
#include <unordered_set>

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> rowSet;
        vector<unordered_set<int>> colSets(9), cubeSets(3);
        
        for (auto i = 0; i != board.size(); ++i)
        {
            for (auto j = 0; j != board[i].size(); ++j)
            {
                int num = getNumber(board[i][j]);
                if (num == 0)
                    continue;
                
                if (rowSet.find(num) != rowSet.end())
                {
                    return false;
                }
                else
                {
                    rowSet.insert(num);
                }
                
                if (colSets[j].find(num) != colSets[j].end())
                {
                    return false;
                }
                else
                {
                    colSets[j].insert(num);
                }
                
                if (cubeSets[j / 3].find(num) != cubeSets[j / 3].end())
                {
                    return false;
                }
                else
                {
                    cubeSets[j / 3].insert(num);
                }
            }
            
            rowSet.clear();
            
            if (i % 3 == 2)
            {
                for (int k = 0; k < 3; ++k)
                {
                    cubeSets[k].clear();
                }
            }
        }
        
        return true;
    }
    
    int getNumber(char &c)
    {
        int n = c - '0';
        if (n >= 1 && n <= 9)
            return n;
        
        return 0;
    }
};
