class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<char, int>> q;
        if (a > 0) q.push(pair<int, char>(a, 'a'));
        if (b > 0) q.push(pair<int, char>(b, 'b'));
        if (c > 0) q.push(pair<int, char>(c, 'c'));
        
        string ans;
        while (!q.empty())
        {
            auto v = q.top();
            q.pop();
            char ch = v.second;
            
            int size = ans.size();
            if (size < 2 || (ans[size - 1] != ch || ans[size - 2] != ch))
            {
                ans += ch;
                v.first--;
                if (v.first > 0)
                {
                    q.push(v);
                }
            }
            else
            {
                if (q.empty())
                    break;
                else
                {
                    auto v2 = q.top();
                    q.pop();
                    ans += v2.second;
                    v2.first--;
                    if (v2.first > 0)
                        q.push(v2);
                    q.push(v);
                }
            }
        }
        
        return ans;
    }
};
