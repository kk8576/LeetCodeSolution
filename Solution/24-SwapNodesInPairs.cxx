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
    ListNode* swapPairs(ListNode* head) {
        ListNode *newHead = NULL;
        ListNode *first = head;
        if (first == NULL)
            return newHead;
        
        ListNode *second = first->next;
        if (second == NULL)
        {
            newHead = head;
            return newHead;
        }
        
        ListNode *pre = NULL;
        
        while (first != NULL && second != NULL)
        {
            if (newHead == NULL)
                newHead = second;
            
            first->next = second->next;
            second->next = first;
            
            if (pre != NULL)
                pre->next = second;
            
            pre = first;
            
            first = first->next;
            
            second = first == NULL ? NULL : first->next;
        }
        
        return newHead;
    }
};
