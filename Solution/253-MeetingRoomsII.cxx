#include <vector>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if (size == 0)
            return 0;
        
        vector<int> start, end;
        for (int i = 0; i < size; ++i)
        {
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int count = 0, max = 0, lastStart = -1;
        int i = 0, j = 0;
        while (true)
        {
            if (end[j] <= start[i])
            {
                j++;
                count--;
            }
            else
            {
                i++;
                count++;
                max = max > count ? max : count;
            }
            
            if (i == size)
                break;
        }
        
        return max;
    }
};
