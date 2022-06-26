// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        
        if (isBadVersion(left))
            return 1;
        
        int mid;
        while (true)
        {
            // use this to instead of (left + right) / 2 in order to prevent integer overflow
            mid = left + (right - left) / 2;
            
            if (isBadVersion(mid))
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
            
            if (left >= right - 1)
                break;
        }
        
        return right;
    }
};
