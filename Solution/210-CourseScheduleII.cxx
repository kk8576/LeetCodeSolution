#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> courseMap = buildGraph(prerequisites);
        stack<int> sequence;
        unordered_set<int> noCycle, processed;
       
        bool flag;
        for (int i = 0; i < numCourses; ++i)
        {
            flag = isCycle(i, courseMap, noCycle, processed, sequence);
            
            if (flag)
                break;
        }
        
        if (flag)
        {
            return vector<int>();
        }
        
        vector<int> ans;
        while (!sequence.empty())
        {
            ans.push_back(sequence.top());
            sequence.pop();
        }
        
        return ans;
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
    
    bool isCycle(int courseId, unordered_map<int, vector<int>> &courseMap, 
                 unordered_set<int> &noCycle, unordered_set<int> &processed, 
                 stack<int> &sequence)
    {
        // processed
        if (processed.find(courseId) != processed.end())
        {
            // not in a cycle
            if (noCycle.find(courseId) != noCycle.end())
            {
                return false;
            }
            // in a cycle
            else
            {
                return true;
            }
        }
        
        processed.insert(courseId);
        
        auto it = courseMap.find(courseId);
        if (it == courseMap.end())
        {
            sequence.push(courseId);
            noCycle.insert(courseId);
            return false;
        }
        
        bool flag;
        for (int i = 0; i < it->second.size(); ++i)
        {
            flag = isCycle(it->second[i], courseMap, noCycle, processed, sequence);
            
            if (flag)
                break;
        }
        
        if (!flag)
        {
            sequence.push(courseId);
            noCycle.insert(courseId);
        }
        
        return flag;
    }
};
