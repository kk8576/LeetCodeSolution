class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        if (n == 0)
            return 0;
        
        // left: fail; right: pass
        int right = piles[0], left = 0;
        for (int i = 1; i < n; ++i)
        {
            right = right > piles[i] ? right : piles[i];
        }
        
        int mid;
        while (true)
        {
            mid = (left + right) / 2;
            
            if (can(piles, h, mid))
            {
                right = mid;
            }
            else
                left = mid;
            
            if (left >= right - 1)
                break;
        }
        
        return right;
    }
    
    bool can(vector<int> &piles, int h, int speed)
    {
        int curr = 0;
        for (int i = 0; i < piles.size(); ++i)
        {
            int h0 = piles[i] / speed;
            if (h0 * speed != piles[i])
                h0++;
            
            curr += h0;
            
            if (curr > h)
                return false;
        }
        
        return true;
    }
};
