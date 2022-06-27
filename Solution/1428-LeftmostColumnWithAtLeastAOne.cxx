/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

#include <vector>

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        
        int idx = 0, idy = dim[1] - 1;
        
        while (true)
        {
            if (binaryMatrix.get(idx, idy) == 1)
            {
                idy--;
            }
            else
            {
                idx++;
            }
            
            if (idy == -1)
                break;
            
            if (idx == dim[0])
                break;
        }
        
        if (idy + 1 == dim[1])
            return -1;
        
        return idy + 1;
    }
};
