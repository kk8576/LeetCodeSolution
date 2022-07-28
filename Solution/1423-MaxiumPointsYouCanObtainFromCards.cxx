class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxSum = 0, sum = 0, size = cardPoints.size();
        for (int i = size - k; i < size; ++i)
        {
            sum += cardPoints[i];
        }
        maxSum = sum;
        
        for (int i = 0; i < k; ++i)
        {
            sum -= cardPoints[size - k + i];
            sum += cardPoints[i];
            
            maxSum = maxSum > sum ? maxSum : sum;
        }
        
        return maxSum;
    }
};
