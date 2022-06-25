class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        if (n == 0)
            return 0;
        
        // 'left' is not able to ship and 'right' is able to ship
        int left = weights[0], right = 0;
        for (int i = 0; i < n; ++i)
        {
            left = left > weights[i] ? left : weights[i];
            right += weights[i];
        }
        left--;
        
        int mid;
        while (true)
        {
            mid = (left + right) / 2;
            
            if (canShip(weights, mid, days))
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
    
    bool canShip(vector<int> &weights, int capacity, int maxDays)
    {
        int day = 0;
        int currCap = 0;
        for (int i = 0; i < weights.size(); ++i)
        {
            if (currCap + weights[i] > capacity)
            {
                currCap = weights[i];
                day++;
            }
            else
            {
                currCap += weights[i];
            }
            
            if (day >= maxDays)
                return false;
        }
        
        return true;
    }
};
