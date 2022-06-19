#include <vector>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int sizeI = grid.size();
        
        if (sizeI == 0)
            return maxArea;
        
        int sizeJ = grid[0].size();
        for (int i = 0; i < sizeI; ++i)
        {
            for (int j = 0; j < sizeJ; ++j)
            {
                int area = search(grid, i, j);
                
                maxArea = maxArea > area ? maxArea : area;
            }
        }
        
        return maxArea;
    }
    
    // return the area
    int search(vector<vector<int>> &grid, int i, int j)
    {
        if (grid[i][j] == 0)
            return 0;
        
        int area = 1;
        grid[i][j] = 0;
        
        if (i > 0)
            area += search(grid, i - 1, j);
        
        if (j > 0)
            area += search(grid, i, j - 1);
        
        if (i < grid.size() - 1)
            area += search(grid, i + 1, j);
        
        if (j < grid[i].size() - 1)
            area += search(grid, i, j + 1);
        
        return area;
    }
};
