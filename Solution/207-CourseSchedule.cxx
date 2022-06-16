#include <vector>
#include <set>
#include <unordered_map>

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> courseMap = buildGraph(prerequisites);
        
        set<int> checked;
        set<int> noCycle;
        
        for (int i = 0; i < numCourses; ++i)
        {
            if (isCycle(i, courseMap, checked, noCycle))
                return false;
        }
        
        return true;
    }
    
    unordered_map<int, vector<int>> buildGraph(vector<vector<int>> &prereqs)
    {
        unordered_map<int, vector<int>> courseMap;
        
        for (int i = 0; i < prereqs.size(); ++i)
        {
            courseMap[prereqs[i][1]].push_back(prereqs[i][0]);
        }
        
        return courseMap;
    }
    
    bool isCycle(int courseId, unordered_map<int, vector<int>> &courseMap, set<int> &checked, set<int> &noCycle)
    {
        auto it = courseMap.find(courseId);
        
        if (it == courseMap.end())
        {
            return false;
        }
        
        if (checked.find(courseId) != checked.end())
        {
            if (noCycle.find(courseId) == noCycle.end())
                return true;
            else
                return false;
        }
        
        checked.insert(courseId);
        
        bool flag;
        for (int i = 0; i < it->second.size(); ++i)
        {
            flag = isCycle(it->second[i], courseMap, checked, noCycle);
            if (flag)
                return true;
        }
        
        noCycle.insert(courseId);
        
        return false;
    }
};
