/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        if (head == NULL)
            return 0;
        
        ListNode *slow, *fast;
        
        slow = head;
        fast = head->next;
        while (true)
        {
            if (fast->next == NULL)
                break;
            
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *secList = slow->next;
        slow->next = NULL;
        
        ListNode *next = secList->next;
        secList->next = NULL;
        while (next != NULL)
        {   
            ListNode *nextNext = next->next;
            next->next = secList;
            
            secList = next;
            next = nextNext;
        }
        
        ListNode *l1 = head, *l2 = secList;
        int maxV = 0;
        while (l1 != NULL && l2 != NULL)
        {
            int sum = l1->val + l2->val;
            maxV = maxV > sum ? maxV : sum;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        return maxV;
    }
};
