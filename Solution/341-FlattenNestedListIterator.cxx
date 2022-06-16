#include <stack>
#include <vector>

using namespace std;

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; --i)
        {
            m_st.push(&(nestedList[i]));
        }
    }
    
    int next() {
        const NestedInteger *item = m_st.top();
        m_st.pop();
        
        return item->getInteger();
    }
    
    bool hasNext() {        
        ProcessTop();
        return !m_st.empty();
    }
    
private:
    void ProcessTop()
    {
        if (m_st.empty())
            return;
        
        const NestedInteger *item = m_st.top();

        if (item->isInteger())
            return;
        
        m_st.pop();
        const vector<NestedInteger> &list = item->getList();
        for (int i = list.size() - 1; i >= 0; --i)
        {
            m_st.push(&(list[i]));
        }
        
        ProcessTop();
    }
    
private:
    stack<const NestedInteger*> m_st;
};
