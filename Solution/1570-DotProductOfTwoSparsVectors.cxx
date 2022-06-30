#include <vector>
#include <pair>

using namespace std;

class SparseVector {
public:
    
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
                Data.push_back(pair<int, int>(i, nums[i]));
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int nz1 = Data.size(), nz2 = vec.Data.size();
        int i = 0, j = 0;
        int id1, id2;
        int sum = 0;
        while (i != nz1 && j != nz2)
        {
            id1 = Data[i].first;
            id2 = vec.Data[j].first;
            
            if (id1 == id2)
            {
                sum += Data[i].second * vec.Data[j].second;
                i++;
                j++;
            }
            else if (id1 < id2)
            {
                i++;
            }
            else
                j++;
        }
        
        return sum;
    }
    
    vector<pair<int, int>> Data;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
