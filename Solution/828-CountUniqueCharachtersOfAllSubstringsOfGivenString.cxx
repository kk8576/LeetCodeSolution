class Solution {
public:
    int uniqueLetterString(string s) {
        int sum = 0;
        
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < s.size(); i++)
        {
            int id = s[i] - 'A';
            pos[id].push_back(i);
        }
        
        for (auto it = pos.begin(); it != pos.end(); it++)
        {
            for (int j = 0; j < it->second.size(); ++j)
            {
                int left = j == 0 ? -1 : it->second[j - 1];
                int right = j == it->second.size() - 1 ? s.size() : it->second[j + 1];
                
                sum += (it->second[j] - left) * (right - it->second[j]);
            }
        }
        
        return sum;
    }
};
